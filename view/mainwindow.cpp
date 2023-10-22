#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace joaquind {
    mainwindow::mainwindow(QWidget *parent) :
            QWidget(parent),
            ui(new Ui::mainwindow),
            scroll_area_(this) {
        scroll_area_.AddLabel(FilesLabelsCreator::CreateFileLabel("Hello!", this));
        scroll_area_.AddLabel(FilesLabelsCreator::CreateFileLabel("A!", this));
        ui->setupUi(this);
    }

    mainwindow::~mainwindow() {
        delete ui;
    }
}