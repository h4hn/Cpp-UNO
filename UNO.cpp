#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>

#include "UNO.hpp"
#include "CppRandom.hpp"


int main()
{
	system("MODE CON COLS=94 LINES=35");
	system("title UNO - Das Kartenspiel in C++");

	intro();

	menu();

	return 0;
}

void intro()
{
	std::cout 
		<< "##############################################################################################" << std::endl
		<< "#                                                                                            #" << std::endl
		<< "#  ######                 ######  ##########          ######         ###############         #" << std::endl
		<< "#  ######                 ######  ###########         ######      #####################      #" << std::endl
		<< "#  ######                 ######  ############        ######    #########################    #" << std::endl
		<< "#  ######                 ######  ###### ######       ######   #######             #######   #" << std::endl
		<< "#  ######                 ######  ######  ######      ######  #######               #######  #" << std::endl
		<< "#  ######                 ######  ######   ######     ######  ######                 ######  #" << std::endl
		<< "#  ######                 ######  ######    ######    ######  ######                 ######  #" << std::endl
		<< "#  ######                 ######  ######     ######   ######  ######                 ######  #" << std::endl
		<< "#  ######                 ######  ######      ######  ######  ######                 ######  #" << std::endl
		<< "#  ######                 ######  ######       ###### ######  ######                 ######  #" << std::endl
		<< "#  ######                 ######  ######        ############  ######                 ######  #" << std::endl
		<< "#  #######               #######  ######         ###########  #######               #######  #" << std::endl
		<< "#   #######             #######   ######          ##########   #######             #######   #" << std::endl
		<< "#    #########################    ######           #########    #########################    #" << std::endl
		<< "#      #####################      ######            ########      #####################      #" << std::endl
		<< "#         ###############         ######             #######         ###############         #" << std::endl
		<< "#                                                                                            #" << std::endl
		<< "##############################################################################################" << std::endl
		<< "#                                                                                            #" << std::endl
		<< "#                         Tobias Hahn | Fabian Eilber | Fabian Unger                         #" << std::endl
		<< "#                                                                                            #" << std::endl
		<< "##############################################################################################" << std::endl;
	std::cout << std::endl << std::endl;
}

