#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <array>
#include <unordered_map>
#include <QString>
#include <QStringList>

// Pièces : 1000 pc = 100 pa = 10 po = 1 pp
struct Coins {
	int value; //Valeur en pc
	QString valueString;
	void addPc(int pc) { value += 1 * pc; };
	void addPa(int pa) { value += 10 * pa; };
	void addPo(int po) { value += 100 * po; };
	void addPp(int pp) { value += 1000 * pp; };
	void setValue(int val, QString devise) {
		if (devise == "pp") {
			value += 1000 * val;
		} else if (devise == "po") {
			value += 100 * val;
		} else if (devise == "pa") {
			value += 10 * val;
		} else if (devise == "pc") {
			value += 1 * val;
		}
		valueString = QString::number(val) + devise;
	}
	void setValue(QString valueString) {
		QString devise = valueString.right(2);
		int val = valueString.left(valueString.size() - 2).toInt();
		setValue(val, devise);
	}
};

struct Weight {
	int value = 0; //Valeur en grammes
	QString valueString;
	void addG(int g) { value += g; };
	void addKG(int kg) { value += 1000 * kg; };
	void setValue(const QString &valueStr) {
		valueString = valueStr;
		QRegExp rx("(\\d+)(?:\\s*)(g|kg)");
		int pos = rx.indexIn(valueStr);
		if (rx.cap(2) == "g")
			addG(rx.cap(1).toInt());
		else if (rx.cap(2) == "kg")
			addKG(rx.cap(1).toInt());
	}
};

struct DiceRoll {
	int diceCount = 1;
	int diceValue = 6;
	int bonusValue = 0;
	QString valueString;

	void setValue(const QString &valueStr) {
		QStringList l = valueStr.split("d");
		diceCount = l.at(0).toInt();
		QStringList ll = valueStr.split("+");
		if (ll.size() == 1) {
			diceValue = ll.at(0).toInt();
			bonusValue = 0;
		} else {
			diceValue = ll.at(0).toInt();
			bonusValue = ll.at(1).toInt();
		}
		valueString = valueStr;
	}
};

struct Ammunition {
	QString	name;
	int		quantity;
	Coins	value;
	Weight	weight;
};

struct WeaponType {
	bool choice; //Tous les types ou un des types au choix
	bool C = false, P = false, T = false;
	QString valueString;
	void setValue(const QString &valueStr) {
		valueString = valueStr;
		if (valueStr.size() == 1) {
			choice = false;
			activateType(valueStr.leftRef(1));
		} else {
			activateType(valueStr.leftRef(1));
			activateType(valueStr.rightRef(1));
			choice = (valueStr.contains("ou")) ? true : false;
		}
	}
private:
	void activateType(const QStringRef &type) {
		if (type == "C") {
			C = true;
		} else if (type == "P") {
			P = true;
		} else if (type == "T") {
			T = true;
		}
	}
};

struct Dammage {
	bool		isDouble;

	QString		valueStringP;
	DiceRoll	leftP;
	DiceRoll	rightP;
	QString		valueStringM;
	DiceRoll	leftM;
	DiceRoll	rightM;

	void setPValue(const QString &dammageStr) {
		valueStringP = dammageStr;
		QStringList list = dammageStr.split("/");
		if (list.size() == 1) {
			isDouble = false;
			leftP.setValue(list.at(0));
			rightP = leftP;
		} else {
			isDouble = true;
			leftP.setValue(list.at(0));
			rightP.setValue(list.at(1));
		}
	}

	void setMValue(const QString &dammageStr) {
		valueStringM = dammageStr;
		QStringList list = dammageStr.split("/");
		if (list.size() == 1) {
			isDouble = false;
			leftM.setValue(list.at(0));
			rightM = leftM;
		} else {
			isDouble = true;
			leftM.setValue(list.at(0));
			rightM.setValue(list.at(1));
		}
	}
};

struct Critical {
	int minValue, maxValue, multiplier;
	QString valueString;
	void setValue(const QString &valueStr) {
		multiplier = valueStr.rightRef(1).toInt();
		if (valueStr.contains("/")) {
			minValue = valueStr.leftRef(2).toInt();
			maxValue = valueStr.midRef(3, 2).toInt();
		} else {
			minValue = 20;
			maxValue = 20;
		}
		valueString = valueStr;
	}
};

struct Distance {
	int value; // in m
	QString valueString;
	void setValue(QString valueStr) {
		valueString = valueStr;
		QRegExp rx("(\\d+)(?:\\s*)(m|km)");
		int pos = rx.indexIn(valueStr);
		if (rx.cap(2) == "m")
			value = rx.cap(1).toInt();
		else if (rx.cap(2) == "km")
			value = rx.cap(1).toInt() * 1000;
	}
};

struct Weapon {
	QString		name;
	QString		category;
	QString		subCategory;

	bool		hasCost;
	Coins		cost;
	
	Dammage		dammages;

	Critical	critical;

	bool		isRanged;
	Distance	range; //Portée

	Weight		weight;
	WeaponType	type;

	bool		hasSpecial;
	QStringList special;
};

#endif // EQUIPEMENT_H
