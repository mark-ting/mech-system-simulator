#include "mechsystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MechSystem w;
	w.show();
	return a.exec();
}