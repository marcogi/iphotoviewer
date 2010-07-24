/********************************************************************************
** Form generated from reading UI file 'photoviewer.ui'
**
** Created: Sat Jul 24 14:29:02 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOVIEWER_H
#define UI_PHOTOVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoViewerClass
{
public:
    QPushButton *goBack;

    void setupUi(QWidget *PhotoViewerClass)
    {
        if (PhotoViewerClass->objectName().isEmpty())
            PhotoViewerClass->setObjectName(QString::fromUtf8("PhotoViewerClass"));
        PhotoViewerClass->resize(400, 300);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(85, 85, 85, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        PhotoViewerClass->setPalette(palette);
        PhotoViewerClass->setAutoFillBackground(true);
        goBack = new QPushButton(PhotoViewerClass);
        goBack->setObjectName(QString::fromUtf8("goBack"));
        goBack->setGeometry(QRect(10, 10, 85, 27));
        goBack->setAutoFillBackground(true);

        retranslateUi(PhotoViewerClass);

        QMetaObject::connectSlotsByName(PhotoViewerClass);
    } // setupUi

    void retranslateUi(QWidget *PhotoViewerClass)
    {
        PhotoViewerClass->setWindowTitle(QApplication::translate("PhotoViewerClass", "PhotoViewer", 0, QApplication::UnicodeUTF8));
        goBack->setText(QApplication::translate("PhotoViewerClass", "Go back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhotoViewerClass: public Ui_PhotoViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOVIEWER_H
