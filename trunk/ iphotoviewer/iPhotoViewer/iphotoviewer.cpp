#include "iphotoviewer.h"

using namespace std;

iPhotoViewer::iPhotoViewer(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(pushButtonPressed()));
	connect(ui.lstPhotos, SIGNAL(itemSelectionChanged()), this, SLOT(lstSelectionChanged()));
}

iPhotoViewer::~iPhotoViewer()
{

}

void iPhotoViewer::lstSelectionChanged()
{
	//QMessageBox::information( 0, "Info",ui.lstPhotos->currentItem()->text());
	//QPixmap *image = new QPixmap(ui.lstPhotos->currentItem()->text());
	ui.label->setPixmap(QPixmap(ui.lstPhotos->currentItem()->text()));
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
						QString id=imgNode.toElement().text();
						//cout << id.toStdString() << endl;

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
								ui.lstPhotos->addItem(path);
							}

							img2Node = img2Node.nextSibling();
						}

						imgNode = imgNode.nextSibling();
					}
				}

				innerNode = innerNode.nextSibling();
			}
		}
	}

}
