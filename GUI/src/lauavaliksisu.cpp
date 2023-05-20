#include "../lib/lauavaliksisu.h"
#include "ui_lauavaliksisu.h"

lauaValikSisu::lauaValikSisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lauaValikSisu)
{
    ui->setupUi(this);

    // Edasi nupp
    QObject::connect(ui->edasiNupp, &QPushButton::clicked, this, &lauaValikSisu::edasi);
    // Tagasi nupp
    QObject::connect(ui->tagasiNupp, &QPushButton::clicked, this, &lauaValikSisu::tagasi);
}

lauaValikSisu::~lauaValikSisu()
{
    delete ui;
}

void lauaValikSisu::tagasi()
{
    emit tagasiAvalehele();
}

void lauaValikSisu::edasi()
{
    // TODO: Implement the functionality for the "edasi" button
}
