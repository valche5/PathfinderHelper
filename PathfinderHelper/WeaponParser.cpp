#include "WeaponParser.h"

#include <QFile>
#include <QXmlStreamReader>
#include <iostream>

using namespace std;

WeaponParser::WeaponParser(const QString & filename) {
	xmlFile.setFileName(filename);
	if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		std::cout << "Can't open file" << std::endl;
	}
	
	reader.setDevice(&xmlFile);
}

bool WeaponParser::parse() {
	if (reader.readNextStartElement()) {
		if (reader.name() == "Armes") {
			return parseWeapons();
		} else {
			return false;
		}
	} else  {
		std::cout << qPrintable(reader.errorString()) << std::endl;
		return false;
	}

	return true;
}

bool WeaponParser::parseWeapons() {
	while (reader.readNextStartElement()) {
		if (reader.name() == "Arme") {
			return parseWeapon();
		} else {
			return false;
		}
	}
	if (reader.hasError()) {
		cout << qPrintable(reader.errorString()) << endl;
		return false;
	}

	return true;
}

bool WeaponParser::parseWeapon() {
	Weapon w;
	//Parsing Name
	if (reader.readNextStartElement() && reader.name() == u8"Nom") {
		w.name = reader.readElementText();
	} else {
		return false;
	}

	//Parsing category
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Catégorie") {
			w.category = reader.readElementText();
		}
	} else {
		return false;
	}

	//Parsing SubCategory
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"SousCatégorie") {
			w.subCategory = reader.readElementText();
		}
	} else {
		return false;
	}

	//Parsing Price
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Prix") {
			QString text = reader.readElementText();
			if (text.isEmpty()) {
				w.hasCost = false;
			} else {
				w.hasCost = true;
				w.cost.setValue(text);
			}
		}
	} else {
		return false;
	}

	//Parsing DammageP
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"DégatsP") {
			w.dammages.setPValue(reader.readElementText());
		}
	} else {
		return false;
	}

	//Parsing DammageM
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"DégatsM") {
			w.dammages.setMValue(reader.readElementText());
		}
	} else {
		return false;
	}

	//Parsing Critical
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Critique") {
			w.critical.setValue(reader.readElementText());
		}
	} else {
		return false;
	}

	//Parsing Range
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Portée") {
			QString text = reader.readElementText();
			if (text.isEmpty()) {
				w.isRanged = false;
				w.range.value = 0;
			} else {
				w.isRanged = true;
				w.range.setValue(text);
			}
		}
	} else {
		return false;
	}

	//Parsing Weight
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Poids") {
			w.range.setValue(reader.readElementText());
		}
	} else {
		return false;
	}

	//Parsing Type
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Type") {
			w.type.setValue(reader.readElementText());
		}
	} else {
		return false;
	}

	//Parsing Spécial
	if (reader.readNextStartElement()) {
		if (reader.name() == u8"Spécial") {
			w.special = reader.readElementText().split(", ");
			w.hasSpecial = (w.special.length() > 0) ? true : false;
		}
	} else {
		return false;
	}

	weapons.weapons.push_back(w);

	return true;
}
