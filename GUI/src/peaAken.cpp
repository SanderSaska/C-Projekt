#include "../lib/peaAken.h"
#include "../lib/avalehtsisu.h"
#include "../lib/lauavaliksisu.h"
#include "ui_peaAken.h"

peaAken::peaAken(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peaAken),
    avaleht(nullptr),
    lauavalik(nullptr)
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
        QObject::connect(avaleht, &avalehtSisu::edasiLauaValikule, this, &peaAken::edasiLauaValikule);
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
        lauavalik = new lauaValikSisu(this);
        QObject::connect(lauavalik, &lauaValikSisu::tagasiAvalehele, this, &peaAken::avaleheSisu);
    }

    setCentralWidget(lauavalik);
}

void peaAken::edasiLauaValikule()
{
    lauavalikuSisu();
}
