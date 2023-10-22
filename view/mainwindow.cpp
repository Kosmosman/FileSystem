#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

namespace joaquind {
    mainwindow::mainwindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainwindow) {
        layout_.addWidget(&tree_);
        layout_.addWidget(&finder_);
        layout_.addWidget(&button_);
        tree_.SetHomeDirectory(std::getenv("HOME"));
        connect(&finder_, &QLineEdit::returnPressed, [this]() { EnterPressed(); });
        connect(&button_, &ResetButton::clicked, [this]() { ResetPressed(); });
        ui->setupUi(this);
    }

    mainwindow::~mainwindow() {
        delete ui;
    }

    void mainwindow::EnterPressed() {
        QString filter;
        if (finder_.text().isEmpty()) {
            tree_.ResetSearch();
        } else {
            filter = "*" + finder_.text() + "*";
            tree_.SetFilter(filter);
        }
    }

    void mainwindow::ResetPressed() {
        finder_.clear();
        tree_.ResetSearch();
        tree_.collapseAll();
    }
}
