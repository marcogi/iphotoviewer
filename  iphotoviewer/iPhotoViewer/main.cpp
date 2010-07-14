#include "iphotoviewer.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iPhotoViewer w;
    w.show();
    return a.exec();
}
