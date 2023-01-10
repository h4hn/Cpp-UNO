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
    int points;
    // Destruktor?
};

class Player
{
public:
    int id;
    bool bot;
    std::string name;
    std::vector<Card*> playerCards;
    int score;
    // Destruktor?
};

void intro();
void menu();
void changeRules();
void showRules();
void startGame(bool multiplayer);
void startSingleplayer();
void startMultiplayer();
void createPlayers(std::vector<Player*>& players, bool multiplayer);
int selectPlayerAmount();
void showRanking();
void createCards(std::vector<Card*>& drawDeck);
void shuffleDeck(std::vector<Card*>& deck);
void distributeCards(std::vector<Card*>& drawDeck, std::vector<Player*>& players);
void placeStartCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck);
void chooseRules(bool& specialRules);
void game(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players, bool& specialRules);
void singleplayerGame(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players, bool specialRules);
void multiplayerGame(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players, bool specialRules);
void showPlaceDeck(std::vector<Card*>& placeDeck, std::string wishedColor);
void confirmNextPlayer(Player* player);
Card* selectCardBOT(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor);
Card* selectCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor);
void drawCard(std::vector<Card*>& drawDeck, Player* player);
bool checkCard(Card* stackCard, Card* playerCard, std::string& wishedColor);
void placeCardByPlayer(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Card* card);
void executeAction(Card* card, bool& reverse, bool& skip, int& plustwo, bool& plusfour, std::string& wishedColor, Player* player, bool specialRules, std::vector<Player*>& players);
int countCards(Player* player);
void swapCards(Player* player1, Player* player2);
void wishColor(std::string& newColor, Player* player);
void backToMenu();
void saveScores(std::vector<Player*>& players);
void safeScore(Player* player);
void writeScore(int selection);
void loadGame();
void readScore(int selection);
void clearScreen();

//Spielstandspeicherung
int playerAmountSave;
std::vector<Card*> actualPlaceDeck;
std::vector<Player*> playerScore;
std::vector<Card*> actualDrawDeck;

#endif
