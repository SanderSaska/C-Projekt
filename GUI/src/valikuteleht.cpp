#include "../lib/valikuteleht.h"
#include "ui_valikuteleht.h"

ValikuteLeht::ValikuteLeht(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ValikuteLeht)
{
    ui->setupUi(this);
}

ValikuteLeht::~ValikuteLeht()
{
    delete ui;
}
