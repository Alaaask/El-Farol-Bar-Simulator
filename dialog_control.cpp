#include "dialog_control.h"

DialogControl::DialogControl()
{
    start = new DialogStart;
    simulate = new DialogSimulate;
    play = new DialogPlay;

    connect(start, SIGNAL(change_from_start(int)), this, SLOT(change_dialog(int)));
    connect(simulate, SIGNAL(change_from_simulate(int)), this, SLOT(change_dialog(int)));
    connect(play, SIGNAL(change_from_play(int)), this, SLOT(change_dialog(int)));

}

DialogControl::~DialogControl()
{

}

void DialogControl::run()
{
    start->show();
}

void DialogControl::restart(int signal)
{
    if (signal == SIMULATE2START) {
        simulate->restart();
    }

    else if (signal == PLAY2START) {
        play->restart();
    }

}

void DialogControl::change_dialog(int signal)
{
    if (signal == START2SIMULATE) {
        start->done(0);
        simulate->show();
    }

    else if (signal == START2PLAY) {
        start->done(0);
        play->show();
    }

    else if (signal == SIMULATE2START) {
        simulate->done(0);
        start->show();
    }

    else if (signal == PLAY2START) {
        play->done(0);
        start->show();
    }

    else if (signal == EXIT) {
        start->done(0);
    }
    // 模式转换，清空垃圾
    restart(signal);
}
