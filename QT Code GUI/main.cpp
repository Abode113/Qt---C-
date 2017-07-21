#include "dialog.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog *widget = new Dialog;
    widget->show();
    return app.exec();
}
