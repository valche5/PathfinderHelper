#include "pathfinderhelper.h"

#include "WeaponParser.h"

using namespace std;


PathfinderHelper::PathfinderHelper(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	read();
}

PathfinderHelper::~PathfinderHelper() {

}

void PathfinderHelper::read() {
	WeaponParser parser("armes.xml");
	parser.parse();
}
