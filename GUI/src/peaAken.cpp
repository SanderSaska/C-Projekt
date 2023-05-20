#include "../lib/peaAken.h"
#include "../lib/avalehtsisu.h"
#include "../lib/lauavaliksisu.h"
#include "../lib/mangulaudsisu.h"
#include "ui_peaAken.h"
#include <QDebug>

peaAken::peaAken(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peaAken),
    avaleht(nullptr),
    lauavalik(nullptr),
    mangulaud(nullptr)
{
    ui->setupUi(this);

    setFixedSize(640, 480);

    avaleheSisu();

    QObject::connect(ui->actionV_lju, &QAction::triggered, this, &peaAken::close);
}

peaAken::~peaAken()
{
    delete ui;
}

void peaAken::avaleheSisu()
{
    if (lauavalik)
    {
        delete lauavalik;
        lauavalik = nullptr;
    }

    if (!avaleht)
    {
        avaleht = new avalehtSisu(this);
        QObject::connect(avaleht, &avalehtSisu::edasiLauaValikuleSignaal, this, &peaAken::lauavalikuSisu);
    }
    setCentralWidget(avaleht);
}

void peaAken::lauavalikuSisu()
{
    if (avaleht)
    {
        delete avaleht;
        avaleht = nullptr;
    }

    if (!lauavalik)
    {
        lauavalik = new lauavalikSisu(this);
        QObject::connect(lauavalik, &lauavalikSisu::tagasiAvaleheleSignaal, this, &peaAken::avaleheSisu);
        QObject::connect(lauavalik, &lauavalikSisu::edasiMangulaualeSignaal, this, &peaAken::mangulauaSisu);
        QObject::connect(lauavalik, &lauavalikSisu::valitudLaudadeArvMuudetud, this, &peaAken::mangulaudadeArv);
        mangulaudadeArv(0);
    }

    setCentralWidget(lauavalik);
}

void peaAken::mangulauaSisu(){
    if (lauavalik){
        delete lauavalik;
        lauavalik = nullptr;
    }

    if (!mangulaud){
        mangulaud = new mangulaudSisu(this);
    }

    setCentralWidget(mangulaud);
}

void peaAken::mangulaudadeArv(int arv) {
    valitudLaudadeArv = arv;
    qDebug() << "Valitud arv: " << valitudLaudadeArv;
}