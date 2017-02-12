#include "pathfinderhelper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PathfinderHelper w;
	w.show();
	return a.exec();
}
