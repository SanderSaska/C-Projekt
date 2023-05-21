#include "../lib/peaAken.h"
#include "../lib/avalehtsisu.h"
#include "../lib/lauavaliksisu.h"
#include "../lib/mangulaudsisu.h"
#include "ui_peaAken.h"
#include <QDebug>

peaAken::peaAken(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peaAken)
{
    std::srand(time(NULL));

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
        for (int i = 0; i < valitudLaudadeArv; ++i) {
            std::shared_ptr<mangulaudSisu> laud = std::make_shared<mangulaudSisu>(this);
            QObject::connect(laud.get(), &mangulaudSisu::liiguVasakuleLaualeSignaal, this, &peaAken::eelmineLaud);
            QObject::connect(laud.get(), &mangulaudSisu::liiguParemaleLaualeSignaal, this, &peaAken::jargmineLaud);
            mangulauad.append(std::move(laud));
            qDebug() << "Tehtud laud: " << i;
        }
        mitmesLaudIterator = mangulauad.begin();
        mangulaud = mitmesLaudIterator->get();
    }

    setCentralWidget(mangulaud);
}

void peaAken::mangulaudadeArv(int arv) {
    valitudLaudadeArv = arv + 1;
    qDebug() << "Valitud arv: " << valitudLaudadeArv;
}

void peaAken::jargmineLaud() {
    ++mitmesLaudIterator;
    if (mitmesLaudIterator == mangulauad.end()) {
        mitmesLaudIterator = mangulauad.begin();
    }
    qDebug() << "Järgmine laud: " << std::distance(mangulauad.begin(), mitmesLaudIterator);
    mangulaud = mitmesLaudIterator->get();
    setCentralWidget(mangulaud);
}

void peaAken::eelmineLaud() {
    if (mitmesLaudIterator == mangulauad.begin()) {
        mitmesLaudIterator = mangulauad.end() - 1;
    }
    else {
        --mitmesLaudIterator;
    }
    qDebug() << "Eelmine laud: " << std::distance(mangulauad.begin(), mitmesLaudIterator);
    mangulaud = mitmesLaudIterator->get();
    setCentralWidget(mangulaud);
}
