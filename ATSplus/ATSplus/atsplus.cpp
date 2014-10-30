#include "atsplus.h"

#include "VisualAcuityTest.h"

ATSplus::ATSplus(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionAcuity_Test, SIGNAL(triggered(bool)), this, SLOT(openWindow()));

}

ATSplus::~ATSplus()
{

}


void ATSplus::openWindow()
{
	VisualAcuityTest* oglwindow = new VisualAcuityTest();

	oglwindow->show();
}