#include "gameover.h"
#include "ui_gameover.h"
#include <QPixmap>
#include <QPainter>

gameOver::gameOver(QWidget *parent) :
    ui(new Ui::gameOver),
    QDialog(parent)
{
    ui->setupUi(this);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QColor(255,255,255)));
    this->setPalette(p);
    this->setAutoFillBackground(true);
    this->setMinimumSize(400,200);
    this->setMaximumSize(400,200);
}

gameOver::~gameOver()
{
    delete ui;

}

void gameOver::setLoser(int loser)
{
    if (loser==1)
        filename="player2.png";
    else
        filename="player1.png";
}

void gameOver::paintEvent(QPaintEvent *)
{
    QPixmap endImg;
    QPainter painter(this);
    QString fullName=":/images/images/"+filename;
    endImg.load(":/images/images/over.png");
    painter.drawPixmap(0,0, endImg);
    endImg.load(fullName);
    painter.drawPixmap(80,80, endImg);
}
