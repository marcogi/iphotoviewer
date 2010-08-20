#include "iphotoviewer.h"

using namespace std;

iPhotoViewer::iPhotoViewer(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	// connect the rolls button to the appropriate click event...
	connect(ui.btnRolls, SIGNAL(pressed()), this, SLOT(btnRollsPressed()));
	connect(ui.zoomSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));

	// initialize the content area...
	photoPanel=new PhotoPanel(ui.scrollArea);
	ui.scrollArea->setWidget(photoPanel);

	// initialize the zoom-slider...
	ui.zoomSlider->setRange(MIN_SLIDER,MAX_SLIDER);
	ui.zoomSlider->setValue(75);
	ui.zoomSlider->setSingleStep(1);

	// load the iPhoto database...
	loadIPhotoDB();
}

iPhotoViewer::~iPhotoViewer()
{

}

void iPhotoViewer::sliderValueChanged(int value)
{
	photoPanel->resize(value*BASE_SIZE);
}

void iPhotoViewer::lstAlbumSelectionChanged()
{
	BaseList *albumList=(BaseList*)ui.lstAlbums->model();
	Album *album=(Album*)albumList->get(ui.lstAlbums->currentIndex());
	BaseList *list=album->getList();

	for(int i=0;i<ui.contentLayout->count();i++)
	{
		QWidget *widget=ui.contentLayout->itemAt(i)->widget();
		if(widget->objectName()=="PhotoViewerClass")
		{
			PhotoViewer *photoViewer=(PhotoViewer*)widget;
			photoViewer->goBack();
		}
	}

	photoPanel->setModel(list,ui.zoomSlider->value()*BASE_SIZE,MODE_PHOTO);
}

void iPhotoViewer::btnRollsPressed()
{
	for(int i=0;i<ui.contentLayout->count();i++)
	{
		// we close all photoViewers...
		QWidget *widget=ui.contentLayout->itemAt(i)->widget();
		if(widget->objectName()=="PhotoViewerClass")
		{
			PhotoViewer *photoViewer=(PhotoViewer*)widget;
			photoViewer->goBack();
		}
	}
	photoPanel->setModel(this->lstRolls,ui.zoomSlider->value()*BASE_SIZE,MODE_ROLL);
}

