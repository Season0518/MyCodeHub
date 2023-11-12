//
// Created by Season on 2021/12/27.
//

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void loginEvent();
    void exitEvent();

private:
    Ui::MainWindow *ui;
};


#endif //UNTITLED_MAINWINDOW_H
