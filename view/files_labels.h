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
        FilesLabels(QString &&text, QWidget *parent = nullptr) : QPushButton(parent) {
            setFlat(true);
            setStyleSheet("QPushButton { border: none; background-color: transparent; text-align: left; }"
                          "QPushButton::before { content: \"∟ \"; padding-right: 10px; color : white }"
                          "QPushButton { color : white }");
            setText(text);
        }

        ~FilesLabels() override = default;
    };

    struct FilesLabelsCreator {
        static std::shared_ptr<FilesLabels> CreateFileLabel(QString &&s, QWidget *parent = nullptr) {
            return std::make_shared<FilesLabels>(std::move(s), parent);
        }
    };

} // joaquind

#endif //FILESYSTEM_FILES_LABELS_H
