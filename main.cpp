#include "maininterface.h"
#include <QApplication>
#include "CreateDatebase.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //a.setStyleSheet("QPushButton:hover{background-color:rgba(255,255,255,80%);}");
    createConnection();
    MainInterface w;
    w.show();

    return a.exec();
}
