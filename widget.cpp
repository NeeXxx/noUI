#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b=new  board;
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(b);
    setLayout(layout);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QColor(255,255,255)));
    this->setPalette(p);
    this->setAutoFillBackground(true);
    this->setMinimumSize(1200,762);
    this->setMaximumSize(1200,762);
}

Widget::~Widget()
{

}
