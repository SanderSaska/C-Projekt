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

private slots:
    void kaiguTegemine();

private:
    Ui::mangulaudSisu *ui;
    QList<QPushButton*> nupud; // Mängulaual olevad võimalikud käigud
};

#endif // MANGULAUD_H
