#ifndef DIALOG_CONTROL_H
#define DIALOG_CONTROL_H

#include "start.h"
#include "simulate.h"
#include "play.h"

class DialogControl : public QObject
{
    Q_OBJECT

public:
    DialogControl();
    ~DialogControl();

    void run();
    void restart(int);

protected:
    DialogStart *start;
    DialogSimulate *simulate;
    DialogPlay *play;

private slots:
    void change_dialog(int);

};

#endif // DIALOG_CONTROL_H
