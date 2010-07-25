/********************************************************************************
** Form generated from reading UI file 'iphotoviewer.ui'
**
** Created: Sun Jul 25 12:09:39 2010
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iPhotoViewerClass
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListView *lstRolls;
    QListView *lstAlbums;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;

    void setupUi(QMainWindow *iPhotoViewerClass)
    {
        if (iPhotoViewerClass->objectName().isEmpty())
            iPhotoViewerClass->setObjectName(QString::fromUtf8("iPhotoViewerClass"));
        iPhotoViewerClass->resize(799, 600);
        centralwidget = new QWidget(iPhotoViewerClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstRolls = new QListView(widget);
        lstRolls->setObjectName(QString::fromUtf8("lstRolls"));

        verticalLayout->addWidget(lstRolls);

        lstAlbums = new QListView(widget);
        lstAlbums->setObjectName(QString::fromUtf8("lstAlbums"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lstAlbums->sizePolicy().hasHeightForWidth());
        lstAlbums->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lstAlbums);


        horizontalLayout->addWidget(widget);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        QPalette palette;
        QBrush brush(QColor(85, 85, 85, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        scrollArea->setPalette(palette);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 517, 559));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        iPhotoViewerClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(iPhotoViewerClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 799, 21));
        iPhotoViewerClass->setMenuBar(menubar);

        retranslateUi(iPhotoViewerClass);

        QMetaObject::connectSlotsByName(iPhotoViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *iPhotoViewerClass)
    {
        iPhotoViewerClass->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class iPhotoViewerClass: public Ui_iPhotoViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPHOTOVIEWER_H
