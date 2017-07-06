#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b=new  board;
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(b);
    setLayout(layout);

    resize(900,900);
}

Widget::~Widget()
{

}
