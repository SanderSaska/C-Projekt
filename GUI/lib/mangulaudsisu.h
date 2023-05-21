#ifndef MANGULAUD_H
#define MANGULAUD_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class mangulaudSisu;
}

class mangulaudSisu : public QWidget
{
    Q_OBJECT

public:
    explicit mangulaudSisu(QWidget *parent = nullptr);
    ~mangulaudSisu();
    bool kaikVoetud(int index) const;
    bool voit();
    QList<int> getKoikKaigud();

signals:
    void liiguVasakuleLaualeSignaal();
    void liiguParemaleLaualeSignaal();

private slots:
    void vasakule();
    void paremale();
    void kaiguTegemine();
    void teeKaik();
    void nupudKinni();
    int getRate(QList<int> nupud);
    bool laudLabi(QList<int> nupud);
    bool voiduVoimalus(QList<int> nupud);

private:
    Ui::mangulaudSisu *ui;
    QList<QPushButton*> nupud; // Mängulaual olevad võimalikud käigud
    QList<std::string> mangijad = {"mängija", "AI"};
    int mangukord = 1;
};

#endif // MANGULAUD_H
