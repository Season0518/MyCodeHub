//
// Created by Season on 2021/12/28.
//

#ifndef PROJECT5_USERWINDOW_H
#define PROJECT5_USERWINDOW_H

#include <QWidget>
#include "depositwindow.h"
#include "ui_depositwindow.h"
#include "../Class/userAccount.h"

QT_BEGIN_NAMESPACE
namespace Ui { class userwindow; }
QT_END_NAMESPACE

class userwindow : public QWidget {
Q_OBJECT

public:
    explicit userwindow(QWidget *parent = nullptr);
    ~userwindow() override;

private slots:
    void depositEvent();
    void exitEvent();

private:
    userAccount account;
    Ui::userwindow *ui;
};


#endif //PROJECT5_USERWINDOW_H
