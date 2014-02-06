#include "danmakueditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DanmakuEditor w;
    w.show();

    return a.exec();
}
