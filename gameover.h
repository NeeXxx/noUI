#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent);
    void setLoser(int loser);
    void paintEvent(QPaintEvent*);
    ~gameOver();

private:
    Ui::gameOver *ui;
    int winner;
    QString filename;
};

#endif // GAMEOVER_H
