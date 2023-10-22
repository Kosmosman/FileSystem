//
// Created by Joaquina Daeron on 10/20/23.
//

#include "QtWidgets/qapplication.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    joaquind::mainwindow w;
    w.show();
    return a.exec();
}
