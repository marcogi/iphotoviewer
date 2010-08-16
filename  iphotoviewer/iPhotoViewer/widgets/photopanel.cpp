#include "photopanel.h"

PhotoPanel::PhotoPanel(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
}

PhotoPanel::~PhotoPanel()
{

}

/**
 * Sets a list of photos or rolls as the model.
 */
void PhotoPanel::setModel(BaseList *list,int size,int mode)
{
	// persist the size of a thumb in the PhotoPanel.
	this->size=size;

	int panelWidth=this->width();
	int labelsPerRow = floor((float)(panelWidth-SPACING)/(float)(size+SPACING));

	int rows = ceil((float)list->rowCount() / (float)labelsPerRow);

	// clean up the layout...
	if(this->layout()!=0)
	{
		QLayoutItem *child;
		while ((child = this->layout()->takeAt(0)) != 0)
		{
			delete child->widget();
			delete child;
		}
		delete this->layout();
	}

	QGridLayout *gridLayout=new QGridLayout(this);
	gridLayout->setSpacing(SPACING);

	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<labelsPerRow;col++)
		{
			if(row*labelsPerRow+col+1<=list->rowCount())
			{
				PhotoFrame *photoFrame=new PhotoFrame();
				QModelIndex index=list->index(row*labelsPerRow+col,0,QModelIndex());

				if(mode==MODE_PHOTO)
				{
					Photo *photo=(Photo*)list->get(index);
					photoFrame->setPhoto(photo,this->size);
				}
				else
				{
					Roll *roll=(Roll*)list->get(index);
					photoFrame->setRoll(roll,this->size);
				}

				gridLayout->addWidget(photoFrame,row,col);
				QApplication::processEvents();
			}
		}
	}
}

/**
 * Invoked when the main window is being resized. Reorders the contained
 * PhotoFrames.
 */
void PhotoPanel::resizeEvent (QResizeEvent* /*event*/)
{
	int panelWidth=this->parentWidget()->parentWidget()->width();
	int labelsPerRow = floor((float)(panelWidth-SPACING)/(float)(this->size+SPACING));

	if(this->layout()!=0)
	{
		QLayoutItem *child;
		QList<QLayoutItem*> list;
		while ((child=this->layout()->takeAt(0))!=0)
		{
			list.append(child);
		}
		delete this->layout();
		QGridLayout *gridLayout=new QGridLayout(this);
		gridLayout->setSpacing(SPACING);

		int rows = ceil((float)list.count()/(float)labelsPerRow);

		// now we resize each photoframe the panel contains and move it to
		// its new position in the panel...
		for(int row=0;row<rows;row++)
		{
			for(int col=0;col<labelsPerRow;col++)
			{
				if(row*labelsPerRow+col+1<=list.count())
				{
					QLayoutItem *item=list.at(row*labelsPerRow+col);
					PhotoFrame *photoFrame=(PhotoFrame*)item->widget();
					photoFrame->resize(this->size);
					gridLayout->addItem(item,row,col);
				}
			}
		}
	}
}

/**
 * Invoked when resizing the main window.
 */
void PhotoPanel::resize(int size)
{
	this->size=size;
	this->resizeEvent(0);
}