void menu()
{
	int selection;
	std::cout 
		<< "[1]\t Singleplayer" << std::endl
		<< "[2]\t Multiplayer" << std::endl
		<< "[3]\t Spezialregeln ein-/ausschalten" << std::endl
		<< "[4]\t Regeln anzeigen" << std::endl
		<< "[5]\t Rangliste anzeigen" << std::endl
		<< "[ELSE]\t Beenden" << std::endl;

	std::cin >> selection;

	switch (selection)
	{
	case 1:
		break;
	case 2: startMultiplayer();
		break;
	case 3: changeRules();
		break;
	case 4: showRules();
		break;
	case 5: showRanking();
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
	system("cls");
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
	system("cls");
	menu();
}

void startMultiplayer()
{
	std::vector<Card*> drawDeck;
	std::vector<Card*> placeDeck;
	std::vector<Player*> players;

	createPlayers(players);
	createCards(drawDeck);
	distributeCards(drawDeck, players);
	placeStartCard(drawDeck, placeDeck);
	multiplayerGame(drawDeck, placeDeck, players);
}

void createPlayers(std::vector<Player*> &players)
{
	int numberOfPlayers = selectPlayerAmount();
	std::cout << "Es spielen " << numberOfPlayers << " Spieler mit." << std::endl;
	for (int i = 1; i < numberOfPlayers + 1; i++)
	{
		std::string name = "Spieler" + (char)i;
		Player* player = new Player;
		std::cout << "Gebe den Namen fuer Spieler " << i << " ein: ";
		std::cin >> name;
		player->name = name;
		players.push_back(player);
	}
}

int selectPlayerAmount()
{
	bool correctInput = false;
	int playerAmount;
	while (!correctInput)
	{
		playerAmount = 0;
		std::cout << "Gebe die Anzahl an Spielern ein: " << std::endl;
		std::cin >> playerAmount;
		if (playerAmount < 2 || playerAmount > 4)
		{
			std::cout << "Es muessen mindestens 2 und maximal 4 Spieler mitspielen." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else 
		{
			correctInput = true;
		}
	}
	return playerAmount;
}

void createCards(std::vector<Card*> &drawDeck)
{
	// Karten instanziieren --> Es muessen folgende Karten dem Deck hinzugefuegt werden: https://de.wikipedia.org/wiki/Uno_(Kartenspiel)#/media/Datei:UNO_cards_deck.svg

	// ROTE Karten
	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 13; j++)
		{
			Card* card = new Card;
			card->color = "rot";
			card->number = j;
			drawDeck.push_back(card);
		}
	}
	// BLAUE Karten
	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 13; j++)
		{
			Card* card = new Card;
			card->color = "blau";
			card->number = j;
			drawDeck.push_back(card);
		}
	}
	// GELBE Karten
	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 13; j++)
		{
			Card* card = new Card;
			card->color = "gelb";
			card->number = j;
			drawDeck.push_back(card);
		}
	}
	// Gruene Karten
	for (int i = 0; i < 2; i++)
	{
		for (int j = i; j < 13; j++)
		{
			Card* card = new Card;
			card->color = "gruen";
			card->number = j;
			drawDeck.push_back(card);
		}
	}
	// SCHWARZE Karten
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Card* card = new Card;
			card->color = "schwarz";
			card->number = i;				// Wenn schwarz Nummer 1 hat --> +4 Karte
			drawDeck.push_back(card);
		}
	}
}

void shuffleDeck(std::vector<Card*>& deck)
{
	std::random_device rd;
	std::shuffle(std::begin(deck), std::end(deck), rd);
}

void distributeCards(std::vector<Card*> &drawDeck, std::vector<Player*> &players)
{
	shuffleDeck(drawDeck);
	// Jeder Spieler erhält sieben zufaellige Karten aus dem drawDeck
	for (int i = 0; i < 7; i++)
	{
		for (Player* player : players)
		{
			Card* drawnCard = drawDeck.front();
			drawDeck.erase(drawDeck.begin());
			player->playerCards.push_back(drawnCard);
		}
	}

	/*
	// Alle Karten der jeweiligen Spieler zeigen
	for (Player* player : players)
	{
		for (Card* card : player->playerCards)
		{
			std::cout << card->color << " + " << card->number << std::endl;
		}
		std::cout << std::endl;
	}
	*/
}

