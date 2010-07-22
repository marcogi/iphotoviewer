#include "photopanel.h"

PhotoPanel::PhotoPanel(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
}

PhotoPanel::~PhotoPanel()
{

}

void PhotoPanel::setModel(BaseList *list,int width)
{
	int panelWidth=this->width();
	int labelsPerRow = panelWidth/width;

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

	QGridLayout *grid=new QGridLayout(this);
	//grid->set
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<labelsPerRow;j++)
		{
			if(i*labelsPerRow+j+1<=list->rowCount())
			{
				QLabel *lb=new QLabel();
				QModelIndex idx=list->index(i*labelsPerRow+j,0,QModelIndex());
				Photo *p=(Photo*)list->get(idx);
				QPixmap *pm=new QPixmap(p->getThumbPath());

				lb->setPixmap(pm->scaled(width,width));
				//lb->setFixedWidth(width);
				//lb->setGeometry(j*(width+10),i*(width+10),width,width);

				grid->addWidget(lb,i,j);

				//vbox->addWidget(lb,1,0);

			}
			else
			{
				QLabel *lb2=new QLabel("");
				grid->addWidget(lb2,i,j);
			}
		}
	}

	//grid->activate();
}
