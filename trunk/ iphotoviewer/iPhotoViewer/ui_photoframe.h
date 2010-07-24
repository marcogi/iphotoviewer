/********************************************************************************
** Form generated from reading UI file 'photoframe.ui'
**
** Created: Sat Jul 24 02:09:37 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOFRAME_H
#define UI_PHOTOFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoFrameClass
{
public:
    QLabel *photoWidget;
    QLabel *defaultBorder;
    QLabel *selectedBorder;

    void setupUi(QWidget *PhotoFrameClass)
    {
        if (PhotoFrameClass->objectName().isEmpty())
            PhotoFrameClass->setObjectName(QString::fromUtf8("PhotoFrameClass"));
        PhotoFrameClass->resize(400, 300);
        PhotoFrameClass->setStyleSheet(QString::fromUtf8(""));
        photoWidget = new QLabel(PhotoFrameClass);
        photoWidget->setObjectName(QString::fromUtf8("photoWidget"));
        photoWidget->setGeometry(QRect(180, 70, 91, 111));
        photoWidget->setStyleSheet(QString::fromUtf8("QLabel#photoWidget { \n"
"border-width: 5px; \n"
"border-style: outset; \n"
"border-color: #FFFF00; \n"
"border-radius: 10px; \n"
"/*background: #FFFFFF; */\n"
"color: #000000; \n"
"selection-background-color:#000000; \n"
"}"));
        defaultBorder = new QLabel(PhotoFrameClass);
        defaultBorder->setObjectName(QString::fromUtf8("defaultBorder"));
        defaultBorder->setGeometry(QRect(140, 50, 131, 151));
        defaultBorder->setStyleSheet(QString::fromUtf8("QLabel#defaultBorder { \n"
"border-width: 5px; \n"
"border-style: outset; \n"
"border-color: #DDDDDD; \n"
"border-radius: 10px; \n"
"/*background: #FFFFFF; */\n"
"color: #000000; \n"
"selection-background-color:#000000; \n"
"}"));
        selectedBorder = new QLabel(PhotoFrameClass);
        selectedBorder->setObjectName(QString::fromUtf8("selectedBorder"));
        selectedBorder->setGeometry(QRect(251, 50, 71, 151));
        selectedBorder->setStyleSheet(QString::fromUtf8("QLabel#selectedBorder { \n"
"border-width: 5px; \n"
"border-style: outset; \n"
"border-color: #FFFF00; \n"
"border-radius: 10px; \n"
"/*background: #FFFFFF; */\n"
"color: #000000; \n"
"selection-background-color:#000000; \n"
"}"));

        retranslateUi(PhotoFrameClass);

        QMetaObject::connectSlotsByName(PhotoFrameClass);
    } // setupUi

    void retranslateUi(QWidget *PhotoFrameClass)
    {
        PhotoFrameClass->setWindowTitle(QApplication::translate("PhotoFrameClass", "PhotoFrame", 0, QApplication::UnicodeUTF8));
        photoWidget->setText(QString());
        defaultBorder->setText(QString());
        selectedBorder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PhotoFrameClass: public Ui_PhotoFrameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOFRAME_H
