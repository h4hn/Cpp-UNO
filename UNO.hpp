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
	aussetzen,		// = 10
	rotieren,		// = 11
	zweiZiehen,		// = 12
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
	std::vector<Card*> playerCards;
	Player(int setID)
	{
		id = setID;
	}
};


void menu();
void changeRules();
void showRules();
void startMultiplayer();
void createPlayers(std::vector<Player*>& players);
int selectPlayerAmount();
void showRanking();
void createCards(std::vector<Card*>& drawDeck);
void distributeCards(std::vector<Card*>& drawDeck, std::vector<Player*>& players);
void multiplayerGame(std::vector<Card*>& drawDeck, std::vector<Player*>& players);

#endif
