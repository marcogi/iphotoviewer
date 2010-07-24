/********************************************************************************
** Form generated from reading UI file 'photopanel.ui'
**
** Created: Sat Jul 24 14:16:36 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOPANEL_H
#define UI_PHOTOPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoPanelClass
{
public:

    void setupUi(QWidget *PhotoPanelClass)
    {
        if (PhotoPanelClass->objectName().isEmpty())
            PhotoPanelClass->setObjectName(QString::fromUtf8("PhotoPanelClass"));
        PhotoPanelClass->resize(400, 319);

        retranslateUi(PhotoPanelClass);

        QMetaObject::connectSlotsByName(PhotoPanelClass);
    } // setupUi

    void retranslateUi(QWidget *PhotoPanelClass)
    {
        PhotoPanelClass->setWindowTitle(QApplication::translate("PhotoPanelClass", "PhotoPanel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PhotoPanelClass: public Ui_PhotoPanelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOPANEL_H
