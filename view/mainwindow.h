#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "files_labels.h"
#include "scroll_area.h"

namespace Ui {
class mainwindow;
}
namespace joaquind {
    class mainwindow : public QWidget {
    Q_OBJECT

    public:
        explicit mainwindow(QWidget *parent = nullptr);

        ~mainwindow() override;

    private:
        Ui::mainwindow *ui;
        ScrollArea<FilesLabels> scroll_area_;
        QVBoxLayout layout_;
    };
}
#endif // MAINWINDOW_H
