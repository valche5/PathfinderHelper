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
	while (!reader.atEnd()) {
		if (reader.readNext() == QXmlStreamReader::StartElement) {
			if (reader.name() == "Arme") {
				if (!parseWeapons()) return false;
			}
		}
	}
	if (reader.hasError()) {
		std::cout << qPrintable(reader.errorString()) << std::endl;
	}

	return true;
}

bool WeaponParser::parseWeapons() {
	//while (!reader.atEnd()) {
	//	if (reader.readNext() == QXmlStreamReader::StartElement)
	//		if (reader.name == "Nom") {
	//		} else if (reader.name == "Catégorie")
	//		cout << reader.name().toString().toStdString() << endl;
	//		break;
	//	case QXmlStreamReader::Characters:
	//		if (!reader.isWhitespace()) {
	//			cout << "Texte : " << reader.text().toString().toStdString() << endl;
	//		}
	//		break;
	//	}
	//}
	
	return false;
}
