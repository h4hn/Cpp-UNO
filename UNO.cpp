#include <iostream>

#include "UNO.hpp"

int main()
{
	menu();


	return 0;
}

void menu()
{
	int selection;
	std::cout << "UNO" << std::endl << std::endl
		<< "[1]\t Spielen" << std::endl
		<< "[2]\t Spezialregeln ein-/ausschalten" << std::endl
		<< "[3]\t Regeln anzeigen" << std::endl
		<< "[4]\t Rangliste anzeigen" << std::endl;

	std::cin >> selection;

	switch (selection)
	{
	case 1: startGame();
		break;
	case 2: changeRules();
		break;
	case 3: showRules();
		break;
	case 4:
		break;
	default:
		return;
	}
}

void changeRules()
{

}

void showRules()
{
	std::cout << "Regeln" << std::endl
		<< "-----" << std::endl

		<< "Vorbereitung:" << std::endl
		<< "\t- Es werden jedem Spieler sieben Karten ausgeteilt." << std::endl

		<< "\t- Der Rest kommt auf einen verdeckten Stapel in die Mitte." << std::endl
		<< "\t- Von diesem verdeckten Stapel wird eine Karte gezogen," << std::endl 
			<< "aufgedeckt und dann den Ablegestapel bildet." << std::endl
		<< "\t- Daraufhin darf ein zufällig ausgewählter Spieler starten." << std::endl << std::endl

		<< "Spielen:" << std::endl
		<< "\t- Nacheinander legt jeder Spiele pro Runde eine Karte ab." << std::endl
		<< "\t- Die abzulegende Karte muss dieselbe Zahl oder dieselbe Farbe" << std::endl 
			<< "\twie die oberste Karte des Ablegestapels haben." << std::endl
		<< "\t- Moechte der Spieler aus taktischen Gruenden keine Karte legen oder hat" << std::endl 
			<< "\tkeine Karte, die er legen kann, muss er eine Karte ziehen." << std::endl
		<< "\t\t- Diese darf der Spieler sofort ablegen." << std::endl
		<< "\t- Gewinner ist derjenige, der zuerst seine letzte Karte abgelegt hat." << std::endl

		<< "Aktionskarten:" << std::endl
		<< "\t- Legt ein Spieler eine \"Zwei Ziehen\"-Karte, muss der naechste Spieler zwei Karten ziehen." << std::endl
		<< "\t- Legt ein Spieler eine \"Richtungswechsel\"-Karte, wird die Richtung der naechsten Spieler umgedreht." << std::endl
		<< "\t- Legt ein Spieler eine \"Aussetzen\"-Karte, wird der naechste Spieler uebersprungen und darf keine Karte legen." << std::endl
		<< "\t- Legt ein Spieler eine \"Farbwahl\"-Karte, gibt dieser dem naechsten Spieler die zu legende Farbe vor." << std::endl
		<< "\t- Legt ein Spieler eine \"Farbwahl-Plus-4\"-Karte, gibt dieser dem naechsten Spieler die zu legende Farbe vor" << std::endl
		<< "\t  und der naechste Spieler muss 4 Karten ziehen." << std::endl;

}

void startGame()
{

}