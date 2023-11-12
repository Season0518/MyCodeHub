#include <QApplication>
#include <QPushButton>
#include "UI/ui_mainwindow.h"
#include "UI/mainwindow.h"
#include "UI/ui_userwindow.h"
#include "UI/userwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    MainWindow mwindow;
    mwindow.show();
//    userwindow uwindow;
//    if(uwindow.exec())



    return QApplication::exec();
}
