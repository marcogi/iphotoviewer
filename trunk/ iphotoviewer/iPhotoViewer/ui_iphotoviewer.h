/********************************************************************************
** Form generated from reading UI file 'iphotoviewer.ui'
**
** Created: Wed Aug 18 00:01:12 2010
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
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
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
    QListView *lstAlbums;
    QPushButton *btnRolls;
    QWidget *contentWidget;
    QVBoxLayout *contentLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSlider *zoomSlider;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;

    void setupUi(QMainWindow *iPhotoViewerClass)
    {
        if (iPhotoViewerClass->objectName().isEmpty())
            iPhotoViewerClass->setObjectName(QString::fromUtf8("iPhotoViewerClass"));
        iPhotoViewerClass->resize(614, 338);
        iPhotoViewerClass->setMinimumSize(QSize(614, 338));
        centralwidget = new QWidget(iPhotoViewerClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(200, 0));
        widget->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstAlbums = new QListView(widget);
        lstAlbums->setObjectName(QString::fromUtf8("lstAlbums"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(lstAlbums->sizePolicy().hasHeightForWidth());
        lstAlbums->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lstAlbums);

        btnRolls = new QPushButton(widget);
        btnRolls->setObjectName(QString::fromUtf8("btnRolls"));

        verticalLayout->addWidget(btnRolls);


        horizontalLayout->addWidget(widget);

        contentWidget = new QWidget(centralwidget);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(contentWidget->sizePolicy().hasHeightForWidth());
        contentWidget->setSizePolicy(sizePolicy3);
        contentLayout = new QVBoxLayout(contentWidget);
        contentLayout->setSpacing(0);
        contentLayout->setContentsMargins(0, 0, 0, 0);
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        frame = new QFrame(contentWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 20));
        frame->setMaximumSize(QSize(16777215, 20));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        zoomSlider = new QSlider(frame);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(zoomSlider);


        contentLayout->addWidget(frame);

        scrollArea = new QScrollArea(contentWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(60);
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 386, 269));
        scrollArea->setWidget(scrollAreaWidgetContents);

        contentLayout->addWidget(scrollArea);


        horizontalLayout->addWidget(contentWidget);

        iPhotoViewerClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(iPhotoViewerClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 614, 27));
        iPhotoViewerClass->setMenuBar(menubar);

        retranslateUi(iPhotoViewerClass);

        QMetaObject::connectSlotsByName(iPhotoViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *iPhotoViewerClass)
    {
        iPhotoViewerClass->setWindowTitle(QString());
        btnRolls->setText(QApplication::translate("iPhotoViewerClass", "Rolls", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class iPhotoViewerClass: public Ui_iPhotoViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPHOTOVIEWER_H
