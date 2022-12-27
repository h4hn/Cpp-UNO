#ifndef UNO_HPP
#define UNO_HPP

enum class Color 
{
	rot,
	gelb,
	gruen,
	blau
};

enum class Action
{
	zweiZiehen,
	vierZiehen,
	aussetzen,
	farbeWechseln
};

class TakeTwo
{
public:
	Color rot;
	Action zweiZiehen;
};


void menu();
void changeRules();
void showRules();
void startGame();

#endif