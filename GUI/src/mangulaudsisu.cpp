#include "../lib/mangulaudsisu.h"
#include "ui_mangulaudsisu.h"
#include <string>
#include <algorithm>

mangulaudSisu::mangulaudSisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mangulaudSisu)
{
    ui->setupUi(this);

    // Nuppude lisamine vektorisse
    for (int i = 0; i < 9; ++i) {
        QString nupuNimi = QString("pushButton_%1").arg(i);
        nupud.append(findChild<QPushButton*>(nupuNimi));
    }
    // Käigunupud
    for (QPushButton* nupp : nupud){
        connect(nupp, &QPushButton::clicked, this, &mangulaudSisu::kaiguTegemine);
    }
    // Vasakule nupp
    QObject::connect(ui->eelmineLaudNupp, &QPushButton::clicked, this, &mangulaudSisu::vasakule);
    // Paremale nupp
    QObject::connect(ui->jargmineLaudNupp, &QPushButton::clicked, this, &mangulaudSisu::paremale);
}

mangulaudSisu::~mangulaudSisu()
{
    delete ui;
}

void mangulaudSisu::kaiguTegemine()
{
    QPushButton* nupp = qobject_cast<QPushButton*>(sender());
    if (nupp){
        nupp->setDisabled(true);
        nupp->setText("X");
        if (laudLabi(getKoikKaigud())){
            nupudKinni();
            return;
        }
        teeKaik();
    }
}

void mangulaudSisu::vasakule() {
    emit liiguVasakuleLaualeSignaal();
}

void mangulaudSisu::paremale() {
    emit liiguParemaleLaualeSignaal();
}

QList<int> mangulaudSisu::getKoikKaigud() {
    auto n = nupud.size();
    QList<int> kaigud;
    for (int i = 0; i < n; ++i) {
        if (nupud[i]->isEnabled()){
            kaigud.append(i);
        }
    }
    return kaigud;
}

bool mangulaudSisu::kaikVoetud(int index) const {
    if (index >= 0 && index < nupud.size()){
        QPushButton* nupp = nupud[index];
        return !nupp->isEnabled();
    }
    return true;
}

void mangulaudSisu::nupudKinni() {
    for (const auto &nupp: nupud){
        nupp->setEnabled(false);
    }
    std::string tekst = "Laud surnud. Võitis " + mangijad[mangukord];
    ui->kirjeldus->setText(QString::fromStdString(tekst));
    ui->kirjeldus->setAlignment(Qt::AlignCenter);
}

void mangulaudSisu::teeKaik() {
    ui->kirjeldus->setText("AI kord");
    ui->kirjeldus->setAlignment(Qt::AlignCenter);
    mangukord -= 1; // Võidab mängija
    int parimRate = 0;
    QList<int> parimadKaigud;
    QList<int> voimalikudKaigud = getKoikKaigud();
    for (const auto &kaik: voimalikudKaigud){
        QList<int> valikud = getKoikKaigud();
        valikud.removeAll(kaik);
        int rate = getRate(valikud);
        if (rate > parimRate) { // Kas hinnang on parem kui eelmine
            parimadKaigud.clear(); // Kustutame eelnevad parimad käigud
            parimRate = rate; // Salvestame parema hinnangu
        }
        if (rate == parimRate) { // Kui hinnang on sama
            parimadKaigud.push_back(kaik);
        }
        valikud.clear();
    }
    int valik = rand() % parimadKaigud.size();
    nupud[parimadKaigud[valik]]->setEnabled(false);
    nupud[parimadKaigud[valik]]->setText("X");
    ui->kirjeldus->setText("Sinu kord");
    ui->kirjeldus->setAlignment(Qt::AlignCenter);
    if (laudLabi(getKoikKaigud())){
        nupudKinni();
    }
    mangukord += 1; // Võidab AI
}

bool mangulaudSisu::laudLabi(QList<int> nupud) {
    // Vaata ridu
    for (int i = 0; i < 6; i+=3) {
        if (!nupud.contains(i) && !nupud.contains(i+1) && !nupud.contains(i+2)){
            return true;
        }
    }
    // Vaata tulpasid
    for (int i = 0; i < 3; ++i) {
        if (!nupud.contains(i) && !nupud.contains(i+3) && !nupud.contains(i+6)){
            return true;
        }
    }
    // Vaata peadiagonaali
    if (!nupud.contains(0) && !nupud.contains(4) && !nupud.contains(8)){
        return true;
    }
    // Vaata kõrvaldiagonaali
    if (!nupud.contains(2) && !nupud.contains(4) && !nupud.contains(6)){
        return true;
    }
    return false;
}

int mangulaudSisu::getRate(QList<int> nupud) {
    int rate = 2;
    if (laudLabi(nupud)) { // Kui tehtud käiguga saab kolm ritta
        rate = 1; // Siis on kaotus
        return rate;
    }
    if (voiduVoimalus(nupud)) { // Kui tehtud käiguga saab kaks ritta
        rate = 3; // Siis on vastane ühe käigu kaugusel kaotusest
        return rate;
    }
    return rate;
}

bool mangulaudSisu::voiduVoimalus(QList<int> nupud) {
    // Vaata ridu
    for (int i = 0; i < 6; i+=3) {
        for (int j = 0; j < 2; ++j) {
            if (!nupud.contains(i+j) && !nupud.contains(i+j+1)){
                return true;
            }
        }
    }
    // Vaata tulpasid
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 1; ++j) {
            if (!nupud.contains(i+(3*j)) && !nupud.contains(i+3+(3*j))){
                return true;
            }
        }
    }
    // Vaata peadiagonaali
    for (int i = 0; i < 2; ++i) {
        if (!nupud.contains(4*i) && !nupud.contains(4*(i+1))) {
            return true;
        }
    }
    // Vaata kõrvaldiagonaali
    for (int i = 2; i < 6; i+=2) {
        if (!nupud.contains(i) && !nupud.contains(i+2)){
            return true;
        }
    }
    return false;
}
