#ifndef PEAAKEN_H
#define PEAAKEN_H

#include <QMainWindow>
#include "avalehtsisu.h"
#include "lauavaliksisu.h"

namespace Ui {
class peaAken;
}

class peaAken : public QMainWindow
{
    Q_OBJECT

public:
    explicit peaAken(QWidget *parent = nullptr);
    ~peaAken();

public slots:
    void avaleheSisu();
    void lauavalikuSisu();
    void edasiLauaValikule();

private:
    Ui::peaAken *ui;
    avalehtSisu* avaleht;
    lauaValikSisu* lauavalik;
};

#endif // PEAAKEN_H
