/********************************************************************************
** Form generated from reading UI file 'photoviewer.ui'
**
** Created: Sat Jul 24 11:17:35 2010
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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoViewerClass
{
public:
    QLabel *photo;
    QPushButton *goBack;

    void setupUi(QWidget *PhotoViewerClass)
    {
        if (PhotoViewerClass->objectName().isEmpty())
            PhotoViewerClass->setObjectName(QString::fromUtf8("PhotoViewerClass"));
        PhotoViewerClass->resize(400, 300);
        PhotoViewerClass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:#555555;\n"
"}"));
        photo = new QLabel(PhotoViewerClass);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(10, 50, 171, 121));
        photo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"border:1px solid #000000;\n"
"}"));
        goBack = new QPushButton(PhotoViewerClass);
        goBack->setObjectName(QString::fromUtf8("goBack"));
        goBack->setGeometry(QRect(10, 10, 85, 27));

        retranslateUi(PhotoViewerClass);

        QMetaObject::connectSlotsByName(PhotoViewerClass);
    } // setupUi

    void retranslateUi(QWidget *PhotoViewerClass)
    {
        PhotoViewerClass->setWindowTitle(QApplication::translate("PhotoViewerClass", "PhotoViewer", 0, QApplication::UnicodeUTF8));
        photo->setText(QString());
        goBack->setText(QApplication::translate("PhotoViewerClass", "Go back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhotoViewerClass: public Ui_PhotoViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOVIEWER_H
