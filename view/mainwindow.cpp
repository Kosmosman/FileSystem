#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace joaquind {
    mainwindow::mainwindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainwindow), scroll_area_(this), layout_(this) {
        layout_.addWidget(&scroll_area_);
        setLayout(&layout_);
        for (int i = 0; i < 50; ++i) {
            scroll_area_.AddLabel(FilesLabelsCreator::CreateFileLabel("Hello", &scroll_area_));
        }

        ui->setupUi(this);
    }

    mainwindow::~mainwindow() {
        delete ui;
    }
}
