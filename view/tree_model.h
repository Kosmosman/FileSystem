//
// Created by Joaquina Daeron on 10/22/23.
//

#ifndef FILESYSTEM_TREE_MODEL_H
#define FILESYSTEM_TREE_MODEL_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QHeaderView>

namespace joaquind {

    class TreeModel : public QTreeView {
    public:
        explicit TreeModel(QWidget *parent) : QTreeView(parent) {
            QTreeView::setModel(&model_);
            model_.setFilter(QDir::AllEntries | QDir::Hidden);
            header()->setSectionResizeMode(QHeaderView::Stretch);
        }

        void SetHomeDirectory(const std::string &root) {
            root_index_ = model_.setRootPath(root.c_str());
            QTreeView::setRootIndex(root_index_);
        }

        void SetFilter(const QString &filter) {
            model_.setNameFilters(QList<QString>{filter});
            model_.setNameFilterDisables(false);
        };

        void ResetSearch() {
            model_.setNameFilters(QStringList());
        }

    private:
        QFileSystemModel model_{};
        QModelIndex root_index_;

    };

} // joaquind

#endif //FILESYSTEM_TREE_MODEL_H
