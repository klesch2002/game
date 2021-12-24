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
	cout << "А вот и подкрепление\n Сейчас вас определят в дивизии" << endl;
	cout << "Кто ты?" << endl;
	cout << "1 - Солдат\n2 - Воин Крига" << endl;
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
	cout << "И в какую же мясорубку вас отправить" << endl;
	cout << "1 - Адский Предел\n2 - Тартар" << endl;
	int ways;
	int i = 1;
	cin >> ways;
	srand(time(NULL));
	int chance;
	int randHealth = rand() % 15 + 1; 
	int randDamage = rand() % 15 + 1;
	Evil evil1("Орк", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 
	Evil evil2("Нурглит", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 
	Evil evil3("Демон", randHealth, randDamage); 
	randHealth = rand() % 15 + 1; 
	randDamage = rand() % 15 + 1; 

	switch (ways) {
	case 1: {
		cout << "Вас перебрасывают\nМолитесь Императору..." << endl;
		for (int i = 1; i < 4; i++) {
			Sleep(1000);
			cout << "Вы прожили " << 33*i << "дней" << endl;
			if (i == 1) {
				evil1.getStats();
			}
			if (i == 2) {
				evil2.getStats();
			}
			if (i == 3) {
				evil3.getStats();
			}
			cout << "Что будешь делать?" << endl;
			cout << "1 - Кинуться в атаку на врага \n2 - сбежать\n3 - Продумать стратегию и пойти в бой" << endl;
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
							cout << "Вас ранили = " << evil1.getDamage() << endl;
							hitEvil = soldier.getHealth() - evil1.getDamage();
							soldier.setHealth(hitEvil);
							cout << "Ваше здоровье = " << soldier.getHealth() << endl;
							cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
							hitHero = evil1.getHealth() - soldier.getDamage();
							evil1.setHealth(hitHero);
							cout << "Здоровье противника = " << evil1.getHealth() << endl;
							if (soldier.getHealth() <= 0)
							{
								cout << "Вы умерли = " << endl;
								fight = false;
							}
							if (evil1.getHealth() <= 0)
							{
								cout << "Вы не сдохли" << endl;
								cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
								cout << "сохранение" << endl;
								ofstream abc;
								abc.open(patch);
								abc << soldier.getHealth();
								abc << soldier.getDamage();
								abc.close();
								int relax;
								cin >> relax;
								if (relax == 1) {
									cout << "Вы заматываете раны тряпкой" << endl;
									Sleep(60000);
									soldier.setHealth(50 * soldier.getLvl());
									cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
								}
								else {
									cout << "Вы снова на марше" << endl;
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
					cout << "Вы успешно дезертировали" << endl;
				}
				else
				{
					cout << "Силы Варпа настигли вас" << endl;
					int hitEvil;
					bool fight = true;
					int hitHero;
					if (choise == 1) {
						if (i == 1)
						{
							while (fight)
							{
								cout << endl;
								cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "Ваше здоровье = " << soldier.getHealth() << endl;
								cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "Здоровье противника = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "Вы погибли = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "Вы не сдохли" << endl;
									cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "Вы заматываете раны тряпкой" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "Вы снова на марше" << endl;
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
					cout << "Выстрелить в бочку с топливом\\n(Потратить 5 очков стратегии)\n1 - да\n2 - нет" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "Бочка взрывается и орк сгорает" << endl;
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
									cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
									hitEvil = soldier.getHealth() - evil1.getDamage();
									soldier.setHealth(hitEvil);
									cout << "Ваше здоровье = " << soldier.getHealth() << endl;
									cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
									hitHero = evil1.getHealth() - soldier.getDamage();
									evil1.setHealth(hitHero);
									cout << "Здоровье противника = " << evil1.getHealth() << endl;
									if (soldier.getHealth() <= 0)
									{
										cout << "Вы погибли = " << endl;
										fight = false;
									}
									if (evil1.getHealth() <= 0)
									{
										cout << "Вы не сдохли" << endl;
										cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
										int relax;
										cin >> relax;
										if (relax == 1) {
											cout << "Вы заматываете раны тряпкой" << endl;
											Sleep(60000);
											soldier.setHealth(50 * soldier.getLvl());
											cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
										}
										else {
											cout << "Вы снова на марше" << endl;
										}
										fight = false;
									}
								}
							}
						}
					}
				}
				if (i == 2) {
					cout << "Кинуть фугасную гранату \n1 - да\n2 - нет" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "Вы целитесь" << endl;
						Sleep(2000);
						cout << "Вы замахиваетесь" << endl;
						Sleep(2000);
						cout << "Граната падает прямо рядом с нурглитом\nВы идете дальше\n";
					}
					else if (spendStrategyPoints == 2) {
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							while (fight)
							{
								cout << endl;
								cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "Ваше здоровье = " << soldier.getHealth() << endl;
								cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "Здоровье противника = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "Вы погибли = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "Вы не сдохли" << endl;
									cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "Вы заматываете раны тряпкой" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "Вы снова на марше" << endl;
									}
									fight = false;
								}
							}
						}
					}
				}
				if (i == 3) {
					cout << "Подбежать поближе и отрубить голову \n1 - да\n2 - нет" << endl;
					cin >> spendStrategyPoints;
					if (spendStrategyPoints == 1) {
						cout << "Демон истошно кричит и падает замертво\n";
					}
					else if (spendStrategyPoints == 2) {
						int hitEvil;
						bool fight = true;
						int hitHero;
						if (choise == 1) {
							while (fight)
							{
								cout << endl;
								cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
								hitEvil = soldier.getHealth() - evil1.getDamage();
								soldier.setHealth(hitEvil);
								cout << "Ваше здоровье = " << soldier.getHealth() << endl;
								cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
								hitHero = evil1.getHealth() - soldier.getDamage();
								evil1.setHealth(hitHero);
								cout << "Здоровье противника = " << evil1.getHealth() << endl;
								if (soldier.getHealth() <= 0)
								{
									cout << "Вы погибли = " << endl;
									fight = false;
								}
								if (evil1.getHealth() <= 0)
								{
									cout << "Вы не сдохли" << endl;
									cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
									int relax;
									cin >> relax;
									if (relax == 1) {
										cout << "Вы заматываете раны тряпкой" << endl;
										Sleep(60000);
										soldier.setHealth(50 * soldier.getLvl());
										cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
									}
									else {
										cout << "Вы снова на марше" << endl;
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
			  cout << "Вас перебрасывают\nМолитесь Императору..." << endl;
			  for (int i = 1; i < 4; i++) {
				  Sleep(1000);
				  cout << "Вы прожили " << 33 * i << "дней" << endl;
				  if (i == 1) {
					  evil1.getStats();
				  }
				  if (i == 2) {
					  evil2.getStats();
				  }
				  if (i == 3) {
					  evil3.getStats();
				  }
				  cout << "Что будешь делать?" << endl;
				  cout << "1 - Кинуться в атаку на врага \n2 - сбежать\n3 - Продумать стратегию и пойти в бой" << endl;
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
								  cout << "Вас ранили = " << evil1.getDamage() << endl;
								  hitEvil = soldier.getHealth() - evil1.getDamage();
								  soldier.setHealth(hitEvil);
								  cout << "Ваше здоровье = " << soldier.getHealth() << endl;
								  cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
								  hitHero = evil1.getHealth() - soldier.getDamage();
								  evil1.setHealth(hitHero);
								  cout << "Здоровье противника = " << evil1.getHealth() << endl;
								  if (soldier.getHealth() <= 0)
								  {
									  cout << "Вы умерли = " << endl;
									  fight = false;
								  }
								  if (evil1.getHealth() <= 0)
								  {
									  cout << "Вы не сдохли" << endl;
									  cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
									  int relax;
									  cin >> relax;
									  if (relax == 1) {
										  cout << "Вы заматываете раны тряпкой" << endl;
										  Sleep(60000);
										  soldier.setHealth(50 * soldier.getLvl());
										  cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
									  }
									  else {
										  cout << "Вы снова на марше" << endl;
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
						  cout << "Вы успешно дезертировали" << endl;
					  }
					  else
					  {
						  cout << "Силы Варпа настигли вас" << endl;
						  int hitEvil;
						  bool fight = true;
						  int hitHero;
						  if (choise == 1) {
							  if (i == 1)
							  {
								  while (fight)
								  {
									  cout << endl;
									  cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "Ваше здоровье = " << soldier.getHealth() << endl;
									  cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "Здоровье противника = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "Вы погибли = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "Вы не сдохли" << endl;
										  cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "Вы заматываете раны тряпкой" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "Вы снова на марше" << endl;
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
						  cout << "Выстрелить в бочку с топливом\\n(Потратить 5 очков стратегии)\n1 - да\n2 - нет" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "Бочка взрывается и орк сгорает" << endl;
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
										  cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
										  hitEvil = soldier.getHealth() - evil1.getDamage();
										  soldier.setHealth(hitEvil);
										  cout << "Ваше здоровье = " << soldier.getHealth() << endl;
										  cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
										  hitHero = evil1.getHealth() - soldier.getDamage();
										  evil1.setHealth(hitHero);
										  cout << "Здоровье противника = " << evil1.getHealth() << endl;
										  if (soldier.getHealth() <= 0)
										  {
											  cout << "Вы погибли = " << endl;
											  fight = false;
										  }
										  if (evil1.getHealth() <= 0)
										  {
											  cout << "Вы не сдохли" << endl;
											  cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
											  int relax;
											  cin >> relax;
											  if (relax == 1) {
												  cout << "Вы заматываете раны тряпкой" << endl;
												  Sleep(60000);
												  soldier.setHealth(50 * soldier.getLvl());
												  cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
											  }
											  else {
												  cout << "Вы снова на марше" << endl;
											  }
											  fight = false;
										  }
									  }
								  }
							  }
						  }
					  }
					  if (i == 2) {
						  cout << "Кинуть фугасную гранату \n1 - да\n2 - нет" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "Вы целитесь" << endl;
							  Sleep(2000);
							  cout << "Вы замахиваетесь" << endl;
							  Sleep(2000);
							  cout << "Граната падает прямо рядом с нурглитом\nВы идете дальше\n";
						  }
						  else if (spendStrategyPoints == 2) {
							  int hitEvil;
							  bool fight = true;
							  int hitHero;
							  if (choise == 1) {
								  while (fight)
								  {
									  cout << endl;
									  cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "Ваше здоровье = " << soldier.getHealth() << endl;
									  cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "Здоровье противника = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "Вы погибли = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "Вы не сдохли" << endl;
										  cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "Вы заматываете раны тряпкой" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "Вы снова на марше" << endl;
										  }
										  fight = false;
									  }
								  }
							  }
						  }
					  }
					  if (i == 3) {
						  cout << "Подбежать поближе и отрубить голову \n1 - да\n2 - нет" << endl;
						  cin >> spendStrategyPoints;
						  if (spendStrategyPoints == 1) {
							  cout << "Демон истошно кричит и падает замертво\n";
						  }
						  else if (spendStrategyPoints == 2) {
							  int hitEvil;
							  bool fight = true;
							  int hitHero;
							  if (choise == 1) {
								  while (fight)
								  {
									  cout << endl;
									  cout << "Вам нанесли урон = " << evil1.getDamage() << endl;
									  hitEvil = soldier.getHealth() - evil1.getDamage();
									  soldier.setHealth(hitEvil);
									  cout << "Ваше здоровье = " << soldier.getHealth() << endl;
									  cout << "Вы нанесли урон = " << soldier.getDamage() << endl;
									  hitHero = evil1.getHealth() - soldier.getDamage();
									  evil1.setHealth(hitHero);
									  cout << "Здоровье противника = " << evil1.getHealth() << endl;
									  if (soldier.getHealth() <= 0)
									  {
										  cout << "Вы погибли = " << endl;
										  fight = false;
									  }
									  if (evil1.getHealth() <= 0)
									  {
										  cout << "Вы не сдохли" << endl;
										  cout << "Времени на отдых нет, нужно идти дальше, правда стоит забинтовать раны\n1 - Да\n2 - Нет";
										  int relax;
										  cin >> relax;
										  if (relax == 1) {
											  cout << "Вы заматываете раны тряпкой" << endl;
											  Sleep(60000);
											  soldier.setHealth(50 * soldier.getLvl());
											  cout << "Ваше здоровье полностью восстановилось = " << soldier.getHealth() << "hp" << endl;
										  }
										  else {
											  cout << "Вы снова на марше" << endl;
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
