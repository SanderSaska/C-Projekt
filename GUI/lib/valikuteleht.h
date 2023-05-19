#ifndef VALIKUTELEHT_H
#define VALIKUTELEHT_H

#include <QWidget>

namespace Ui {
class ValikuteLeht;
}

class ValikuteLeht : public QWidget
{
    Q_OBJECT

public:
    explicit ValikuteLeht(QWidget *parent = nullptr);
    ~ValikuteLeht();

private:
    Ui::ValikuteLeht *ui;
};

#endif // VALIKUTELEHT_H
