//d
// Created by Season on 2021/12/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_despositwindow.h" resolved

#include "depositwindow.h"
#include "ui_depositwindow.h"
#include <iostream>
#include <string>

depositwindow::depositwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::depositwindow) {
    ui->setupUi(this);
    //连接信号槽
    connect(ui->depositButton,SIGNAL(clicked()),this,SLOT(depositEvent()));
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(exitEvent()));

    //控制存款金额输入框输入合法
    auto cashVaildator=new QIntValidator(100,1000000,this);
    ui->depositCashEdit->setValidator(cashVaildator);
}

depositwindow::~depositwindow() {

    delete ui;
}

void depositwindow::depositEvent() {
    QString qCashString = ui->depositCashEdit->text();
    std::string cashString = qCashString.toStdString();
    account->precisionKeepDeposit(cashString);
    std::cout << "存款金额:" << account->getUserBalance() << std::endl;
    return;
}

void depositwindow::exitEvent() {
    close();
}

void depositwindow::initDepositor(userAccount *depositorAccount) {
    account = depositorAccount;
    return;
}



