#include <iostream>
#include <vector>
#include <iostream>

#include "UNO.hpp"
#include "CppRandom.hpp"


int main()
{
	menu();


	return 0;
}

void menu()
{
	int selection;
	std::cout << "UNO" << std::endl << std::endl
		<< "[1]\t Multiplayer" << std::endl
		<< "[2]\t Spezialregeln ein-/ausschalten" << std::endl
		<< "[3]\t Regeln anzeigen" << std::endl
		<< "[4]\t Rangliste anzeigen" << std::endl
		<< "[ELSE]\t Beenden" << std::endl;

	std::cin >> selection;

	switch (selection)
	{
	case 1: startMultiplayer();
		break;
	case 2: changeRules();
		break;
	case 3: showRules();
		break;
	case 4: showRanking();
		break;
	default:
		return;
	}
}

void changeRules()
{
	// 0-7-Regel
	// +2 auf +2
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

	std::cout << std::endl << "Mit Enter zurueck zum Menue.";

	std::cin.ignore();
	std::cin.ignore();
	menu();
}

void startMultiplayer()
{
	int numberOfPlayers = selectPlayerAmount();
	std::cout << "Es spielen " << numberOfPlayers << " Spieler mit." << std::endl;
}

int selectPlayerAmount()
{
	bool correctInput = false;
	int playerAmount;
	while (!correctInput)
	{
		playerAmount = 0;
		std::cout << "Geben Sie die Anzahl an Spielern ein: " << std::endl;
		std::cin >> playerAmount;
		if (playerAmount < 2 || playerAmount > 4)
		{
			std::cout << "Es muessen mindestens 2 und maximal 4 Spieler mitspielen." << std::endl;
		}
		else 
		{
			correctInput = true;
		}
	}
	return playerAmount;
}

void createCards(std::vector<Card*> drawDeck)
{
	for (int i = 0; i < 108; i++)
	{
		Card* card = new Card(i);
		drawDeck.push_back(card);
	}
}

void distributeCards(int numPlayers, std::vector<Card*> drawDeck)
{
	// Jeder Spieler erhält sieben zufaellige Karten aus dem drawDeck
	for (int i = 0; i < 7; i++)
	{
		
	}
}

void placeCard()
{

}








void showRanking()
{

}
