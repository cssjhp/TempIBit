#ifndef ATSPLUS_H
#define ATSPLUS_H

#include <QtWidgets/QMainWindow>
#include "ui_atsplus.h"

class ATSplus : public QMainWindow
{
	Q_OBJECT

public:
	ATSplus(QWidget *parent = 0);
	~ATSplus();


public slots:
	void openWindow();

private:
	Ui::ATSplusClass ui;
};

#endif // ATSPLUS_H
