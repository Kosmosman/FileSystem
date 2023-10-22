//
// Created by Joaquina Daeron on 10/22/23.
//

#ifndef FILESYSTEM_SCROLL_AREA_H
#define FILESYSTEM_SCROLL_AREA_H

#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <vector>
#include <utility>

namespace joaquind {

    template<typename T>
    class ScrollArea : public QScrollArea {
    public:
        explicit ScrollArea(QWidget *parent = nullptr) : QScrollArea(parent), widget_(this), layout_(&widget_) {
            setWidget(&widget_);
            this->setWidgetResizable(true);
            this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            setGeometry(0, 0, parent->width(), parent->height());
        };

        void AddLabel(std::shared_ptr<T> &&label) {
            labels_.emplace_back(label);
            position_.emplace_back(position_.back().first, position_.back().second + 20);
            labels_.back()->move(position_.back().first, position_.back().second);
            layout_.addWidget(labels_.back().get());
        };

        ~ScrollArea() override {labels_.clear(); };

    private:
        std::vector<std::shared_ptr<T>> labels_{};
        std::vector<std::pair<int, int>> position_{{0, 0}};
        QWidget widget_;
        QVBoxLayout layout_;
    };

} // joaquind

#endif //FILESYSTEM_SCROLL_AREA_H
