#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>

// Pièces : 1000 pc = 100 pa = 10 po = 1 pp
struct Coins {
	int value = 0; //Valeur en pc
	void addPc(int pc) { value += 1 * pc; };
	void addPa(int pa) { value += 10 * pa; };
	void addPo(int po) { value += 100 * po; };
	void addPp(int pp) { value += 1000 * pp; };
};

struct Weight {
	int value = 0; //Valeur en grammes
	void addG(int g) { value += g; };
	void addKG(int kg) { value += 1000 * kg; };
};

struct DiceRoll {
	int DiceCount = 1;
	int DiceValue = 6;
};

struct Ammunition {
	QString	name;
	int		quantity;
	Coins	value;
	Weight	weight;
};

struct DammageType {
	bool choice; //Tous les types ou un des types au choix
	bool C, P, T;
};

struct Weapon {
	enum Category {
		Courante,
		Guerre,
		Exotique
	};
	QString		name;
	Category	category;

	bool		cac;
	bool		ranged; //A distance
	bool		small; //Légère
	int			hands;

	Coins		cost;
	DiceRoll	dammageP;
	DiceRoll	dammageM;

	int			criticalHitMinValue;
	int			criticalHitMaxValue;
	int			criticalHitMultiplier;
	int			range; //Portée en mètres
	Weight		weight;
	DammageType	dammageType;

	QString		special;
};

#endif // EQUIPEMENT_H
