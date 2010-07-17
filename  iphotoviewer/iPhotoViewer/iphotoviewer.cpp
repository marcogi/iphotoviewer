#include "iphotoviewer.h"

using namespace std;

iPhotoViewer::iPhotoViewer(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(pushButtonPressed()));
}

iPhotoViewer::~iPhotoViewer()
{

}

void iPhotoViewer::lstSelectionChanged()
{
	PhotoModel *l=(PhotoModel*)ui.lstPhotos->model();
	Photo p=l->get(ui.lstPhotos->currentIndex());
	ui.label->setPixmap(QPixmap(p.getThumbPath()));
}

void iPhotoViewer::pushButtonPressed()
{
	//ui.lstPhotos->addItem("Item");
	//IPhotoPhotos *ipp=new IPhotoPhotos();
	QString originalPath;
	QString libraryPath="/home/david/Dropbox/iPhoto Library";
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

	PhotoModel *listOfPhotos=new PhotoModel();
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
						Photo photo;//=new IPhotoPhotos();

						int id=imgNode.toElement().text().toInt();
						photo.setId(id);
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
								photo.setThumbPath(path);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="ImagePath")
							{
								img2Node = img2Node.nextSibling();
								QString path = img2Node.toElement().text();
								path=path.replace(originalPath,libraryPath);
								photo.setImagePath(path);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="MediaType")
							{
								img2Node = img2Node.nextSibling();
								QString mediaType = img2Node.toElement().text();
								photo.setMediaType(mediaType);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Caption")
							{
								img2Node = img2Node.nextSibling();
								QString caption = img2Node.toElement().text();
								photo.setCaption(caption);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Comment")
							{
								img2Node = img2Node.nextSibling();
								QString comment = img2Node.toElement().text();
								photo.setComment(comment);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Roll")
							{
								img2Node = img2Node.nextSibling();
								int roll = img2Node.toElement().text().toInt();
								photo.setRoll(roll);
							}
							else if(img2Node.toElement().tagName()=="key" && img2Node.toElement().text()=="Rating")
							{
								img2Node = img2Node.nextSibling();
								int rating = img2Node.toElement().text().toInt();
								photo.setRating(rating);
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


	ui.lstPhotos->setModel(listOfPhotos);
	connect(ui.lstPhotos->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(lstSelectionChanged()));
}
