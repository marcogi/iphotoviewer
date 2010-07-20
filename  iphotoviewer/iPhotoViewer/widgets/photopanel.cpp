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

	int rows = list->rowCount() / labelsPerRow;
	QVBoxLayout *vbox=new QVBoxLayout(this);
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<labelsPerRow;j++)
		{
			if(i*labelsPerRow+j+1<=list->rowCount())
			{
				QLabel *lb=new QLabel();
				QModelIndex idx=list->index(i,0,QModelIndex());
				Photo *p=(Photo*)list->get(idx);
				lb->setPixmap(QPixmap(p->getThumbPath()));
				//lb->setFixedWidth(width);
				lb->setGeometry(j*(50+10),i*(50+10),50,50);

				vbox->addWidget(lb,1,0);

			}
		}
	}

	vbox->activate();
}
