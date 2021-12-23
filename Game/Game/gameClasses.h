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
		cout << "��� �������� � ������ ���������" << endl << "��� ���� ����� ������?\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "������ ���� ���� - " << damage << endl;
	}
	void getWeapons() {
		cout << "������ � ���� ���� " << weapons << endl;
	}
	~Soldier() {
		if (soldier)
			cout << "������ " << name << " ����� �� ����������" << endl;
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
		cout << "���� ������ ���� ����������" << endl << "������ ���� ������ �����\t";
		cin >> name;
		cout << endl;
		getStats();
		cout << "������ ���� ���� - " << damage << endl;
	}

	~KriegWarrior() {
		if (kriegwarrior)
			cout << "������ ����� " << name << " ���� �� ����������" << endl;
	}
};
