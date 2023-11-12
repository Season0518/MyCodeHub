/********************************************************************************
** Form generated from reading UI file 'userwindowziDiWB.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef USERWINDOWZIDIWB_H
#define USERWINDOWZIDIWB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwindow
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *welcomeLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *balanceLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *totalRevenueLabel;
    QLabel *totalIncomeLabel;
    QLabel *label_3;
    QTableView *finical;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *changePasswordButton;
    QPushButton *depositButton;
    QPushButton *withDrawButton;
    QPushButton *safeLogoutButton;

    void setupUi(QWidget *userwindow)
    {
        if (userwindow->objectName().isEmpty())
            userwindow->setObjectName(QString::fromUtf8("userwindow"));
        userwindow->resize(686, 448);
        verticalLayout_4 = new QVBoxLayout(userwindow);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        welcomeLabel = new QLabel(userwindow);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        QFont font;
        font.setPointSize(18);
        welcomeLabel->setFont(font);

        verticalLayout_4->addWidget(welcomeLabel);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        balanceLabel = new QLabel(userwindow);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));
        QFont font1;
        font1.setPointSize(15);
        balanceLabel->setFont(font1);

        verticalLayout_2->addWidget(balanceLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        totalRevenueLabel = new QLabel(userwindow);
        totalRevenueLabel->setObjectName(QString::fromUtf8("totalRevenueLabel"));
        QFont font2;
        font2.setPointSize(14);
        totalRevenueLabel->setFont(font2);

        horizontalLayout_2->addWidget(totalRevenueLabel);

        totalIncomeLabel = new QLabel(userwindow);
        totalIncomeLabel->setObjectName(QString::fromUtf8("totalIncomeLabel"));

        horizontalLayout_2->addWidget(totalIncomeLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        label_3 = new QLabel(userwindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        verticalLayout_4->addWidget(label_3);

        finical = new QTableView(userwindow);
        finical->setObjectName(QString::fromUtf8("finical"));

        verticalLayout_4->addWidget(finical);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(userwindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        changePasswordButton = new QPushButton(userwindow);
        changePasswordButton->setObjectName(QString::fromUtf8("changePasswordButton"));

        horizontalLayout_3->addWidget(changePasswordButton);

        depositButton = new QPushButton(userwindow);
        depositButton->setObjectName(QString::fromUtf8("depositButton"));

        horizontalLayout_3->addWidget(depositButton);

        withDrawButton = new QPushButton(userwindow);
        withDrawButton->setObjectName(QString::fromUtf8("withDrawButton"));

        horizontalLayout_3->addWidget(withDrawButton);

        safeLogoutButton = new QPushButton(userwindow);
        safeLogoutButton->setObjectName(QString::fromUtf8("safeLogoutButton"));

        horizontalLayout_3->addWidget(safeLogoutButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(userwindow);

        QMetaObject::connectSlotsByName(userwindow);
    } // setupUi

    void retranslateUi(QWidget *userwindow)
    {
        userwindow->setWindowTitle(QCoreApplication::translate("userwindow", "userwindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("userwindow", "\344\270\255\345\215\210\345\245\275\357\274\214", nullptr));
        balanceLabel->setText(QCoreApplication::translate("userwindow", "\346\200\273\350\265\204\344\272\247:", nullptr));
        totalRevenueLabel->setText(QCoreApplication::translate("userwindow", "\346\200\273\346\224\257\345\207\272:", nullptr));
        totalIncomeLabel->setText(QCoreApplication::translate("userwindow", "\346\200\273\346\224\266\345\205\245:", nullptr));
        label_3->setText(QCoreApplication::translate("userwindow", "\346\224\266\346\224\257\350\257\246\346\203\205", nullptr));
#if QT_CONFIG(tooltip)
        finical->setToolTip(QCoreApplication::translate("userwindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("userwindow", "\344\270\232\345\212\241\345\212\236\347\220\206\345\214\272", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        depositButton->setText(QCoreApplication::translate("userwindow", "\346\264\273\346\234\237\345\255\230\346\254\276", nullptr));
        withDrawButton->setText(QCoreApplication::translate("userwindow", "\346\264\273\346\234\237\345\217\226\346\254\276", nullptr));
        safeLogoutButton->setText(QCoreApplication::translate("userwindow", "\345\256\211\345\205\250\347\231\273\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwindow: public Ui_userwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // USERWINDOWZIDIWB_H
