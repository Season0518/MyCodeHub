//
// Created by Season on 2021/12/28.
//

#ifndef PROJECT5_DEPOSITWINDOW_H
#define PROJECT5_DEPOSITWINDOW_H

#include <QWidget>
#include <qvalidator.h>
#include "../Class/userAccount.h"

QT_BEGIN_NAMESPACE
namespace Ui { class depositwindow; }
QT_END_NAMESPACE

class depositwindow : public QWidget {
Q_OBJECT

public:
    explicit depositwindow(QWidget *parent = nullptr);
    ~depositwindow() override;
    void initDepositor(userAccount *depositorAccount);

private slots:
    void depositEvent();
    void exitEvent();

private:
    Ui::depositwindow *ui;
    userAccount *account;
};


#endif //PROJECT5_DEPOSITWINDOW_H
