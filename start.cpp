#include "start.h"
#include <QGridLayout>

DialogStart::DialogStart(QWidget *parent)
    : QDialog(parent)
{
    // 初始化变量
    welcome_message = "Welcome to El Farol Bar simulator/game!";

    // 初始化部件对象指针
    button_simulate = new QPushButton("Simulate");
    button_play = new QPushButton("Play!");
    button_exit = new QPushButton("Exit");

    // Welcome message
    welcome_label = new QLabel(welcome_message);

    // 使用网格布局，还有水平和垂直布局
    QGridLayout *Grid = new QGridLayout;

    // 参数含义:widget部件指针,所在行,所在列,(行宽,列宽,)对齐方式
    Grid->addWidget(welcome_label, 1, 1, 1, 4, Qt::Alignment());
    Grid->addWidget(button_simulate, 7, 2, Qt::Alignment());
    Grid->addWidget(button_play, 9, 2, Qt::Alignment());
    Grid->addWidget(button_exit, 11, 3, Qt::Alignment());

    // 把Grid布局设置给当前创建的对话框对象
    this->setLayout(Grid);

    // 实现连接函数  Connect函数参数 (pushbutton,signal,this指针,slot函数)
    connect(button_simulate, SIGNAL(clicked(bool)), this, SLOT(on_button_simulate_clicked()));
    connect(button_play, SIGNAL(clicked(bool)), this, SLOT(on_button_play_clicked()));
    connect(button_exit, SIGNAL(clicked(bool)), this, SLOT(on_button_exit_clicked()));

}

DialogStart::~DialogStart()
{

}

// 实现槽函数
void DialogStart::on_button_simulate_clicked()
{
    emit change_from_start(START2SIMULATE);
}

void DialogStart::on_button_play_clicked()
{
    emit change_from_start(START2PLAY);
}

void DialogStart::on_button_exit_clicked()
{
    emit change_from_start(EXIT);
}