std::string getCardInfo(Card* card)
{
	std::string cardInfo;

	if (card->color == "rot")
	{
		switch (card->number)
		{
		case 0: cardInfo = "Rote 0";
			break;
		case 1: cardInfo = "Rote 1";
			break;
		case 2: cardInfo = "Rote 2";
			break;
		case 3: cardInfo = "Rote 3";
			break;
		case 4: cardInfo = "Rote 4";
			break;
		case 5: cardInfo = "Rote 5";
			break;
		case 6: cardInfo = "Rote 6";
			break;
		case 7: cardInfo = "Rote 7";
			break;
		case 8: cardInfo = "Rote 8";
			break;
		case 9: cardInfo = "Rote 9";
			break;
		case 10: cardInfo = "Rote \"Aussetzen\"-Karte";
			break;
		case 11: cardInfo = "Rote \"Richtungswechsel\"-Karte";
			break;
		case 12: cardInfo = "Rote \"Zwei Ziehen\"-Karte";
			break;
		default: cardInfo = "Karte nicht verfuegbar.";
			break;
		}
	}
	else if (card->color == "blau")
	{
		switch (card->number)
		{
		case 0: cardInfo = "Blaue 0";
			break;
		case 1: cardInfo = "Blaue 1";
			break;
		case 2: cardInfo = "Blaue 2";
			break;
		case 3: cardInfo = "Blaue 3";
			break;
		case 4: cardInfo = "Blaue 4";
			break;
		case 5: cardInfo = "Blaue 5";
			break;
		case 6: cardInfo = "Blaue 6";
			break;
		case 7: cardInfo = "Blaue 7";
			break;
		case 8: cardInfo = "Blaue 8";
			break;
		case 9: cardInfo = "Blaue 9";
			break;
		case 10: cardInfo = "Blaue \"Aussetzen\"-Karte";
			break;
		case 11: cardInfo = "Blaue \"Richtungswechsel\"-Karte";
			break;
		case 12: cardInfo = "Blaue \"Zwei Ziehen\"-Karte";
			break;
		default: cardInfo = "Karte nicht verfuegbar.";
			break;
		}
	}
	else if (card->color == "gruen")
	{
		switch (card->number)
		{
		case 0: cardInfo = "Gruene 0";
			break;
		case 1: cardInfo = "Gruene 1";
			break;
		case 2: cardInfo = "Gruene 2";
			break;
		case 3: cardInfo = "Gruene 3";
			break;
		case 4: cardInfo = "Gruene 4";
			break;
		case 5: cardInfo = "Gruene 5";
			break;
		case 6: cardInfo = "Gruene 6";
			break;
		case 7: cardInfo = "Gruene 7";
			break;
		case 8: cardInfo = "Gruene 8";
			break;
		case 9: cardInfo = "Gruene 9";
			break;
		case 10: cardInfo = "Gruene \"Aussetzen\"-Karte";
			break;
		case 11: cardInfo = "Gruene \"Richtungswechsel\"-Karte";
			break;
		case 12: cardInfo = "Gruene \"Zwei Ziehen\"-Karte";
			break;
		default: cardInfo = "Karte nicht verfuegbar.";
			break;
		}
	}
	else if (card->color == "gelb")
	{
		switch (card->number)
		{
		case 0: cardInfo = "Gelbe 0";
			break;
		case 1: cardInfo = "Gelbe 1";
			break;
		case 2: cardInfo = "Gelbe 2";
			break;
		case 3: cardInfo = "Gelbe 3";
			break;
		case 4: cardInfo = "Gelbe 4";
			break;
		case 5: cardInfo = "Gelbe 5";
			break;
		case 6: cardInfo = "Gelbe 6";
			break;
		case 7: cardInfo = "Gelbe 7";
			break;
		case 8: cardInfo = "Gelbe 8";
			break;
		case 9: cardInfo = "Gelbe 9";
			break;
		case 10: cardInfo = "Gelbe \"Aussetzen\"- Karte";
			break;
		case 11: cardInfo = "Gelbe \"Richtungswechsel\"-Karte";
			break;
		case 12: cardInfo = "Gelbe \"Zwei Ziehen\"-Karte";
			break;
		default: cardInfo = "Karte nicht verfuegbar.";
			break;
		}
	}
	else if (card->color == "schwarz")
	{
		switch (card->number)
		{
		case 0: cardInfo = "\"Farbwechsel\"-Karte";
			break;
		case 1: cardInfo = "\"Farbwechsel + 4\"-Karte";
			break;
		default: cardInfo = "Karte nicht verfuegbar.";
			break;
		}
	}

	return cardInfo;
}

void placeStartCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck)
{
	bool isActionCard = false;
	Card* startCard = new Card;

	do {
		isActionCard = false;
		startCard = drawDeck.front();
		drawDeck.erase(drawDeck.begin());
		if (startCard->color == "schwarz" || startCard->number >= 10 && startCard->number <= 12)
		{
			isActionCard = true;
			drawDeck.push_back(startCard);
		}
	} while (isActionCard);

	placeDeck.push_back(startCard);
}

