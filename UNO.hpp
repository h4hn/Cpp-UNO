#ifndef UNO_HPP
#define UNO_HPP

/*
enum class Color 
{
	rot,
	gelb,
	gruen,
	blau,
	schwarz
};
*/

enum class Action
{
	// Diese Aktionen werden als weitere Nummern in der Karte definiert
	aussetzen,				// = 10
	richtungswechsel,		// = 11
	zweiZiehen,				// = 12
};

class Card
{
public:
	int number;
	std::string color;

	// Destruktor?
};

class Player
{
public:
	int id;
	std::string name;
	std::vector<Card*> playerCards;

	// Destruktor?
};

void intro();
void menu();
void changeRules();
void showRules();
void startMultiplayer();
void createPlayers(std::vector<Player*>& players);
int selectPlayerAmount();
void showRanking();
void createCards(std::vector<Card*>& drawDeck);
void shuffleDeck(std::vector<Card*>& deck);
void distributeCards(std::vector<Card*>& drawDeck, std::vector<Player*>& players);
void placeStartCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck);
void multiplayerGame(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players);
void showPlaceDeck(std::vector<Card*>& placeDeck, std::string wishedColor);
void confirmNextPlayer(Player* player);
Card* selectCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor);
void drawCard(std::vector<Card*>& drawDeck, Player* player);
bool checkCard(Card* stackCard, Card* playerCard, std::string& wishedColor);
void placeCardByPlayer(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Card* card);
void executeAction(Card* card, bool& reverse, bool& skip, int& plustwo, bool& plusfour, std::string& wishedColor);
void wishColor(std::string& newColor);
void backToMenu();

#endif
