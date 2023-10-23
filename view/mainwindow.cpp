#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

namespace joaquind {
    mainwindow::mainwindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainwindow) {
        layout_.addWidget(&tree_);
        layout_.addWidget(&finder_);
        layout_.addWidget(reinterpret_cast<QWidget *>(&rbutton_));
        layout_.addWidget(reinterpret_cast<QWidget *>(&fbutton_));
        tree_.SetHomeDirectory(std::getenv("HOME"));
        connect(&finder_, &QLineEdit::returnPressed, [this]() { EnterPressed(); });
        connect(&rbutton_, &ResetButton::clicked, [this]() { ResetPressed(); });
        connect(&fbutton_, &FindButton::clicked, [this]() { Find(); });
        ui->setupUi(this);
    }

    mainwindow::~mainwindow() {
        delete ui;
    }

    void mainwindow::EnterPressed() {
        if (finder_.text().isEmpty()) {
            tree_.ResetSearch();
        } else {
            Find();
        }
    }

    void mainwindow::ResetPressed() {
        finder_.clear();
        tree_.ResetSearch();
        tree_.collapseAll();
    }

    void mainwindow::Find() {
        QString filter{"*" + finder_.text() + "*"};
        tree_.SetFilter(filter);
    }
}
