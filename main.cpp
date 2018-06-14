#include "dialog_control.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogControl w;
    w.run();

    return a.exec();
}
