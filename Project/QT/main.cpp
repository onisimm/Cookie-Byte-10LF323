#include "TwixtGame.h"
#include "mainwindow.h"
#include <QApplication>

//int main()
//{
//	TwixtGame game;
//	game.Run();
//	return 0;
//}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
