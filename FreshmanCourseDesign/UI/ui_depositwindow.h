/********************************************************************************
** Form generated from reading UI file 'depositwindowLfeoaZ.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DEPOSITWINDOWLFEOAZ_H
#define DEPOSITWINDOWLFEOAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_depositwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *depositCashEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *depositButton;
    QPushButton *exitButton;

    void setupUi(QWidget *depositwindow)
    {
        if (depositwindow->objectName().isEmpty())
            depositwindow->setObjectName(QString::fromUtf8("depositwindow"));
        depositwindow->resize(292, 177);
        verticalLayout_2 = new QVBoxLayout(depositwindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(depositwindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        depositCashEdit = new QLineEdit(depositwindow);
        depositCashEdit->setObjectName(QString::fromUtf8("depositCashEdit"));

        horizontalLayout->addWidget(depositCashEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        depositButton = new QPushButton(depositwindow);
        depositButton->setObjectName(QString::fromUtf8("depositButton"));

        horizontalLayout_2->addWidget(depositButton);

        exitButton = new QPushButton(depositwindow);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(depositwindow);

        QMetaObject::connectSlotsByName(depositwindow);
    } // setupUi

    void retranslateUi(QWidget *depositwindow)
    {
        depositwindow->setWindowTitle(QCoreApplication::translate("depositwindow", "depositwindow", nullptr));
        label->setText(QCoreApplication::translate("depositwindow", "\345\255\230\346\254\276\351\207\221\351\242\235:", nullptr));
        depositCashEdit->setText(QString());
        depositButton->setText(QCoreApplication::translate("depositwindow", "\347\241\256\350\256\244\345\255\230\346\254\276", nullptr));
        exitButton->setText(QCoreApplication::translate("depositwindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class depositwindow: public Ui_depositwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DEPOSITWINDOWLFEOAZ_H
