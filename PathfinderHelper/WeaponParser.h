#ifndef WEAPONPARSER_H
#define WEAPONPARSER_H

#include "Containers.h"
#include <QXmlStreamReader>
#include <QFile>

class WeaponParser {
public:
	WeaponParser(const QString &filename);
	bool parse();
private:
	bool parseWeapons();
private:
	QXmlStreamReader reader;
	Weapons weapons;
	QFile xmlFile;
};

#endif // WEAPONPARSER_H
