#ifndef MANGULAUD_H
#define MANGULAUD_H

#include <QWidget>

namespace Ui {
class mangulaudSisu;
}

class mangulaudSisu : public QWidget
{
    Q_OBJECT

public:
    explicit mangulaudSisu(QWidget *parent = nullptr);
    ~mangulaudSisu();

private:
    Ui::mangulaudSisu *ui;
};

#endif // MANGULAUD_H
