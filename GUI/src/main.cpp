#include "../lib/peaAken.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    peaAken w;
    w.show();
    return a.exec();
}