void multiplayerGame(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players)
{
	system("cls");

	bool finished = false;
	int startPlayerID = GetRandomNumberBetween(0, players.size() - 1);
	int currentPlayerID = startPlayerID;

	std::vector<Player*> ranking;

	// Aktionskarten - Parameter
	bool skip = false;				// number == 10
	bool reverse = false;			// number == 11
	int plustwo = 0;				// number == 12
	bool plusfour = false;			// color == black && number == 1
	std::string wishedColor = "";	// color == black
	// -------------------------

	Player* currentPlayer = players[currentPlayerID];

	while (!finished)
	{
		currentPlayer = players[currentPlayerID];
		if (currentPlayer->playerCards.size() != 0)
		{
			confirmNextPlayer(currentPlayer);
			system("cls");
			std::cout << "Aktueller Spieler: " << currentPlayer->name << std::endl << std::endl;

			if (skip)
			{
				std::cout << "Du musst diese Runde aussetzen." << std::endl << std::endl;
				skip = false;
			}
			else
			{
				if (plustwo > 0)
				{
					/*
					* Ueberpruefen, ob Spieler eine +2-Karte hat
					* - Wenn ja, fragen, ob er diese legen moechte oder direkt zwei Karten ziehen moechte
					* - Wenn nein, muss er Karten ziehen
					*/
					bool hasPlusTwo = false;
					Card* plusTwoCard = new Card;
					int plusTwoIndex = 0;
					for (Card* card : currentPlayer->playerCards)
					{
						if (card->number == 12)
						{
							hasPlusTwo = true;
							plusTwoCard = card;
							break;
						}
						plusTwoIndex++;
					}
					if (hasPlusTwo)
					{
						bool correctInput = false;
						char choice;
						while (!correctInput)
						{
							std::cout << "Moechtest du deine \"+2\"-Karte legen?" << std::endl
								<< "Wenn nein, musst du " << plustwo << " Karten ziehen. [y|n]" << std::endl;
							std::cin >> choice;
							if (choice == 'y' || choice == 'n')
							{
								correctInput = true;
							}
							else
							{
								std::cout << "Bitte geben Sie y oder n ein." << std::endl;
								system("cls");
							}
						}
						if (choice == 'y')
						{
							placeCardByPlayer(drawDeck, placeDeck, plusTwoCard);
							currentPlayer->playerCards.erase(currentPlayer->playerCards.begin() + plusTwoIndex);
							plustwo += 2;
						}
						else if (choice == 'n')
						{
							for (int i = 0; i < plustwo; i++)
							{
								drawCard(drawDeck, currentPlayer);
							}
							plustwo = 0;
						}
					}
					else
					{
						std::cout << "Du musst " << plustwo << " Karten ziehen." << std::endl << std::endl;
						for (int i = 0; i < plustwo; i++)
						{
							drawCard(drawDeck, currentPlayer);
						}
						plustwo = 0;
					}
				}
				else if (plusfour)
				{
					/*
					* Spieler muss 4 Karten ziehen und darf keine Karte legen
					*/
					std::cout << "Du musst 4 Karten ziehen." << std::endl << std::endl;
					for (int i = 0; i < 4; i++)
					{
						drawCard(drawDeck, currentPlayer);
					}
					plusfour = false;
				}
				else
				{
					/*
					* Spieler, die Karten ziehen mussten, duerfen nicht direkt wieder eine Karte legen.
					*/
					Card* selectedCard = selectCard(drawDeck, placeDeck, currentPlayer, wishedColor);
					if (selectedCard != NULL)
					{
						wishedColor = "";
						placeCardByPlayer(drawDeck, placeDeck, selectedCard);
						executeAction(selectedCard, reverse, skip, plustwo, plusfour, wishedColor);
					}			
				}
			}

			if (currentPlayer->playerCards.size() == 0)
			{
				ranking.push_back(currentPlayer);
			}
		}

		if (currentPlayerID < players.size() - 1 && !reverse)
		{
			currentPlayerID++;
		}
		else if (currentPlayerID == players.size() - 1 && !reverse)
		{
			currentPlayerID = 0;
		}
		else if (currentPlayerID > 0 && reverse)
		{
			currentPlayerID--;
		}
		else if (currentPlayerID == 0 && reverse)
		{
			currentPlayerID = players.size() - 1;
		}

		if (ranking.size() == players.size() - 1)
		{
			finished = true;
			for (Player* lastPlayer : players)
			{
				if (lastPlayer->playerCards.size() != 0)
				{
					ranking.push_back(lastPlayer);
				}
			}
		}
	}

	system("cls");

	std::cout << "Das Spiel ist zu Ende. Im Folgenden seht ihr die Rangliste des Spiels." << std::endl << std::endl;

	int rank = 1;
	for (Player* player : ranking)
	{
		std::cout << rank << ". Platz:\t" << player->name << std::endl;
		rank++;
	}
	backToMenu();
	system("cls");
}

