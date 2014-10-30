#ifndef VISUALACUITYTESTFORM_H
#define VISUALACUITYTESTFORM_H

#include <QWidget>
#include "ui_visualacuitytestform.h"

class VisualAcuityTestForm : public QWidget
{
	Q_OBJECT

public:
	VisualAcuityTestForm(QWidget *parent = 0);
	~VisualAcuityTestForm();

private:
	Ui::VisualAcuityTestForm ui;
};

#endif // VISUALACUITYTESTFORM_H
