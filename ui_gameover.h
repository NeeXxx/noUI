/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_gameOver
{
public:

    void setupUi(QDialog *gameOver)
    {
        if (gameOver->objectName().isEmpty())
            gameOver->setObjectName(QStringLiteral("gameOver"));
        gameOver->resize(400, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameOver->sizePolicy().hasHeightForWidth());
        gameOver->setSizePolicy(sizePolicy);
        gameOver->setMinimumSize(QSize(400, 250));
        gameOver->setMaximumSize(QSize(400, 250));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        gameOver->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        gameOver->setWindowIcon(icon);

        retranslateUi(gameOver);

        QMetaObject::connectSlotsByName(gameOver);
    } // setupUi

    void retranslateUi(QDialog *gameOver)
    {
        gameOver->setWindowTitle(QApplication::translate("gameOver", "\346\270\270\346\210\217\347\273\223\346\235\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameOver: public Ui_gameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