void confirmNextPlayer(Player* player)
{
	// Erst zum naechsten Spieler wechseln, wenn er bereit ist, damit niemand anderes seine Karten sieht
	bool correctInput = false;

	while (!correctInput)
	{
		std::string confirmPlayer;
		std::cout << "Der naechste Spieler ist " << player->name << std::endl
			<< "Bitte mit [y] bestaetigen, dass gewechselt werden kann." << std::endl;
		std::cin >> confirmPlayer;

		if (confirmPlayer == "y")
		{
			correctInput = true;
		}
		else
		{
			std::cout << "Bitte gebe nur [y] ein, wenn du bereit bist." << std::endl;
		}
	}
}

void showPlaceDeck(std::vector<Card*>& placeDeck, std::string wishedColor)
{
	std::string shownCard = getCardInfo(placeDeck.front());

	std::cout << "Die aktuell oberste Karte auf dem Legestapel ist: " << shownCard << std::endl << std::endl;
	if (wishedColor != "")
	{
		std::cout << "Es wurde sich die Farbe " << wishedColor << " gewuenscht." << std::endl << std::endl;
	}
}

Card* selectCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor)
{
	std::vector<Player*> ranking;
	Card* placeDeckCard = placeDeck.front();
	Card* selectedCard;
	bool correctInput = false;
	bool cardDrawn = false;
	int selection;
	while (!correctInput)
	{
		showPlaceDeck(placeDeck, wishedColor);
		std::cout << "Bitte waehle die Karte, die gelegt werden soll." << std::endl;
		int index = 0;
		for (Card* card : player->playerCards)
		{
			std::string cardInfo = getCardInfo(card);
			std::cout << "[" << index + 1 << "]\t" << cardInfo << std::endl;
			index++;
		}

		if (!cardDrawn)
		{
			std::cout << "[" << index + 1 << "]\tKarte ziehen" << std::endl;
			std::cin >> selection;
			if (selection < 1 || selection > player->playerCards.size() + 1)
			{
				std::cout << "Bitte gebe eine gueltige Zahl ein." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else
		{
			std::cout << "[" << index + 1 << "]\tKeine Karte legen" << std::endl;
			std::cin >> selection;
			if (selection < 1 || selection > player->playerCards.size() + 1)
			{
				std::cout << "Bitte gebe eine gueltige Zahl ein." << std::endl;
				std::cin.clear(); //clear bad input flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}


		if (selection == player->playerCards.size() + 1 && !cardDrawn)
		{
			// Karte ziehen
			drawCard(drawDeck, player);
			cardDrawn = true;
			system("cls");
			std::cout << "Aktueller Spieler: " << player->name << std::endl << std::endl;
			continue;
		}
		else if (selection == player->playerCards.size() + 1 && cardDrawn)
		{
			system("cls");
			return NULL;
		}
		else
		{
			// Karte legen
			selection--;

			std::cout << "Ausgewaehlte Karte: " << player->playerCards[selection]->color << " + " << player->playerCards[selection]->number << std::endl;

			selectedCard = player->playerCards[selection];

			// Ueberpruefen, ob Karte gelegt werden darf.
			correctInput = checkCard(placeDeckCard, selectedCard, wishedColor);

			if (!correctInput)
			{
				system("cls");
				std::cout << "Diese Karte kann nicht auf der Karte, die auf dem Ablegestapel liegt, abgelegt werden." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Aktueller Spieler: " << player->name << std::endl << std::endl;
			}
			else
			{
				player->playerCards.erase(player->playerCards.begin() + selection);
				system("cls");
				return selectedCard;
			}
		}
	}
}

void drawCard(std::vector<Card*>& drawDeck, Player* player)
{
	// Karte ziehen
	Card* card = drawDeck.front();
	drawDeck.erase(drawDeck.begin());
	player->playerCards.push_back(card);
}

bool checkCard(Card* stackCard, Card* playerCard, std::string &wishedColor)
{
	std::string stackColor = stackCard->color;
	int stackNumber = stackCard->number;

	std::string playerColor = playerCard->color;
	int playerNumber = playerCard->number;
	if (wishedColor == "")
	{
		if (playerColor == "schwarz" && stackColor != "schwarz")
		{
			return true;
		}
		else if (playerColor == stackColor && playerColor != "schwarz")
		{
			return true;
		}
		else if (playerNumber == stackNumber && playerColor != "schwarz")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (playerColor == "schwarz")
		{
			return false;
		}
		else if (playerColor == wishedColor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void placeCardByPlayer(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Card* card)
{
	/*
	* Karte von Spieler auf placeDeck legen
	* Andere Karte(n) von placeDeck direkt zurueck auf drawDeck legen und diesen dann auch direkt mischeln
	*/
	Card* old_card = placeDeck.front();
	placeDeck.erase(placeDeck.begin());
	placeDeck.push_back(card);
	drawDeck.push_back(old_card);
	shuffleDeck(drawDeck);
}

void executeAction(Card* card, bool &reverse, bool &skip, int &plustwo, bool &plusfour, std::string &wishedColor)
{
	int number = card->number;
	std::string color = card->color;

	if (color != "schwarz")
	{
		switch (number)
		{
		case 10: skip = true;
			break;
		case 11: 
			if (!reverse)
			{
				reverse = true;
			}
			else
			{
				reverse = false;
			}
			break;
		case 12: plustwo += 2;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (number)
		{
		case 0: wishColor(wishedColor);
			break;
		case 1: wishColor(wishedColor);
			plusfour = true;
			break;
		default:
			break;
		}
	}
}

void wishColor(std::string &newColor)
{
	char selection;
	bool correctInput = false;
	while (!correctInput)
	{
		std::cout << "Bitte waehle die Farbe, die du dir wuenschst." << std::endl
			<< "[1]\tRot" << std::endl
			<< "[2]\tGruen" << std::endl
			<< "[3]\tBlau" << std::endl
			<< "[4]\tGelb" << std::endl;
		std::cin >> selection;
		if (selection == '1' || selection == '2' || selection == '3' || selection == '4')
		{
			correctInput = true;
		}
		else
		{
			std::cout << "Bitte geben Sie eine gueltige Eingabe ein." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
		}
	}
	switch (selection)
	{
	case '1': newColor = "rot";
		break;
	case '2': newColor = "gruen";
		break;
	case '3': newColor = "blau";
		break;
	case '4': newColor = "gelb";
		break;
	default:
		break;
	}
}

void backToMenu()
{
	char selection;
	std::cout << std::endl << std::endl
		<< "[m] Zum Menue zurueckkehren" << std::endl
		<< "[ELSE] Beenden" << std::endl;
	std::cin >> selection;

	if (selection == 'm')
	{
		menu();
	}
}

void showRanking()
{

}
