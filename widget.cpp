#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b=new  board;
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(b);
    setLayout(layout);

    resize(1200,800);
}

Widget::~Widget()
{

}
