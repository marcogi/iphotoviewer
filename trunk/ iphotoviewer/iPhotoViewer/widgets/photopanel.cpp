#include "photopanel.h"

PhotoPanel::PhotoPanel(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	this->isLoading=false;
	this->cancel=false;
	this->navBar=new NavigationBar();
	QVBoxLayout *vLayout = new QVBoxLayout(ui.navigationWidget);
	vLayout->setMargin(0);
	vLayout->addWidget(this->navBar);
	this->navBar->show();
}

PhotoPanel::~PhotoPanel()
{

}

void PhotoPanel::onLoadingCompleted()
{
	disconnect(this,SIGNAL(loadingCompleted()),this,SLOT(onLoadingCompleted()));
	this->setModel(this->list,this->size,this->mode);
}

/**
 * Sets a list of photos or rolls as the model.
 */
void PhotoPanel::setModel(BaseList *list,int size,int mode)
{
	this->mutex.lock();
	// if the panel is already loading another view...
	if(this->isLoading)
	{
		// we request a cancelation...
		this->cancel=true;
		// persist the parameters...
		this->list=list;
		this->size=size;
		this->mode=mode;
		// and wait for the loadingCompleted signal, emited, when
		// the cancelation took place...
		connect(this,SIGNAL(loadingCompleted()),this,SLOT(onLoadingCompleted()));
		this->mutex.unlock();
		return;
	}
	this->mutex.unlock();

	this->isLoading=true;
	// persist the size of a thumb in the PhotoPanel.
	this->size=size;

	int panelWidth=this->width();
	int labelsPerRow = floor((float)(panelWidth-SPACING)/(float)(size+SPACING));

	int rows = ceil((float)list->rowCount() / (float)labelsPerRow);

	// clean up the layout...
	if(ui.contentWidget->layout()!=0)
	{
		QLayoutItem *child;
		while ((child = ui.contentWidget->layout()->takeAt(0)) != 0)
		{
			delete child->widget();
			delete child;
		}
		delete ui.contentWidget->layout();
	}

	if(mode==MODE_ROLL)
	{
		ui.navigationWidget->setMinimumHeight(0);
		ui.navigationWidget->setMaximumHeight(0);
	}
	else if(mode==MODE_PHOTO)
	{
		ui.navigationWidget->setMinimumHeight(27);
		ui.navigationWidget->setMaximumHeight(27);
	}

	QGridLayout *gridLayout=new QGridLayout();
	ui.contentWidget->setLayout(gridLayout);
	gridLayout->setObjectName("contentGridLayout");
	gridLayout->setSpacing(SPACING);

	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<labelsPerRow;col++)
		{
			if(row*labelsPerRow+col+1<=list->rowCount())
			{
				// if a cancelation was requested we stop here...
				if(this->cancel)
					break;

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

	this->cancel=false;
	this->isLoading=false;
	emit loadingCompleted();
}

/**
 * Invoked when the main window is being resized. Reorders the contained
 * PhotoFrames.
 */
void PhotoPanel::resizeEvent (QResizeEvent* /*event*/)
{
	int panelWidth=this->parentWidget()->parentWidget()->width();
	int labelsPerRow = floor((float)(panelWidth-SPACING)/(float)(this->size+SPACING));

	if(ui.contentWidget->layout()!=0)
	{
		QLayoutItem *child;
		QList<QLayoutItem*> list;
		while ((child=ui.contentWidget->layout()->takeAt(0))!=0)
		{
			list.append(child);
		}
		delete ui.contentWidget->layout();
		QGridLayout *gridLayout=new QGridLayout(ui.contentWidget);
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
