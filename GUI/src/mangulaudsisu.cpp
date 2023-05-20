#include "../lib/mangulaudsisu.h"
#include "ui_mangulaudsisu.h"

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

    for (QPushButton* nupp : nupud){
        connect(nupp, &QPushButton::clicked, this, &mangulaudSisu::kaiguTegemine);
    }
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
    }
}
