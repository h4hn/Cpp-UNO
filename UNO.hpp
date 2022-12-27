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
	zweiZiehen,
	vierZiehen,
	aussetzen,
	farbeWechseln
};

class Card
{
public:
	int number;
	Color color;
};


void menu();
void changeRules();
void showRules();
void startGame();
int selectPlayerAmount();

#endif
