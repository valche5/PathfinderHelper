#ifndef WEAPONPARSER_H
#define WEAPONPARSER_H

#include "Containers.h"
#include <QXmlStreamReader>

class WeaponParser {
public:
	WeaponParser(const QString &filename);
	bool parse();
private:
	bool parseWeapons();

private:
	QXmlStreamReader reader;
	Weapons weapons;
};

#endif // WEAPONPARSER_H
