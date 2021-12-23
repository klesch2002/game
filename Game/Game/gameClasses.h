#pragma once
#include "baseClasses.h"

class Soldier : virtual public Npc {
protected:
	int strange;
	string weapons;
public:
	Soldier() {
		soldier = true;
		kriegwarrior = false;
		health = 50;
		damage = 30;
		armor = 30;
	}
	void create() override {
		cout << endl;
		cout << "Вас призвали в войска Империума" << endl << "Как тебя зовут солдат?\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "Сейчас твоя сила - " << damage << endl;
	}
	void getWeapons() {
		cout << "Теперь у тебя есть " << weapons << endl;
	}
	~Soldier() {
		if (soldier)
			cout << "Солдат " << name << " погиб за Императора" << endl;
	}
};

class KriegWarrior : virtual public Npc {
protected:
	int strange;
	string weapons;
public:
	KriegWarrior() {
		soldier = false;
		kriegwarrior = true;
		health = 40;
		damage = 55;
		armor = 20;
	}
	void create() override {
		cout << endl;
		cout << "Пора отдать долг Императору" << endl << "Назови свой личный номер\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "Сейчас твоя сила - " << damage << endl;
	}

	~KriegWarrior() {
		if (kriegwarrior)
			cout << "Солдат Крига " << name << " умер за Императора" << endl;
	}
};
