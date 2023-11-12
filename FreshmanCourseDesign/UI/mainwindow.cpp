//
// Created by Season on 2021/12/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include <iostream>
#include "QMessageBox"
#include "ui_mainwindow.h"
#include "../global.h"
#include "ui_userwindow.h"
#include "userwindow.h"
#include "../Class/userAccount.h"
#include "ui_depositwindow.h"
#include "depositwindow.h"

//std::string loginAccount;


string loginAccount;

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //槽函数定义
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(loginEvent()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exitEvent()));
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loginEvent() {
    QString qAccount = ui->accountEdit->text();
    QString qPassword = ui->passwordEdit->text();

    std::string inputAccount, inputPassword;

    inputAccount = qAccount.toStdString();
    inputPassword = qPassword.toStdString();

    auto currentAccount = new userAccount;
    currentAccount->initUserFromAccount(inputAccount);
    if (currentAccount->verifyPassword(inputAccount,inputPassword)) {
        std::string infoRaw = "欢迎回来，"+currentAccount->name;
        loginAccount = currentAccount->account;
        free(currentAccount);
        QMessageBox::information(this, "Info", infoRaw.c_str());
        this->hide();
        auto *uwindow = new userwindow;
        uwindow->show();
    } else {
        QMessageBox::critical(this, "Error", "用户名或密码错误，请重试！");
    }
    return;
}

void MainWindow::exitEvent() {
    close();
}







