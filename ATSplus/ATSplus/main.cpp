#include "atsplus.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ATSplus w;
	w.show();
	return a.exec();
}
