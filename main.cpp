#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    Widget w;
    w.setWindowTitle(QObject::tr("Boogle"));
    w.setWindowIcon(QIcon(":/images/images/Logo.png"));
    w.show();

    return a.exec();
}
