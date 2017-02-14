#ifndef PATHFINDERHELPER_H
#define PATHFINDERHELPER_H

#include <QtWidgets/QMainWindow>
#include "ui_pathfinderhelper.h"

class PathfinderHelper : public QMainWindow
{
	Q_OBJECT

public:
	PathfinderHelper(QWidget *parent = 0);
	~PathfinderHelper();

private:
	void read();

private:
	Ui::PathfinderHelperClass ui;
};

#endif // PATHFINDERHELPER_H
