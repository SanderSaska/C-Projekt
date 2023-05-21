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
    void eelmineLaud();
    void jargmineLaud();

private:
    Ui::peaAken *ui;
    avalehtSisu* avaleht = nullptr;
    lauavalikSisu* lauavalik = nullptr;
    mangulaudSisu* mangulaud = nullptr;
    int valitudLaudadeArv;
    QList<std::shared_ptr<mangulaudSisu>>::iterator mitmesLaudIterator;
    QList<std::shared_ptr<mangulaudSisu>> mangulauad;
};

#endif // PEAAKEN_H