void iPhotoViewer::loadIPhotoDB()
{
	//ui.lstPhotos->addItem("Item");
	//IPhotoPhotos *ipp=new IPhotoPhotos();
	QString originalPath;
	QString libraryPath=Config::getLibraryPath(); //"/home/david/Dropbox/iPhoto Library";

	QDomDocument doc( "AdBookML" );
	QFile file( libraryPath + "/AlbumData.xml");
	if( !file.open( QIODevice::ReadOnly ) ){
		QMessageBox::information( 0, "Info", "IOReadonly" );
		return ;}
	if( !doc.setContent( &file ) )
	{
		file.close();
		QMessageBox::information( 0, "Info", "setContent" );
		return ;
	}
	file.close();

	BaseList *listOfPhotos=new BaseList();
	BaseList *listOfAlbums=new BaseList();
	BaseList *listOfRolls=new BaseList();
	QDomElement pathRoot = doc.documentElement();

	if(pathRoot.tagName() == "plist")
	{
		QDomNode pathNode = pathRoot.firstChild();
		if(pathNode.toElement().tagName() == "dict")
		{
			QDomNode innerNode2 = pathNode.firstChild();

			while(!innerNode2.isNull())
			{
				if(innerNode2.toElement().tagName()=="key" && innerNode2.toElement().text()=="Archive Path")
				{
					innerNode2 = innerNode2.nextSibling();
					originalPath = innerNode2.toElement().text();
					cout << "Original Path: " << originalPath.toStdString() << endl;
					break;
				}

				innerNode2 = innerNode2.nextSibling();
			}


		}
	}

	QDomElement root = doc.documentElement();

	if(root.tagName() == "plist")
	{
		QDomNode node = root.firstChild();
		if(node.toElement().tagName() == "dict")
		{
			QDomNode innerNode = node.firstChild();

			while(!innerNode.isNull())
			{
				if(innerNode.toElement().tagName()=="key" && innerNode.toElement().text()=="Master Image List")
				{
					innerNode = innerNode.nextSibling();
					QDomNode imgNode = innerNode.firstChild();

					while(!imgNode.isNull())
					{
						Photo *photo=new Photo();//=new IPhotoPhotos();

						int id=imgNode.toElement().text().toInt();
						photo->setId(id);
						//cout << id << endl;

						imgNode = imgNode.nextSibling();
						QDomNode img2Node = imgNode.firstChild();

						while(!img2Node.isNull())
						{
							//cout << img2Node.toElement().tagName().toStdString() << "---" << img2Node.toElement().text().toStdString() << endl;

							if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="ThumbPath")
							{
								img2Node = img2Node.nextSibling();
								QString path = img2Node.toElement().text();
								//QMessageBox::information( 0, "Info", "ID "+id+" Path "+path);
								path=path.replace(originalPath,libraryPath);
								//ui.lstPhotos->addItem(path);
								photo->setThumbPath(path);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="ImagePath")
							{
								img2Node = img2Node.nextSibling();
								QString path = img2Node.toElement().text();
								path=path.replace(originalPath,libraryPath);
								photo->setImagePath(path);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="MediaType")
							{
								img2Node = img2Node.nextSibling();
								QString mediaType = img2Node.toElement().text();
								photo->setMediaType(mediaType);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Caption")
							{
								img2Node = img2Node.nextSibling();
								QString caption = img2Node.toElement().text();
								photo->setCaption(caption);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Comment")
							{
								img2Node = img2Node.nextSibling();
								QString comment = img2Node.toElement().text();
								photo->setComment(comment);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Roll")
							{
								img2Node = img2Node.nextSibling();
								int roll = img2Node.toElement().text().toInt();
								photo->setRoll(roll);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Rating")
							{
								img2Node = img2Node.nextSibling();
								int rating = img2Node.toElement().text().toInt();
								photo->setRating(rating);
							}

							img2Node = img2Node.nextSibling();
						}

						listOfPhotos->append(photo);

						imgNode = imgNode.nextSibling();
					}
				}

				innerNode = innerNode.nextSibling();
			}
		}
	}

	QDomElement albumRoot = doc.documentElement();

	if(albumRoot.tagName() == "plist")
	{
		QDomNode node = albumRoot.firstChild();
		if(node.toElement().tagName() == "dict")
		{
			QDomNode innerNode = node.firstChild();

			while(!innerNode.isNull())
			{
				if(innerNode.toElement().tagName()=="key" && innerNode.toElement().text()=="List of Albums")
				{
					innerNode = innerNode.nextSibling();
					QDomNode imgNode = innerNode.firstChild();

					while(!imgNode.isNull())
					{
						Album *album = new Album();//=new IPhotoPhotos();

						//int id=imgNode.toElement().text().toInt();
						//photo.setId(id);
						//cout << id << endl;

						imgNode = imgNode.nextSibling();
						QDomNode img2Node = imgNode.firstChild();
						//img2Node = img2Node.firstChild();

						while(!img2Node.isNull())
						{
							//cout << img2Node.toElement().tagName().toStdString() << "---" << img2Node.toElement().text().toStdString() << endl;

							if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="AlbumId")
							{
								img2Node = img2Node.nextSibling();
								int id = img2Node.toElement().text().toInt();

								album->setId(id);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="AlbumName")
							{
								img2Node = img2Node.nextSibling();
								QString albumName = img2Node.toElement().text();

								album->setAlbumName(albumName);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="KeyList")
							{
								img2Node = img2Node.nextSibling();
								QDomNode img3Node=img2Node.firstChild();
								//BaseList *albumList=new BaseList();

								while(!img3Node.isNull())
								{
									int photoKey=img3Node.toElement().text().toInt();
									Photo *p=(Photo*)listOfPhotos->get(photoKey);
									album->getList()->append(p);
									img3Node=img3Node.nextSibling();
								}

								//album->setList(albumList);
							}

							img2Node = img2Node.nextSibling();
						}

						listOfAlbums->append(album);

						imgNode = imgNode.nextSibling();
					}
				}

				innerNode = innerNode.nextSibling();
			}
		}
	}

	QDomElement rollRoot = doc.documentElement();

	if(rollRoot.tagName() == "plist")
	{
		QDomNode node = rollRoot.firstChild();
		if(node.toElement().tagName() == "dict")
		{
			QDomNode innerNode = node.firstChild();

			while(!innerNode.isNull())
			{
				if(innerNode.toElement().tagName()=="key" && innerNode.toElement().text()=="List of Rolls")
				{
					innerNode = innerNode.nextSibling();
					QDomNode imgNode = innerNode.firstChild();

					while(!imgNode.isNull())
					{
						Roll *roll = new Roll();//=new IPhotoPhotos();

						//int id=imgNode.toElement().text().toInt();
						//photo.setId(id);
						//cout << id << endl;

						imgNode = imgNode.nextSibling();
						QDomNode img2Node = imgNode.firstChild();
						//img2Node = img2Node.firstChild();

						while(!img2Node.isNull())
						{
							//cout << img2Node.toElement().tagName().toStdString() << "---" << img2Node.toElement().text().toStdString() << endl;

							if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="RollId")
							{
								img2Node = img2Node.nextSibling();
								int id = img2Node.toElement().text().toInt();

								roll->setId(id);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="RollName")
							{
								img2Node = img2Node.nextSibling();
								QString rollName = img2Node.toElement().text();

								roll->setRollName(rollName);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="KeyPhotoKey")
							{
								img2Node = img2Node.nextSibling();
								int keyPhotoKey = img2Node.toElement().text().toInt();

								Photo *p=(Photo*)listOfPhotos->get(keyPhotoKey);

								roll->setKeyPhoto(p);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="KeyList")
							{
								img2Node = img2Node.nextSibling();
								QDomNode img3Node=img2Node.firstChild();
								//BaseList *albumList=new BaseList();

								while(!img3Node.isNull())
								{
									int photoKey=img3Node.toElement().text().toInt();
									Photo *p=(Photo*)listOfPhotos->get(photoKey);
									roll->getPhotos()->append(p);
									img3Node=img3Node.nextSibling();
								}

								//album->setList(albumList);
							}

							img2Node = img2Node.nextSibling();
						}

						listOfRolls->append(roll);

						imgNode = imgNode.nextSibling();
					}
				}

				innerNode = innerNode.nextSibling();
			}
		}
	}

	ui.lstAlbums->setModel(listOfAlbums);
	this->lstRolls=listOfRolls;
	connect(ui.lstAlbums->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(lstAlbumSelectionChanged()));
}

