#ifndef PEAAKEN_H
#define PEAAKEN_H

#include <QMainWindow>
#include "avalehtsisu.h"
#include "lauavaliksisu.h"
#include "mangulaudsisu.h"

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
    void mangulauaSisu();
    void mangulaudadeArv(int arv);

private:
    Ui::peaAken *ui;
    avalehtSisu* avaleht;
    lauavalikSisu* lauavalik;
    mangulaudSisu* mangulaud;
    int valitudLaudadeArv;
};

#endif // PEAAKEN_H
