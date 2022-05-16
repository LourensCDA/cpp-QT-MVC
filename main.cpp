#include <QApplication>
#include "musicview.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    musicview w;

    // Event loop
    return app.exec();
}
