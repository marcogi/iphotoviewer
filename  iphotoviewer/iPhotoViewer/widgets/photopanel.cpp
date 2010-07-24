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
	//this->setGeometry(0,0,this->parentWidget()->width(),this->parentWidget()->height());


	int labelsPerRow = floor(panelWidth/(width+10));

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
				//QLabel *lb=new QLabel();
				PhotoFrame *pf=new PhotoFrame();
				QModelIndex idx=list->index(i*labelsPerRow+j,0,QModelIndex());
				Photo *p=(Photo*)list->get(idx);
				pf->setPhoto(p,width);
				/*QPixmap *pm=new QPixmap(p->getThumbPath());

				int w=pm->width();
				int h=pm->height();

				if(w>h)
				{
					h=h*width/w;
					w=width;
				}
				else
				{
					w=w*width/h;
					h=width;
				}*/
				//lb->setPixmap(pm->scaled(w,h));
				//lb->setFixedHeight(width);
				//lb->setFixedWidth(width);
				//lb->setGeometry(j*(width+10),i*(width+10),width,width);

				//pf->setFixedHeight(width);
				//pf->setFixedWidth(width);
				grid->addWidget(pf,i,j);

				//vbox->addWidget(lb,1,0);

			}
			/*else
			{
				QLabel *lb2=new QLabel("");
				grid->addWidget(lb2,i,j);
			}*/
		}
	}

	//grid->activate();
}
