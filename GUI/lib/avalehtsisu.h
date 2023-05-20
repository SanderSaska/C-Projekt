#ifndef AVALEHTSISU_H
#define AVALEHTSISU_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class avalehtSisu;
}

class avalehtSisu : public QWidget
{
    Q_OBJECT

public:
    explicit avalehtSisu(QWidget *parent = nullptr);
    ~avalehtSisu();

signals:
    void edasiLauaValikuleSignaal();

private slots:
    void valju();
    void edasi();

private:
    Ui::avalehtSisu *ui;
};

#endif // AVALEHTSISU_H
