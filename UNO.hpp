#ifndef UNO_HPP
#define UNO_HPP

enum class Color 
{
	rot,
	gelb,
	gruen,
	blau,
	schwarz
};

enum class Action
{
	// Diese Aktionen werden als weitere Nummern in der Karte definiert
	aussetzen,		// = 10
	rotieren,		// = 11
	zweiZiehen,		// = 12
	vierZiehen,		// = 13
};

class Card
{
public:
	int id;
	int number;
	Color color;
	Card(int setID)
	{
		id = setID;
	}

	// Destruktor?
};

class Player
{
public:
	int id;
	std::vector<Card*> playerCards;
};


void menu();
void changeRules();
void showRules();
void startMultiplayer();
int selectPlayerAmount();
void showRanking();
void createCards(std::vector<Card*> deck);

#endif
