/********************************************************************************
** Form generated from reading UI file 'navigationbar.ui'
**
** Created: Fri Aug 20 22:40:59 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONBAR_H
#define UI_NAVIGATIONBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationBarClass
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRolls;
    QLabel *lblCaption;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPreviousRoll;
    QPushButton *btnNextRoll;

    void setupUi(QWidget *NavigationBarClass)
    {
        if (NavigationBarClass->objectName().isEmpty())
            NavigationBarClass->setObjectName(QString::fromUtf8("NavigationBarClass"));
        NavigationBarClass->resize(433, 27);
        horizontalLayout = new QHBoxLayout(NavigationBarClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        btnRolls = new QPushButton(NavigationBarClass);
        btnRolls->setObjectName(QString::fromUtf8("btnRolls"));
        btnRolls->setMaximumSize(QSize(85, 16777215));

        horizontalLayout->addWidget(btnRolls);

        lblCaption = new QLabel(NavigationBarClass);
        lblCaption->setObjectName(QString::fromUtf8("lblCaption"));

        horizontalLayout->addWidget(lblCaption);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPreviousRoll = new QPushButton(NavigationBarClass);
        btnPreviousRoll->setObjectName(QString::fromUtf8("btnPreviousRoll"));
        btnPreviousRoll->setMaximumSize(QSize(35, 16777215));

        horizontalLayout->addWidget(btnPreviousRoll);

        btnNextRoll = new QPushButton(NavigationBarClass);
        btnNextRoll->setObjectName(QString::fromUtf8("btnNextRoll"));
        btnNextRoll->setMaximumSize(QSize(35, 16777215));
        btnNextRoll->setFlat(false);

        horizontalLayout->addWidget(btnNextRoll);


        retranslateUi(NavigationBarClass);

        QMetaObject::connectSlotsByName(NavigationBarClass);
    } // setupUi

    void retranslateUi(QWidget *NavigationBarClass)
    {
        NavigationBarClass->setWindowTitle(QApplication::translate("NavigationBarClass", "NavigationBar", 0, QApplication::UnicodeUTF8));
        btnRolls->setText(QApplication::translate("NavigationBarClass", "Rolls", 0, QApplication::UnicodeUTF8));
        lblCaption->setText(QApplication::translate("NavigationBarClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnPreviousRoll->setText(QApplication::translate("NavigationBarClass", "<<", 0, QApplication::UnicodeUTF8));
        btnNextRoll->setText(QApplication::translate("NavigationBarClass", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavigationBarClass: public Ui_NavigationBarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONBAR_H
