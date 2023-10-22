//
// Created by Joaquina Daeron on 10/22/23.
//

#ifndef FILESYSTEM_SCROLL_AREA_H
#define FILESYSTEM_SCROLL_AREA_H

#include <QWidget>
#include <QScrollArea>

namespace joaquind {

    template<typename T>
    class ScrollArea : public QScrollArea {
    public:
        explicit ScrollArea(QWidget *parent = nullptr) : QScrollArea(parent) {
            this->setWidgetResizable(true);
            this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        };

        void AddLabel(std::unique_ptr<T> &&label) { labels_.push_back(std::move(label)); };
    private:
        std::vector<std::unique_ptr<T>> labels_{};
    };

} // joaquind

#endif //FILESYSTEM_SCROLL_AREA_H
