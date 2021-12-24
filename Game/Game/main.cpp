#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#include "baseClasses.h"
#include "evil.h"
#include "gameClasses.h"
#include <fstream> 
#include <string> 

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string patch = "Save.txt";
	Soldier soldier;
	KriegWarrior kriegwarrior;
	Player firstPlayer;
	fstream saven;
	saven.open(patch);
	saven << soldier.getHealth();
	saven << soldier.getDamage();
	saven.close();
	cout << soldier.getHealth();
	cout << soldier.getDamage();
	cout << "� ��� � ������������\n ������ ��� ��������� � �������" << endl;
	cout << "��� ��?" << endl;
	cout << "1 - ������\n2 - ���� �����" << endl;
	int choise;
	cin >> choise;
	switch (choise) {
	case 1:
	{
		firstPlayer.create(&soldier);
		soldier.getWeapons();
		break;
	}
	case 2:
	{
		firstPlayer.create(&kriegwarrior);
		break;
	}
	}
	cout << "� � ����� �� ��������� ��� ���������" << endl;
	cout << "1 - ������ ������\n2 - ������" << endl;
	int ways;
	int i = 1;
	cin >> ways;
	srand(time(NULL));
	int chance;
	int randHealth = rand() % 15 + 1; 
	int randDamage = rand() % 15 + 1;
	Evil evil1("���", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 
	Evil evil2("�������", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 
	Evil evil3("�����", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 

	switch (ways) {
	case 1: {
		cout << "��� �������������\n�������� ����������..." << endl;
		for (int i = 1; i < 4; i++) {
			Sleep(1000);
			cout << "�� ������� " << 33*i << "����" << endl;
			if (i == 1) {
				evil1.getStats();
			}
			if (i == 2) {
				evil2.getStats();
			}
			if (i == 3) {
				evil3.getStats();
			}
			cout << "��� ������ ������?" << endl;
			cout << "1 - �������� � ����� �� ����� \n2 - �������\n3 - ��������� ��������� � ����� � ���" << endl;
			int battle;
			cin >> battle;
			if (battle == 1) {
				int hitEvil;
				bool fight = true;
				int hitHero;
				if (choise == 1) {
					if (i == 1)
					{
						while (fight)
						{
							cout << endl;
							cout << "��� ������ = " << evil1.getDamage() << endl;
							hitEvil = soldier.getHealth() - evil1.getDamage();
							soldier.setHealth(hitEvil);
							cout << "���� �������� = " << soldier.getHealth() << endl;
							cout << "�� ������� ���� = " << soldier.getDamage() << endl;
							hitHero = evil1.getHealth() - soldier.getDamage();
							evil1.setHealth(hitHero);
							cout << "�������� ���������� = " << evil1.getHealth() << endl;
							if (soldier.getHealth() <= 0)
							{
								cout << "�� ������ = " << endl;
								fight = false;
							}
							if (evil1.getHealth() <= 0)
							{
								cout << "�� �� ������" << endl;
								cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
								cout << "����������" << endl;
								ofstream abc;
								abc.open(patch);
								abc << soldier.getHealth();
								abc << soldier.getDamage();
								abc.close();
								int relax;
								cin >> relax;
								if (relax == 1) {
									cout << "�� ����������� ���� �������" << endl;
									Sleep(60000);
									soldier.setHealth(50 * soldier.getLvl());
									cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
								}
								else {
									cout << "�� ����� �� �����" << endl;
								}
								fight = false;
							}
						}
					}
				}
			}
			else if (battle == 2) {
				chance = rand() % 99 + 1;
				if (chance > 50) {
					cout << "�� ������� �������������" << endl;
				}
				else
				{
					cout << "���� ����� �������� ���" << endl;
					int hitEvil;
					bool fight = true;
					int hitHero;
					if (choise == 1) {
						if (i == 1)
						{
							while (fight)
							{
								cout << endl;
								cout << "��� ������� ���� = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "���� �������� = " << soldier.getHealth() << endl;
								cout << "�� ������� ���� = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "�������� ���������� = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "�� ������� = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "�� �� ������" << endl;
									cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "�� ����������� ���� �������" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "�� ����� �� �����" << endl;
									}
									fight = false;
								}
							}
						}
					}
				}
			}
			else if (battle == 3) {
				int spendStrategyPoints;
				if (i == 1) {
					cout << "���������� � ����� � ��������\\n(��������� 5 ����� ���������)\n1 - ��\n2 - ���" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "����� ���������� � ��� �������" << endl;
					}
					else if (spendStrategyPoints == 2) {
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							if (i == 1)
							{
								while (fight)
								{
									cout << endl;
									cout << "��� ������� ���� = " << evil1.getDamage() << endl;
									hitEvil = soldier.getHealth() - evil1.getDamage();
									soldier.setHealth(hitEvil);
									cout << "���� �������� = " << soldier.getHealth() << endl;
									cout << "�� ������� ���� = " << soldier.getDamage() << endl;
									hitHero = evil1.getHealth() - soldier.getDamage();
									evil1.setHealth(hitHero);
									cout << "�������� ���������� = " << evil1.getHealth() << endl;
									if (soldier.getHealth() <= 0)
									{
										cout << "�� ������� = " << endl;
										fight = false;
									}
									if (evil1.getHealth() <= 0)
									{
										cout << "�� �� ������" << endl;
										cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "�� ����������� ���� �������" << endl;
											Sleep(60000);
											soldier.setHealth(50 * soldier.getLvl());
											cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
										}
										else {
											cout << "�� ����� �� �����" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
				}
				if (i == 2) {
					cout << "������ �������� ������� \n1 - ��\n2 - ���" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "�� ��������" << endl;
						Sleep(2000);
						cout << "�� �������������" << endl;
						Sleep(2000);
						cout << "������� ������ ����� ����� � ���������\n�� ����� ������\n";
					}
					else if (spendStrategyPoints == 2) {
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							while (fight)
							{
								cout << endl;
								cout << "��� ������� ���� = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "���� �������� = " << soldier.getHealth() << endl;
								cout << "�� ������� ���� = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "�������� ���������� = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "�� ������� = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "�� �� ������" << endl;
									cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "�� ����������� ���� �������" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "�� ����� �� �����" << endl;
									}
									fight = false;
								}
							}
						}
					}
				}
				if (i == 3) {
					cout << "��������� ������� � �������� ������ \n1 - ��\n2 - ���" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "����� ������� ������ � ������ ��������\n";
					}
					else if (spendStrategyPoints == 2) {
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							while (fight)
							{
								cout << endl;
								cout << "��� ������� ���� = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "���� �������� = " << soldier.getHealth() << endl;
								cout << "�� ������� ���� = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "�������� ���������� = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "�� ������� = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "�� �� ������" << endl;
									cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "�� ����������� ���� �������" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "�� ����� �� �����" << endl;
									}
									fight = false;
								}
							}
						}
					}
				}
			}
		}
	}
		  case 2: {
			  cout << "��� �������������\n�������� ����������..." << endl;
			  for (int i = 1; i < 4; i++) {
				  Sleep(1000);
				  cout << "�� ������� " << 33 * i << "����" << endl;
				  if (i == 1) {
					  evil1.getStats();
				  }
				  if (i == 2) {
					  evil2.getStats();
				  }
				  if (i == 3) {
					  evil3.getStats();
				  }
				  cout << "��� ������ ������?" << endl;
				  cout << "1 - �������� � ����� �� ����� \n2 - �������\n3 - ��������� ��������� � ����� � ���" << endl;
				  int battle;
				  cin >> battle;
				  if (battle == 1) {
					  int hitEvil;
					  bool fight = true;
					  int hitHero;
					  if (choise == 1) {
						  if (i == 1)
						  {
							  while (fight)
							  {
								  cout << endl;
								  cout << "��� ������ = " << evil1.getDamage() << endl;
								  hitEvil = soldier.getHealth() - evil1.getDamage();
								  soldier.setHealth(hitEvil);
								  cout << "���� �������� = " << soldier.getHealth() << endl;
								  cout << "�� ������� ���� = " << soldier.getDamage() << endl;
								  hitHero = evil1.getHealth() - soldier.getDamage();
								  evil1.setHealth(hitHero);
								  cout << "�������� ���������� = " << evil1.getHealth() << endl;
								  if (soldier.getHealth() <= 0)
								  {
									  cout << "�� ������ = " << endl;
									  fight = false;
								  }
								  if (evil1.getHealth() <= 0)
								  {
									  cout << "�� �� ������" << endl;
									  cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
									  int relax;
									  cin >> relax;
									  if (relax == 1) {
										  cout << "�� ����������� ���� �������" << endl;
										  Sleep(60000);
										  soldier.setHealth(50 * soldier.getLvl());
										  cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
									  }
									  else {
										  cout << "�� ����� �� �����" << endl;
									  }
									  fight = false;
								  }
							  }
						  }
					  }
				  }
				  else if (battle == 2) {
					  chance = rand() % 99 + 1;
					  if (chance > 50) {
						  cout << "�� ������� �������������" << endl;
					  }
					  else
					  {
						  cout << "���� ����� �������� ���" << endl;
						  int hitEvil;
						  bool fight = true;
						  int hitHero;
						  if (choise == 1) {
							  if (i == 1)
							  {
								  while (fight)
								  {
									  cout << endl;
									  cout << "��� ������� ���� = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "���� �������� = " << soldier.getHealth() << endl;
									  cout << "�� ������� ���� = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "�������� ���������� = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "�� ������� = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "�� �� ������" << endl;
										  cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "�� ����������� ���� �������" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "�� ����� �� �����" << endl;
										  }
										  fight = false;
									  }
								  }
							  }
						  }
					  }
				  }
				  else if (battle == 3) {
					  int spendStrategyPoints;
					  if (i == 1) {
						  cout << "���������� � ����� � ��������\\n(��������� 5 ����� ���������)\n1 - ��\n2 - ���" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "����� ���������� � ��� �������" << endl;
						  }
						  else if (spendStrategyPoints == 2) {
							  int hitEvil;
							  bool fight = true;
							  int hitHero;
							  if (choise == 1) {
								  if (i == 1)
								  {
									  while (fight)
									  {
										  cout << endl;
										  cout << "��� ������� ���� = " << evil1.getDamage() << endl;
										  hitEvil = soldier.getHealth() - evil1.getDamage();
										  soldier.setHealth(hitEvil);
										  cout << "���� �������� = " << soldier.getHealth() << endl;
										  cout << "�� ������� ���� = " << soldier.getDamage() << endl;
										  hitHero = evil1.getHealth() - soldier.getDamage();
										  evil1.setHealth(hitHero);
										  cout << "�������� ���������� = " << evil1.getHealth() << endl;
										  if (soldier.getHealth() <= 0)
										  {
											  cout << "�� ������� = " << endl;
											  fight = false;
										  }
										  if (evil1.getHealth() <= 0)
										  {
											  cout << "�� �� ������" << endl;
											  cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
											  int relax;
											  cin >> relax;
											  if (relax == 1) {
												  cout << "�� ����������� ���� �������" << endl;
												  Sleep(60000);
												  soldier.setHealth(50 * soldier.getLvl());
												  cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
											  }
											  else {
												  cout << "�� ����� �� �����" << endl;
											  }
											  fight = false;
										  }
									  }
								  }
							  }
						  }
					  }
					  if (i == 2) {
						  cout << "������ �������� ������� \n1 - ��\n2 - ���" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "�� ��������" << endl;
							  Sleep(2000);
							  cout << "�� �������������" << endl;
							  Sleep(2000);
							  cout << "������� ������ ����� ����� � ���������\n�� ����� ������\n";
						  }
						  else if (spendStrategyPoints == 2) {
							  int hitEvil;
							  bool fight = true;
							  int hitHero;
							  if (choise == 1) {
								  while (fight)
								  {
									  cout << endl;
									  cout << "��� ������� ���� = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "���� �������� = " << soldier.getHealth() << endl;
									  cout << "�� ������� ���� = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "�������� ���������� = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "�� ������� = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "�� �� ������" << endl;
										  cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "�� ����������� ���� �������" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "�� ����� �� �����" << endl;
										  }
										  fight = false;
									  }
								  }
							  }
						  }
					  }
					  if (i == 3) {
						  cout << "��������� ������� � �������� ������ \n1 - ��\n2 - ���" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "����� ������� ������ � ������ ��������\n";
						  }
						  else if (spendStrategyPoints == 2) {
							  int hitEvil;
							  bool fight = true;
							  int hitHero;
							  if (choise == 1) {
								  while (fight)
								  {
									  cout << endl;
									  cout << "��� ������� ���� = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "���� �������� = " << soldier.getHealth() << endl;
									  cout << "�� ������� ���� = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "�������� ���������� = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "�� ������� = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "�� �� ������" << endl;
										  cout << "������� �� ����� ���, ����� ���� ������, ������ ����� ����������� ����\n1 - ��\n2 - ���";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "�� ����������� ���� �������" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "���� �������� ��������� �������������� = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "�� ����� �� �����" << endl;
										  }
										  fight = false;
									  }
								  }
							  }
						  }
					  }
				  }
			  }
		  }

}
};
