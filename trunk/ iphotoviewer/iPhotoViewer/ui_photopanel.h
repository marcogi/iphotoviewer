/********************************************************************************
** Form generated from reading UI file 'photopanel.ui'
**
** Created: Wed Aug 18 20:08:35 2010
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoPanelClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *navigationWidget;
    QWidget *contentWidget;

    void setupUi(QWidget *PhotoPanelClass)
    {
        if (PhotoPanelClass->objectName().isEmpty())
            PhotoPanelClass->setObjectName(QString::fromUtf8("PhotoPanelClass"));
        PhotoPanelClass->resize(400, 319);
        verticalLayout = new QVBoxLayout(PhotoPanelClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        navigationWidget = new QWidget(PhotoPanelClass);
        navigationWidget->setObjectName(QString::fromUtf8("navigationWidget"));
        navigationWidget->setMaximumSize(QSize(16777215, 27));
        navigationWidget->setStyleSheet(QString::fromUtf8("#navigationWidget {background-color:#000000;}"));

        verticalLayout->addWidget(navigationWidget);

        contentWidget = new QWidget(PhotoPanelClass);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));

        verticalLayout->addWidget(contentWidget);


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
