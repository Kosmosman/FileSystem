//
// Created by Joaquina Daeron on 10/22/23.
//

#ifndef FILESYSTEM_FILES_LABELS_H
#define FILESYSTEM_FILES_LABELS_H

#include <QWidget>
#include <QPushButton>

namespace joaquind {

    class FilesLabels : public QPushButton {
    public:
        FilesLabels(QString &&text, QWidget *parent) : QPushButton(parent) {
            setFlat(true);
            setStyleSheet("QPushButton { border: none; background-color: transparent; text-align: left; }"
                          "QPushButton::before { content: \"∟ \"; padding-right: 10px; }"
                          "QPushButton { color : white }");
            setText(text);
        }
    };

    struct FilesLabelsCreator {
        static std::unique_ptr<FilesLabels> CreateFileLabel(QString &&s, QWidget *parent = nullptr) {
            return std::make_unique<FilesLabels>(std::move(s), parent);
        }
    };

} // joaquind

#endif //FILESYSTEM_FILES_LABELS_H
