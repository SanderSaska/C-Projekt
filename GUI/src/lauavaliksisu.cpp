#include "../lib/lauavaliksisu.h"
#include "ui_lauavaliksisu.h"

lauavalikSisu::lauavalikSisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lauavalikSisu)
{
    ui->setupUi(this);

    // Edasi nupp
    QObject::connect(ui->edasiNupp, &QPushButton::clicked, this, &lauavalikSisu::edasi);
    // Tagasi nupp
    QObject::connect(ui->tagasiNupp, &QPushButton::clicked, this, &lauavalikSisu::tagasi);
    // ComboBox
    QObject::connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &lauavalikSisu::valik);
}

lauavalikSisu::~lauavalikSisu()
{
    delete ui;
}

void lauavalikSisu::tagasi()
{
    emit tagasiAvaleheleSignaal();
}

void lauavalikSisu::edasi()
{
    emit edasiMangulaualeSignaal();
}

void lauavalikSisu::valik(int i) {
    int valitudArv = i;
    emit valitudLaudadeArvMuudetud(valitudArv);
}