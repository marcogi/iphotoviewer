/********************************************************************************
** Form generated from reading UI file 'iphotoviewer.ui'
**
** Created: Tue Jul 20 22:25:57 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPHOTOVIEWER_H
#define UI_IPHOTOVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iPhotoViewerClass
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QListView *lstPhotos;
    QListView *lstAlbums;
    QListView *lstPhotosInAlbum;
    QListView *lstRolls;
    QMenuBar *menubar;
    QMenu *menuIPhotoViewer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *iPhotoViewerClass)
    {
        if (iPhotoViewerClass->objectName().isEmpty())
            iPhotoViewerClass->setObjectName(QString::fromUtf8("iPhotoViewerClass"));
        iPhotoViewerClass->resize(800, 600);
        centralwidget = new QWidget(iPhotoViewerClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 520, 251, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 10, 521, 531));
        lstPhotos = new QListView(centralwidget);
        lstPhotos->setObjectName(QString::fromUtf8("lstPhotos"));
        lstPhotos->setGeometry(QRect(10, 10, 251, 91));
        lstAlbums = new QListView(centralwidget);
        lstAlbums->setObjectName(QString::fromUtf8("lstAlbums"));
        lstAlbums->setGeometry(QRect(10, 110, 251, 101));
        lstPhotosInAlbum = new QListView(centralwidget);
        lstPhotosInAlbum->setObjectName(QString::fromUtf8("lstPhotosInAlbum"));
        lstPhotosInAlbum->setGeometry(QRect(10, 370, 251, 141));
        lstRolls = new QListView(centralwidget);
        lstRolls->setObjectName(QString::fromUtf8("lstRolls"));
        lstRolls->setGeometry(QRect(10, 220, 251, 141));
        iPhotoViewerClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(iPhotoViewerClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuIPhotoViewer = new QMenu(menubar);
        menuIPhotoViewer->setObjectName(QString::fromUtf8("menuIPhotoViewer"));
        iPhotoViewerClass->setMenuBar(menubar);
        statusbar = new QStatusBar(iPhotoViewerClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        iPhotoViewerClass->setStatusBar(statusbar);

        menubar->addAction(menuIPhotoViewer->menuAction());

        retranslateUi(iPhotoViewerClass);

        QMetaObject::connectSlotsByName(iPhotoViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *iPhotoViewerClass)
    {
        iPhotoViewerClass->setWindowTitle(QString());
        pushButton->setText(QApplication::translate("iPhotoViewerClass", "Fill", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("iPhotoViewerClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuIPhotoViewer->setTitle(QApplication::translate("iPhotoViewerClass", "Datei", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class iPhotoViewerClass: public Ui_iPhotoViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPHOTOVIEWER_H
