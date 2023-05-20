#include "../lib/avalehtsisu.h"
#include "ui_avalehtsisu.h"

avalehtSisu::avalehtSisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::avalehtSisu)
{
    ui->setupUi(this);

    // Väljumise nupp
    QObject::connect(ui->valjuNupp, &QPushButton::clicked, this, &avalehtSisu::valju);
    // Mängimise nupp
    QObject::connect(ui->mangiNupp, &QPushButton::clicked, this, &avalehtSisu::mangi);
}

avalehtSisu::~avalehtSisu()
{
    delete ui;
}

void avalehtSisu::valju()
{
    QApplication::quit();
}

void avalehtSisu::mangi()
{
    emit edasiLauaValikule();
}
