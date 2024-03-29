/********************************************************************************
** Form generated from reading UI file 'photoframe.ui'
**
** Created: Wed Aug 18 00:01:12 2010
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
    QLabel *caption;

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
        defaultBorder->setGeometry(QRect(190, 50, 131, 151));
        defaultBorder->setStyleSheet(QString::fromUtf8("QLabel#defaultBorder { \n"
"border-width: 1px; \n"
"border-style: solid; \n"
"border-color: #000000; \n"
"border-radius: 10px; \n"
"color: #000000; \n"
"selection-background-color:#000000; \n"
"}"));
        selectedBorder = new QLabel(PhotoFrameClass);
        selectedBorder->setObjectName(QString::fromUtf8("selectedBorder"));
        selectedBorder->setGeometry(QRect(251, 50, 71, 151));
        selectedBorder->setStyleSheet(QString::fromUtf8("QLabel#selectedBorder { \n"
"border-width: 3px; \n"
"border-style: outset; \n"
"border-color: #FFFF00; \n"
"border-radius: 10px; \n"
"/*background: #FFFFFF; */\n"
"color: #000000; \n"
"selection-background-color:#000000; \n"
"}"));
        caption = new QLabel(PhotoFrameClass);
        caption->setObjectName(QString::fromUtf8("caption"));
        caption->setGeometry(QRect(170, 240, 52, 13));
        QPalette palette;
        QBrush brush(QColor(221, 221, 221, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(108, 106, 102, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        caption->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(8);
        caption->setFont(font);
        caption->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        photoWidget->raise();
        selectedBorder->raise();
        caption->raise();
        defaultBorder->raise();

        retranslateUi(PhotoFrameClass);

        QMetaObject::connectSlotsByName(PhotoFrameClass);
    } // setupUi

    void retranslateUi(QWidget *PhotoFrameClass)
    {
        PhotoFrameClass->setWindowTitle(QApplication::translate("PhotoFrameClass", "PhotoFrame", 0, QApplication::UnicodeUTF8));
        photoWidget->setText(QString());
        defaultBorder->setText(QString());
        selectedBorder->setText(QString());
        caption->setText(QApplication::translate("PhotoFrameClass", "caption", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhotoFrameClass: public Ui_PhotoFrameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOFRAME_H
