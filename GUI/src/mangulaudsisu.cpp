#include "../lib/mangulaudsisu.h"
#include "ui_mangulaudsisu.h"

mangulaudSisu::mangulaudSisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mangulaudSisu)
{
    ui->setupUi(this);
}

mangulaudSisu::~mangulaudSisu()
{
    delete ui;
}
