#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include "tree_model.h"
#include "finder.h"

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
        void EnterPressed();
        void ResetPressed();
        void Find();

        Ui::mainwindow *ui;
        QVBoxLayout layout_{this};
        TreeModel tree_{this};
        Finder finder_{this};
        ResetButton rbutton_{this};

        FindButton fbutton_{this};
    };
}
#endif // MAINWINDOW_H
