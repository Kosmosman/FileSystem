//
// Created by Joaquina Daeron on 10/20/23.
//

#include "QtWidgets/qapplication.h"
#include "view/mainwindow.h"
#include <finder.h>
#include <filesystem_manager.h>

#include <iostream>

//int main() {
//    joaquind::FilesystemManager f;
//    joaquind::Finder<joaquind::FilesystemManager> fin(&f);
//    for (auto &i: f.GetFilesNameFromFile(true))
//        std::cout << i << '\n';
//    for (auto &i: f.GetFilesNameFromFile(true))
//        std::cout << i << '\n';
//    std::cout << "\n\n\n\"";
//    for (auto &i: fin.FindSuitableFiles("Ubuntu"))
//        std::cout << i << '\n';
//    return 0;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    joaquind::mainwindow w;
    w.show();
    return a.exec();
}
