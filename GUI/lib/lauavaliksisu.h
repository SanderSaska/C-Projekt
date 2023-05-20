#ifndef LAUAVALIKSISU_H
#define LAUAVALIKSISU_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class lauaValikSisu;
}

class lauaValikSisu : public QWidget
{
    Q_OBJECT

public:
    explicit lauaValikSisu(QWidget *parent = nullptr);
    ~lauaValikSisu();

signals:
    void tagasiAvalehele();

private slots:
    void edasi();
    void tagasi();

private:
    Ui::lauaValikSisu *ui;
};

#endif // LAUAVALIKSISU_H
