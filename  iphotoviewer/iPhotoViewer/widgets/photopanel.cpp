#include "photopanel.h"

PhotoPanel::PhotoPanel(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	this->count=0;
}

PhotoPanel::~PhotoPanel()
{

}

void PhotoPanel::resize(int value)
{
	this->thumbWidth=value;
	this->resizeEvent(0);
}

void PhotoPanel::setModel(BaseList *list,int thumbWidth)
{
	this->thumbWidth=thumbWidth;
	int panelWidth=this->width();
	int labelsPerRow = floor(panelWidth/(thumbWidth+10));

	int rows = ceil((float)list->rowCount() / (float)labelsPerRow);

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

	this->grid=new QGridLayout(this);
	grid->setSpacing(5);

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<labelsPerRow;j++)
		{
			if(i*labelsPerRow+j+1<=list->rowCount())
			{
				PhotoFrame *pf=new PhotoFrame();
				QModelIndex idx=list->index(i*labelsPerRow+j,0,QModelIndex());
				Photo *p=(Photo*)list->get(idx);
				pf->setPhoto(p,thumbWidth);
				this->grid->addWidget(pf,i,j);
			}
		}
	}
}

void PhotoPanel::resizeEvent (QResizeEvent *event)
{
	//event->setAccepted(true);
	//qDebug() << "Resize event" << this->count++;
	int panelWidth=this->parentWidget()->parentWidget()->width();
	int labelsPerRow = floor(panelWidth/(this->thumbWidth+10));

	if(this->layout()!=0)
	{
		//qDebug() << "old: " << this->grid->columnCount() << " new: " << labelsPerRow;
		//if(this->grid->columnCount()!=labelsPerRow)
		{
			QLayoutItem *child;
			QList<QLayoutItem*> list;
			while ((child = this->layout()->takeAt(0)) != 0)
			{
				list.append(child);
				//delete child->widget();
				//delete child;
			}
			delete this->layout();
			this->grid=new QGridLayout(this);
			this->grid->setSpacing(5);


			int rows = ceil((float)list.count() / (float)labelsPerRow);

			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<labelsPerRow;j++)
				{
					if(i*labelsPerRow+j+1<=list.count())
					{
						QLayoutItem *item=list.at(i*labelsPerRow+j);
						PhotoFrame *pf=(PhotoFrame*)item->widget();
						pf->resize(this->thumbWidth);
						this->grid->addItem(item,i,j);
					}
				}
			}
		}
	}
}
