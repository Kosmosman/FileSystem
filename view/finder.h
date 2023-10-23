//
// Created by Joaquina Daeron on 10/22/23.
//

#ifndef FILESYSTEM_FINDER_H
#define FILESYSTEM_FINDER_H

#include <QLineEdit>
#include <QPushButton>

namespace joaquind {

    class ResetButton : public QPushButton {
    public:
        explicit ResetButton(QWidget *parent = nullptr) : QPushButton(parent) {
            setText("Reset");
        }
    };

    class FindButton : public QPushButton {
    public:
        explicit FindButton(QWidget *parent = nullptr) : QPushButton(parent) {
                setText("Find");
        };
    };



    class Finder : public QLineEdit {
    public:
        explicit Finder(QWidget *parent = nullptr) : QLineEdit(parent), widget_(parent), layout_(&widget_) {
            setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            setGeometry(0, 0, parent->width(), 20);
            setPlaceholderText(" Input filename...");
            setStyleSheet("QLineEdit::placeholder { color: grey; background-color : white}");
            layout_.addWidget(this);
            layout_.setAlignment(Qt::AlignBottom | Qt::AlignRight);
        };

    private:
        QWidget widget_;
        QHBoxLayout layout_;
    };
} // joaquind

#endif //FILESYSTEM_FINDER_H
