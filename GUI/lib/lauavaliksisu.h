#ifndef LAUAVALIKSISU_H
#define LAUAVALIKSISU_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class lauavalikSisu;
}

class lauavalikSisu : public QWidget
{
    Q_OBJECT

public:
    explicit lauavalikSisu(QWidget *parent = nullptr);
    ~lauavalikSisu();

signals:
    void tagasiAvaleheleSignaal();
    void edasiMangulaualeSignaal();

private slots:
    void edasi();
    void tagasi();

private:
    Ui::lauavalikSisu *ui;
};

#endif // LAUAVALIKSISU_H
