#include "src/Notepad/Notepad.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto * w = new Notepad();
    w->show();
    QString styleSheet("QWidget { font-family:");
    styleSheet.append(w->getFontCfg()[0]);
    styleSheet.append(";\nfont-size:");
    styleSheet.append(w->getFontCfg()[1]);
    styleSheet.append("px;");
    styleSheet.append("}");
    a.setStyleSheet(styleSheet);
    return QApplication::exec();
}
