//
// Created by Season on 2021/12/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userwindow.h" resolved

#include "userwindow.h"
#include "ui_userwindow.h"
#include "../global.h"

#include <iostream>
#include <time.h>

extern std::string loginAccount;

userwindow::userwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::userwindow) {
    ui->setupUi(this);

    //获取当前时间对应的欢迎语
    auto getCurrentTimeRaw = [](void){
        time_t timeStamp;
        time(&timeStamp);
        auto currentTime = localtime(&timeStamp);
        const int currentHour = currentTime->tm_hour;
        const int morning = 3,noon = 11,afternoon = 14,evening = 18,midNight=23;
        std::cout << currentHour << std::endl;
        if(morning <= currentHour && noon >= currentHour){
            return "上午好，";
        }
        else if(noon <= currentHour && currentHour <= afternoon) {
            return "中午好，";
        }
        else if(afternoon <= currentHour && currentHour <= evening){
            return "下午好，";
        }
        else if(currentHour >= evening && currentHour <= midNight || currentHour <= morning){
            return "晚上好，";
        }
        else{
            return "你好，";
        }
    };

    //连接槽函数
    connect(ui->depositButton,SIGNAL(clicked()),this,SLOT(depositEvent()));
    connect(ui->safeLogoutButton,SIGNAL(clicked()),this,SLOT(exitEvent()));

    account.initUserFromAccount(loginAccount);
    std::string WelcomeRaw = getCurrentTimeRaw()+account.name;
    ui->welcomeLabel->setText(QString::fromLocal8Bit(WelcomeRaw.c_str()));
}

userwindow::~userwindow() {
    delete ui;
}

void userwindow::depositEvent() {
    auto depositWidget = new depositwindow;
    depositWidget->initDepositor(&account);
    depositWidget->show();
    std::cout << account.name << std::endl;
    return;
}

void userwindow::exitEvent() {
    close();
}