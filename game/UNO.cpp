#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

#include "UNO.hpp"
#include "CppRandom.hpp"


std::string Card::getCardInfo()
{
    std::string cardInfo;

    if (color == "rot")
    {
        switch (number)
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
    else if (color == "blau")
    {
        switch (number)
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
    else if (color == "gruen")
    {
        switch (number)
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
    else if (color == "gelb")
    {
        switch (number)
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
        case 10: cardInfo = "Gelbe \"Aussetzen\"-Karte";
            break;
        case 11: cardInfo = "Gelbe \"Richtungswechsel\"-Karte";
            break;
        case 12: cardInfo = "Gelbe \"Zwei Ziehen\"-Karte";
            break;
        default: cardInfo = "Karte nicht verfuegbar.";
            break;
        }
    }
    else if (color == "schwarz")
    {
        switch (number)
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


int main()
{
    menu();

    return 0;
}

void intro() //gibt den Intro Screen aus
{
    clearScreen();
    std::ifstream f;
    std::string reading;
    f.open("Intro.txt");
    while (!f.eof())
    {
        getline(f, reading);
        std::cout << reading << std::endl;
    }
    f.close();
}

void menu() //gibt das Menu aus und leitet je nach Input weiter
{
    intro();
    int selection;
    std::cout
        << "[1]\t Singleplayer" << std::endl
        << "[2]\t Multiplayer" << std::endl
        << "[3]\t Regeln anzeigen" << std::endl
        << "[4]\t Rangliste anzeigen" << std::endl
        << "[5]\t Spiel laden" << std::endl
        << "[ELSE]\t Beenden" << std::endl;

    std::cin >> selection;



    switch (selection)
    {
    case 1: startGame(false);
        break;
    case 2: startGame(true);
        break;
    case 3: showRules();
        break;
    case 4: showRanking();
        break;
    case 5: loadSaveGame();
        break;
    default:
        exit(3);
        return;
    }
}

void showRules() // zeigt die Spielregeln
{
    clearScreen();
    std::ifstream f;
    std::string reading;
    f.open("Rules.txt", std::ios::in);
    while (!f.eof())
    {
        getline(f, reading);
        std::cout << reading << std::endl;
    }
    f.close();
    std::cout << std::endl << "Mit Enter zurueck zum Menue.";

    std::cin.ignore();
    std::cin.ignore();
    clearScreen();
    menu();
}

void startGame(bool multiplayer) //erstellt alle nötigen Objekte zum Spielen
{


    if (fileEmpty("./savegames/antiragequitsave.txt"))
    {
        clearScreen();
        if (multiplayer)
        {
            std::cout << "Multiplayer" << std::endl;
            drawLine(NULL);
        }
        else
        {
            std::cout << "Singleplayer" << std::endl;
            drawLine(NULL);
        }
        std::vector<Card*> drawDeck;
        std::vector<Card*> placeDeck;
        std::vector<Player*> players;
        bool specialRules = false;
        std::string colorWish = "";

        createPlayers(players, multiplayer);
        createCards(drawDeck);
        distributeCards(drawDeck, players);
        placeStartCard(drawDeck, placeDeck);
        chooseRules(specialRules);

        startPlayerID = GetRandomNumberBetween(0, players.size() - 1);
        plustwoLoad = 0;
        plusfourLoad = false;

        game(drawDeck, placeDeck, players, specialRules, colorWish);
        //Wenn Spiel beendet werden alle Objekte gelöscht
        for (Card* card : drawDeck)
        {
            delete card;
        }
        for (Card* card : placeDeck)
        {
            delete card;
        }
        for (Player* player : players)
        {
            delete player;
        }
    }
    else
    {
        antiRageQuit(multiplayer);
    }
}

void createPlayers(std::vector<Player*>& players, bool multiplayer) //Erzeugt Objekte der Spieler
{
    int numberOfPlayers = selectPlayerAmount();
    std::cout << "Es spielen " << numberOfPlayers << " Spieler mit." << std::endl << std::endl;

    if (multiplayer) //Wenn Multiplayer können für jeden Spieler Namen eingegebene werden
    {
        for (int i = 1; i < numberOfPlayers + 1; i++)
        {
            std::string name = "Spieler" + (char)i;
            Player* player = new Player;
            std::cout << "Gebe den Namen fuer Spieler " << i << " ein: ";
            std::cin >> name;
            player->id = i - 1;
            player->name = name;
            player->bot = false;
            player->laidCards = 0;
            players.push_back(player);
        }
    }
    else //Wenn Singleplayer wird nur ein Name eingegeben. Der Rest der Spieler werden unter Namen: BOT<Nr> initialisiert
    {
        std::string name = "Spieler1";
        Player* player = new Player;
        std::cout << "Gebe deinen Namen ein: ";
        std::cin >> name;
        player->name = name;
        player->bot = false;
        player->laidCards = 0;
        players.push_back(player);

        for (int i = 2; i < numberOfPlayers + 1; i++) // Initialisierung der BOTs
        {
            std::string name = "BOT";
            name.push_back(i + 47);
            Player* player = new Player;
            player->name = name;
            player->bot = true;
            player->laidCards = 0;
            players.push_back(player);
        }
    }
}

int selectPlayerAmount() //Abfrage wieviel Spieler mitspielen
{
    bool correctInput = false;
    int playerAmount;
    while (!correctInput)
    {
        playerAmount = 0;
        std::cout << "Gebe die Anzahl an Spielern ein: " << std::endl;
        std::cin >> playerAmount;
        if (playerAmount < 2 || playerAmount > 4) //Minimal 2 Maximal 4 Spieler sind erlaubt
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
    playerAmountSave = playerAmount;
    return playerAmount;
}

void createCards(std::vector<Card*>& drawDeck) //Generierung der Karten
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

void shuffleDeck(std::vector<Card*>& deck) //Kartendeck mischeln
{
    std::random_device rd;
    std::shuffle(std::begin(deck), std::end(deck), rd);
}

void distributeCards(std::vector<Card*>& drawDeck, std::vector<Player*>& players) //Karten an spieler austeilen
{
    shuffleDeck(drawDeck);
    // Jeder Spieler erhaelt sieben zufaellige Karten aus dem drawDeck
    for (int i = 0; i < 7; i++)
    {
        for (Player* player : players)
        {
            Card* drawnCard = drawDeck.front();
            drawDeck.erase(drawDeck.begin());
            player->playerCards.push_back(drawnCard);
        }
    }
}

void placeStartCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck) //Die Startkarte wird zufaellig bestimmt
{
    bool isActionCard = false;
    Card* startCard = new Card;

    do {
        isActionCard = false;
        startCard = drawDeck.front();
        drawDeck.erase(drawDeck.begin());
        if (startCard->color == "schwarz" || startCard->number >= 10 && startCard->number <= 12) //Überprüfung ob Startkarte eine Actionkarte ist -> Wenn ja wird eine neue gewaehlt
        {
            isActionCard = true;
            drawDeck.push_back(startCard);
        }
    } while (isActionCard);

    placeDeck.push_back(startCard);

    if (!actualPlaceDeck.empty()) {
        actualPlaceDeck.erase(actualPlaceDeck.begin());
    }
    actualPlaceDeck.push_back(startCard);
}

void chooseRules(bool& specialRules) //Abfrage ob mit oder ohne Spezial Regel gespielt werden soll
{
    bool correctInput = false;
    char choice;
    while (!correctInput)
    {
        std::cout << std::endl << "Moechtest du die 0-7-Regel aktivieren? (y|n)" << std::endl;
        std::cin >> choice;
        if (choice == 'y' || choice == 'n')
        {
            correctInput = true;
        }
        else
        {
            std::cout << "Bitte geben Sie y oder n ein." << std::endl;
            clearScreen();
        }
    }
    if (choice == 'y')
    {
        specialRules = true;
    }
    else if (choice == 'n')
    {
        specialRules = false;
    }
    rulesActive = specialRules;
}

void antiRageQuit(bool multiplayer)
{
    int selection;

    std::cout << "Es gibt noch ein unbeendetes Spiel. Willst du das alte Spiel:" << std::endl
        << "[1]\t fortsetzen oder speichern" << std::endl
        << "[2]\t loeschen und neues Spiel starten" << std::endl
        << "[3]\t Zurueck zum Menu" << std::endl;

    std::cin >> selection;

    switch (selection) {
    case 1:
        readSaveGame(4);
        break;
    case 2:
        deleteSaveGame("./savegames/antiragequitsave.txt");
        startGame(multiplayer);
        break;
    case 3:
        clearScreen();
        menu();
        break;
    default:
        break;
    }
}

void game(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, std::vector<Player*>& players, bool& specialRules, std::string& _wishedColor) //Spiellogik
{
    clearScreen();

    bool finished = false;
    //int startPlayerID = GetRandomNumberBetween(0, players.size() - 1);
    int currentPlayerID = startPlayerID;

    std::vector<Player*> ranking;

    // Aktionskarten - Parameter
    bool skip = false;				            // number == 10
    bool reverse = false;			            // number == 11
    int plustwo = plustwoLoad;				    // number == 12
    bool plusfour = plusfourLoad;	            // color == black && number == 1
    std::string wishedColor = _wishedColor;	    // color == black
    // -------------------------

    Player* currentPlayer = players[currentPlayerID];

    while (!finished)
    {
        currentPlayer = players[currentPlayerID];
        if (currentPlayer->playerCards.size() != 0)
        {
            if (!currentPlayer->bot)
            {
                actualPlayerID = currentPlayerID;
                players[currentPlayerID]->hasPlusTwo = plustwo;
                players[currentPlayerID]->hasPlusFour = plusfour;
                confirmNextPlayer(currentPlayer);
                clearScreen();
                drawLine(currentPlayer);
                std::cout << "Aktueller Spieler: " << currentPlayer->name << std::endl;
            }

            

            //Speichern der aktuellen Player in externen Vektor
            for (int i = 0; i < players.size(); i++) {
                playerScore.push_back(players[i]);
            }
            //Speichern des aktuellen drawDecks
            if (!actualDrawDeck.empty()) {
                actualDrawDeck.clear();
            }
            for (int i = 0; i < drawDeck.size(); i++) {
                //std::cout << drawDeck[i]->color << drawDeck[i]->number << std::endl;
                actualDrawDeck.push_back(drawDeck[i]);
            }

            if (skip) //Überprüfung ob Spieler aussetzen muss
            {
                //Verschiedene Ausgabe wenn Bot oder echter Spieler
                if (currentPlayer->bot)
                {
                    std::cout << currentPlayer->name << " muss diese Runde aussetzen." << std::endl << std::endl;
                }
                else
                {
                    drawLine(currentPlayer);
                    std::cout << "Du musst diese Runde aussetzen." << std::endl << std::endl;
                }

                skip = false;
            }
            else
            {
                if (currentPlayer->bot) //Bot am Zug
                {
                    if (plustwo > 0) //Überprüfung ob Bot Karten durch vorherige +2 Karetenaufziehen muss
                    {
                        bool hasPlusTwo = false;
                        Card* plusTwoCard = new Card;
                        int plusTwoIndex = 0;
                        //Überprüfung ob Bot +2 Karten besitzt
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
                            //Legt die +2-Karte
                            placeCardByPlayer(drawDeck, placeDeck, plusTwoCard);
                            currentPlayer->playerCards.erase(currentPlayer->playerCards.begin() + plusTwoIndex);
                            plustwo += 2;
                            std::cout << currentPlayer->name << " hat eine " << plusTwoCard->getCardInfo() << " gelegt." << std::endl << std::endl;
                            currentPlayer->laidCards++;
                        }
                        else
                        {
                            std::cout << currentPlayer->name << " muss " << plustwo << " Karten ziehen." << std::endl << std::endl;
                            for (int i = 0; i < plustwo; i++)
                            {
                                drawCard(drawDeck, currentPlayer);
                            }
                            plustwo = 0;
                        }
                    }
                    else if (plusfour) //Überprüfung ob Bot 4 Aufziehen muss durch vorherige +4 karte
                    {
                        //Spieler muss 4 Karten ziehen und darf keine Karte legen
                        
                        std::cout << currentPlayer->name << " muss 4 Karten ziehen." << std::endl << std::endl;
                        for (int i = 0; i < 4; i++)
                        {
                            drawCard(drawDeck, currentPlayer);
                        }
                        plusfour = false;
                    }
                    else //normaler Spielzug ohne einwirkung vorheriger Karten
                    {
                        Card* selectedCard = selectCardBOT(drawDeck, placeDeck, currentPlayer, wishedColor);
                        if (selectedCard != nullptr)
                        {
                            wishedColor = "";
                            placeCardByPlayer(drawDeck, placeDeck, selectedCard);
                            executeAction(selectedCard, reverse, skip, plustwo, plusfour, wishedColor, currentPlayer, specialRules, players);
                            currentPlayer->laidCards++;
                            std::cout << currentPlayer->name << " hat eine " << selectedCard->getCardInfo() << " gelegt." << std::endl;
                            if (selectedCard->color == "schwarz")
                            {
                                std::cout << currentPlayer->name << " hat sich die Farbe " << wishedColor << " gewuenscht." << std::endl;
                            }
                            std::cout << std::endl;
                        }
                        else
                        {
                            std::cout << currentPlayer->name << " hat eine Karte gezogen\n" << std::endl;
                        }
                    }
                }
                else //Spieler am Zug
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
                                drawLine(currentPlayer);
                                showPlaceDeck(placeDeck, wishedColor);
                                drawLine(currentPlayer);
                                std::cout << "Moechtest du deine \"+2\"-Karte legen?" << std::endl
                                    << "Wenn nein, musst du " << plustwo << " Karten ziehen. [y|n]" << std::endl;
                                std::cin >> choice;
                                if (choice == 'y' || choice == 'n')
                                {
                                    correctInput = true;
                                }
                                else
                                {
                                    clearScreen();
                                    std::cout << "Bitte geben Sie y oder n ein." << std::endl;
                                }
                            }
                            if (choice == 'y')
                            {
                                placeCardByPlayer(drawDeck, placeDeck, plusTwoCard);
                                currentPlayer->playerCards.erase(currentPlayer->playerCards.begin() + plusTwoIndex);
                                plustwo += 2;
                                currentPlayer->laidCards++;
                            }
                            else if (choice == 'n')
                            {
                                for (int i = 0; i < plustwo; i++)
                                {
                                    drawCard(drawDeck, currentPlayer);
                                }
                                plustwo = 0;
                            }
                            clearScreen();
                        }
                        else
                        {
                            drawLine(currentPlayer);
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
                        drawLine(currentPlayer);
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
                            executeAction(selectedCard, reverse, skip, plustwo, plusfour, wishedColor, currentPlayer, specialRules, players);
                            currentPlayer->laidCards++;
                        }
                    }
                }
            }

            if (currentPlayer->playerCards.size() == 0) //Spieler ist fertig. Ausgabe mit Platzierung und Berechnung des Scores
            {
                ranking.push_back(currentPlayer);
                std::cout << currentPlayer->name << " ist fertig. Er belegt den " << ranking.size() << ". Platz" << std::endl;

                int a = currentPlayer->laidCards;
                int b = 0;
                for (Player* _player : players)
                {
                    if (_player != currentPlayer)
                    {
                        b += _player->playerCards.size();
                    }
                }
                std::cout << "b: " << b << "; a: " << a << std::endl;

                int newScore = (int)((1.0 / a) * 2000.0) + b;

                currentPlayer->score = newScore;
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
                if (lastPlayer->playerCards.size() > 0)
                {

                    ranking.push_back(lastPlayer);
                    int a = lastPlayer->laidCards + lastPlayer->playerCards.size();
                    lastPlayer->score = (int)((1.0 / a) * 2000.0);
                }
            }
        }
    }

    clearScreen();
    std::cout << "Das Spiel ist zu Ende. Im Folgenden seht ihr die Rangliste des Spiels." << std::endl << std::endl;

    for (int i = 0; i < ranking.size() - 1; i++) // Bestimmung der Rangbonuspunkte
    {
        int rankBoni = 0;
        if (i == 0) rankBoni = 200;
        else if (i == 1) rankBoni = 100;
        else if (i == 2) rankBoni = 50;
        ranking[i]->score += rankBoni;
    }

    int rank = 1;
    for (Player* player : ranking)
    {
        std::cout << rank << ". Platz:\t" << player->name << "\t" << player->score << " Punkte" << std::endl;
        rank++;
    }
    saveScores(players);
    backToMenu();
    clearScreen();
}

void confirmNextPlayer(Player* player) // Erst zum naechsten Spieler wechseln, wenn er bereit ist, damit niemand anderes seine Karten sieht
{
    bool correctInput = false;
    bool save = false;
    bool exitToMenu = false;

    while (!correctInput)
    {
        std::string confirmPlayer;
        std::cout << "Der naechste Spieler ist " << player->name << "." << std::endl << std::endl
            << "Bitte mit [y] bestaetigen, dass gewechselt werden kann." << std::endl
            << "Bitte mit [s] das Speichern des Spiels bestaetigen." << std::endl
            << "Bitte mit [x] das Beenden des Spiels bestaetigen." << std::endl;
        std::cin >> confirmPlayer;

        if (confirmPlayer == "y")
        {
            correctInput = true;
            save = false;
            exitToMenu = false;
        }
        else if (confirmPlayer == "s") {
            correctInput = true;
            save = true;
            exitToMenu = false;
        }
        else if (confirmPlayer == "x") {
            correctInput = true;
            save = false;
            exitToMenu = true;
        }
        else
        {
            std::cout << "Bitte gebe entweder y, s oder x ein." << std::endl;
        }
    }

    if (save) {
        saveGame(player);
        menu();
    }
    else if (exitToMenu) {
        writeSaveGame(4);
        menu();
    }
}

void showPlaceDeck(std::vector<Card*>& placeDeck, std::string wishedColor) //Anzeigen der obersten Karte auf dem Legestapel und der gewunschenen Farbe
{
    Card* shownCard = placeDeck.front();
    std::string shownCardInfo = shownCard->getCardInfo();

    std::cout << "Die aktuell oberste Karte auf dem Legestapel ist: " << shownCardInfo << std::endl;
    printCard(placeDeck.front());
    if (wishedColor != "")
    {
        std::cout << std::endl << "Es wurde sich die Farbe " << wishedColor << " gewuenscht." << std::endl;
    }
}

Card* selectCardBOT(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor) //Bestimmung der Karte, die der Bot legen soll
{
    std::vector<Player*> ranking;
    Card* placeDeckCard = placeDeck.front(); //oberste Karte
    Card* selectedCard = NULL; //output
    bool correctInput = false;
    bool cardDrawn = false;
    int stepcount = 0;
    int priority = 0;
    int index = 0;
    std::vector<int> possibilities;

    if (wishedColor == "")
    {
        //checks possible Cards
        for (Card* card : player->playerCards)
        {
            if (checkCard(placeDeckCard, card, wishedColor))
            {
                possibilities.push_back(stepcount);
            }
            stepcount++;
        }
        stepcount = 0;
        if (!possibilities.empty())
        {
            for (int num : possibilities) //Auswahl der bestehenden Möglichkeiten anhand von Prioritäten.
            {
                if (player->playerCards[num]->color == placeDeckCard->color && player->playerCards[num]->number < 10) // Auswahl gleicher Farbe mit beliebiger Nummer (keine Actionkarte)
                {
                    selectedCard = player->playerCards[num];
                    priority = 3;
                    index = num;
                }
                else if (player->playerCards[num]->number == placeDeckCard->number) // Auswahl gleicher Zahl mit beliebiger Farbe (Auch Actionkarte wenn gleich)
                {
                    if (priority < 3)
                    {
                        selectedCard = player->playerCards[num];
                        priority = 2;
                        index = num;
                    }
                }
                else if (player->playerCards[num]->color == placeDeckCard->color) // Auswahl gleicherfarbiger Actionkarte
                {
                    if (priority < 2)
                    {
                        selectedCard = player->playerCards[num];
                        priority = 1;
                        index = num;
                    }
                }
                else                                                            // Auswahl schwarzer Karte
                {
                    if (priority < 1)
                    {
                        selectedCard = player->playerCards[num];
                        priority = 0;
                        index = num;
                    }
                }
            }
        }
        else //Wenn keine Karte möglich ist, Karte aufziehen. Wenn diese Legbar ist, wird sie gelegt
        {
            drawCard(drawDeck, player);
            if (checkCard(placeDeckCard, player->playerCards[player->playerCards.size() - 1], wishedColor))
            {
                selectedCard = player->playerCards[player->playerCards.size() - 1];
                index = player->playerCards.size() - 1;
            }
        }
    }
    else //Wenn sich eine andere Farbe gewuenscht wurde, dann wird nur auf diese Farbe überprüft
    {
        for (Card* card : player->playerCards)
        {
            if (card->color == wishedColor)
            {
                selectedCard = card;
                index = stepcount;
            }
            stepcount++;
        }
        stepcount = 0;

        if (selectedCard == NULL) //Wenn keine Karte möglich ist, Karte aufziehen. Wenn diese Legbar ist, wird sie gelegt
        {
            drawCard(drawDeck, player);
            if (checkCard(placeDeckCard, player->playerCards[player->playerCards.size() - 1], wishedColor))
            {
                selectedCard = player->playerCards[player->playerCards.size() - 1];
                index = player->playerCards.size() - 1;
            }
        }
    }
    player->playerCards.erase(player->playerCards.begin() + index);
    return selectedCard;
}

Card* selectCard(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Player* player, std::string wishedColor) //Spieler wählt zu legende Karte aus
{
    std::vector<Player*> ranking;
    Card* placeDeckCard = placeDeck.front();
    Card* selectedCard;
    bool correctInput = false;
    bool cardDrawn = false;
    int selection;
    while (!correctInput)
    {
        drawLine(player);
        showPlaceDeck(placeDeck, wishedColor);
        drawLine(player);
        std::cout << "Deine Karten: " << std::endl;
        printPlayerCards(player->playerCards);
        drawLine(player);
        std::cout << "Bitte waehle die Karte, die gelegt werden soll." << std::endl;
        int index = 0;
        for (Card* card : player->playerCards)
        {
            std::string cardInfo = card->getCardInfo();
            std::cout << "[" << index + 1 << "]\t" << cardInfo << std::endl;
            index++;
        }

        if (!cardDrawn) //Wenn keine Karte gezogen wurde, kann der Spieler noch eine ziehen
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
            clearScreen();
            drawLine(player);
            std::cout << "Aktueller Spieler: " << player->name << std::endl;
            continue;
        }
        else if (selection == player->playerCards.size() + 1 && cardDrawn)
        {
            clearScreen();
            return NULL;
        }
        else
        {
            // Karte legen
            selection--;

            // std::cout << "Ausgewaehlte Karte: " << player->playerCards[selection]->color << " + " << player->playerCards[selection]->number << std::endl;

            selectedCard = player->playerCards[selection];

            // Ueberpruefen, ob Karte gelegt werden darf.
            correctInput = checkCard(placeDeckCard, selectedCard, wishedColor);

            if (!correctInput)
            {
                clearScreen();
                std::cout << "Diese Karte kann nicht auf der Karte, die auf dem Ablegestapel liegt, abgelegt werden." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                drawLine(player);
                std::cout << "Aktueller Spieler: " << player->name << std::endl;
            }
            else
            {
                player->playerCards.erase(player->playerCards.begin() + selection);
                clearScreen();
                return selectedCard;
            }
        }
    }
    return nullptr;
}

void drawCard(std::vector<Card*>& drawDeck, Player* player) //Oberste Karte vom drawDeck wird gezogen
{
    Card* card = drawDeck.front();
    drawDeck.erase(drawDeck.begin());
    player->playerCards.push_back(card);
}

bool checkCard(Card* stackCard, Card* playerCard, std::string& wishedColor) //Überprüfung ob gewählte Karte gelegt werden darf
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

void placeCardByPlayer(std::vector<Card*>& drawDeck, std::vector<Card*>& placeDeck, Card* card) //Karte von Spieler auf placeDeck legen
{
    /*
    * Karte von Spieler auf placeDeck legen
    * Andere Karte(n) von placeDeck direkt zurueck auf drawDeck legen und diesen dann auch direkt mischeln
    */
    Card* old_card = placeDeck.front();
    placeDeck.erase(placeDeck.begin());
    placeDeck.push_back(card);
    if (!actualPlaceDeck.empty()) {
        actualPlaceDeck.erase(actualPlaceDeck.begin());
    }
    actualPlaceDeck.push_back(card);
    drawDeck.push_back(old_card);
    shuffleDeck(drawDeck);
}

void executeAction(Card* card, bool& reverse, bool& skip, int& plustwo, bool& plusfour, std::string& wishedColor, Player* currentPlayer, bool specialRules, std::vector<Player*>& players) //Ausführung von Actionkarten
{
    //Aktionen von Actionkarten werden ausgeführt
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
            if (specialRules)
            {
                std::vector<Card*> tempCards;
                int shownIndex = 0;
                int trueIndex = 0;
                std::vector<int> cardCounts;
                std::vector<int> indices;
                switch (number)
                {
                case 0:
                    if (reverse)
                    {
                        tempCards = players[0]->playerCards;
                        for (int i = 0; i < players.size() - 1; i++)
                        {
                            players[i]->playerCards = players[i + 1]->playerCards;
                        }
                        players[players.size() - 1]->playerCards = tempCards;
                    }
                    else
                    {
                        tempCards = players[players.size() - 1]->playerCards;
                        for (int i = players.size() - 1; i > 0; i--)
                        {
                            players[i]->playerCards = players[i - 1]->playerCards;
                        }
                        players[0]->playerCards = tempCards;
                    }

                    std::cout << "Die Karten jedes Spielers wurden in Spielrichtung weitergegeben." << std::endl;
                    break;
                case 7:

                    for (Player* player : players)
                    {
                        if (currentPlayer->name != player->name)
                        {
                            std::cout << "[" << shownIndex + 1 << "] " << player->name << " hat " << countCards(player) << " Karten" << std::endl;
                            cardCounts.push_back(countCards(player));
                            indices.push_back(trueIndex);
                            shownIndex++;
                        }
                        trueIndex++;
                    }
                    if (currentPlayer->bot)
                    {
                        int choice = cardCounts[0];
                        for (int i = 0; i < cardCounts.size(); i++)
                        {
                            if (choice < cardCounts[i])
                            {
                                choice = cardCounts[i];
                            }
                        }
                        //Fuer jeden Spieler wird ueberprueft ob Choice der Kartenzahl des Spielers uebereinstimmt und der gewaehlte Spieler nicht der aktuelle spieler ist.
                        for (Player* player : players)
                        {
                            if (choice == countCards(player) && player != currentPlayer)
                                swapCards(currentPlayer, players[indices[0]]);
                        }
                    }
                    else
                    {
                        int selection;
                        std::cout << "Mit welchem Spieler moechtest du deine Karten tauschen?" << std::endl;
                        std::cin >> selection;

                        switch (selection)
                        {
                        case 1:
                            swapCards(currentPlayer, players[indices[0]]);
                            break;
                        case 2:
                            swapCards(currentPlayer, players[indices[1]]);
                            break;
                        case 3:
                            swapCards(currentPlayer, players[indices[2]]);
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
    else
    {
        switch (number)
        {
        case 0: wishColor(wishedColor, currentPlayer);
            break;
        case 1: wishColor(wishedColor, currentPlayer);
            plusfour = true;
            break;
        default:
            break;
        }
    }
}

int countCards(Player* player) //Zählt die Anzahl an Karten die ein Spieler hat
{
    int count = 0;
    for (Card* card : player->playerCards)
    {
        count++;
    }
    return count;
}

void swapCards(Player* player1, Player* player2) //tauscht die Karten zweier Spieler
{
    std::vector<Card*> tempCards;
    tempCards = player1->playerCards;
    player1->playerCards = player2->playerCards;
    player2->playerCards = tempCards;
}

void wishColor(std::string& newColor, Player* player) //Farbauswahl nach legen einer Farbwahlkarte
{
    if (!player->bot)
    {
        char selection;
        bool correctInput = false;
        while (!correctInput)
        {
            drawLine(player);
            std::cout << "Deine Karten: " << std::endl;
            printPlayerCards(player->playerCards);
            drawLine(player);
            for (Card* card : player->playerCards)
            {
                std::cout << " - " << card->getCardInfo() << std::endl;
            }
            drawLine(player);
            std::cout << std::endl << "Bitte waehle die Farbe, die du dir wuenschst." << std::endl
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
                clearScreen();
                std::cout << "Bitte geben Sie eine gueltige Eingabe ein." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        wishedColorSave = newColor;
    }
    else //Bot entscheidet nach Kriterium wieviele Karten er von welcher Fare hat
    {
        int reds = 0;
        int blues = 0;
        int greens = 0;
        int yellows = 0;
        int choice = 0;
        for (Card* card : player->playerCards)
        {
            if (card->color == "rot") reds++;
            else if (card->color == "blau") blues++;
            else if (card->color == "gruen") greens++;
            else if (card->color == "gelb") yellows++;
        }
        //Auswahl von welcher Farbe der Bot am meisten hat
        std::vector<int> colors = { reds, blues, greens, yellows };

        for (int i = 0; i < colors.size(); i++)
        {
            if (choice <= colors[i])
            {
                choice = colors[i];
            }
        }

        if (choice == reds) newColor = "rot";
        else if (choice == blues) newColor = "blau";
        else if (choice == greens) newColor = "gruen";
        else if (choice == yellows) newColor = "gelb";
        wishedColorSave = newColor;
    }
    clearScreen();
}

void backToMenu() //Gibt "Zum Menu zurück" Punkt aus und wartet auf eingabe
{
    char selection;
    std::cout << std::endl << std::endl
        << "[m] Zum Menue zurueckkehren" << std::endl
        << "[ELSE] Beenden" << std::endl;
    std::cin >> selection;
    clearScreen();
    if (selection == 'm')
    {
        menu();
    }
}

void saveScores(std::vector<Player*>& players)
{
    bool correctinput = false;
    char selection;
    while (!correctinput)
    {
        std::cout << std::endl << "Moechtest du die Scores speichern? [y|n]" << std::endl;
        std::cin >> selection;
        if (selection == 'y' || selection == 'n')
        {
            correctinput = true;
        }
        else
        {
            std::cout << "Bitte gebe eine gueltige Eingabe ein." << std::endl;
        }
    }
    if (selection == 'y')
    {
        std::map<int, std::string> ranking;

        std::string strSplitter = ";";
        int MAX_POINTS = 0;

        std::string line;
        std::ifstream scoreFileRead("Scores.txt");
        if (scoreFileRead.is_open())
        {
            while (getline(scoreFileRead, line))
            {
                std::string pointsStr = line.substr(0, line.find(strSplitter));
                int points = atoi(pointsStr.c_str());
                if (points > MAX_POINTS)
                {
                    points = MAX_POINTS;
                }
                line.erase(0, line.find(strSplitter) + strSplitter.length());
                ranking[points] = line;
            }
            scoreFileRead.close();
        }


        for (Player* player : players)
        {
            if (!player->bot)
            {
                if (player->score > MAX_POINTS)
                {
                    MAX_POINTS = player->score;
                }
                std::string info = player->name;
                if (ranking[player->score] != "")
                {
                    ranking[player->score] = ranking[player->score] + ", " + info;
                }
                else
                {
                    ranking[player->score] = info;
                }
            }
        }

        std::ofstream scoreFileWrite;
        scoreFileWrite.open("Scores.txt");
        if (scoreFileWrite.is_open())
        {
            for (int i = MAX_POINTS; i >= 0; i--)
            {
                if (ranking[i] != "")
                {
                    scoreFileWrite << i << strSplitter << ranking[i];
                }
            }
            scoreFileWrite.close();
        }
    }
}

void showRanking()
{
    clearScreen();
    std::map<int, std::string> ranking;

    std::string strSplitter = ";";
    int MAX_POINTS = 0;

    std::string line;
    std::ifstream scoreFileRead("Scores.txt");
    if (scoreFileRead.is_open())
    {
        while (getline(scoreFileRead, line))
        {
            if (line != "")
            {
                std::string pointsStr = line.substr(0, line.find(strSplitter));
                int points = atoi(pointsStr.c_str());
                if (points > MAX_POINTS)
                {
                    MAX_POINTS = points;
                }
                line.erase(0, line.find(strSplitter) + strSplitter.length());
                ranking[points] = line;
            }
        }
        scoreFileRead.close();
    }

    int rank = 1;

    for (int i = MAX_POINTS; i >= 0; i--)
    {
        if (ranking[i] == "")
        {
        }
        else
        {
            std::cout << i << ": " << ranking[i] << std::endl;
        }
        rank++;
    }
    backToMenu();
}

void saveGame(Player* player) //Auswahl von Spielstand auf welchem gespeichert werden soll
{
    int selection;

    std::cout
        << "Waehle den gewuenschten Speicherstand aus." << std::endl
        << "[1]\t Speicherstand 1" << std::endl
        << "[2]\t Speicherstand 2" << std::endl
        << "[3]\t Speicherstand 3" << std::endl
        << "[4]\t Zurueck zum Spiel" << std::endl;

    std::cin >> selection;

    switch (selection)
    {
    case 1: writeSaveGame(selection);
        break;
    case 2: writeSaveGame(selection);
        break;
    case 3: writeSaveGame(selection);
        break;
    case 4: confirmNextPlayer(player);
        break;
    default:
        std::cout << "Couldn´t resolve action." << std::endl;
        return;
    }
    deleteSaveGame("./savegames/antiragequitsave.txt");
}

void writeSaveGame(int selection) {
    /*
        * Hier wird der aktuelle Spielstand gespeichert
        * Dazu werden Informationen ueber Spieler, deren Karten, der Karten in der Mitte und der Karten auf den Ziehstapel gesichert
        * Fuer die Speicherstruktur dient eine csv-Datei
        */

    std::ofstream scoresFile;
    int lines;

    switch (selection)
    {
    case 1:
        scoresFile.open("./savegames/savegame1.txt");
        break;
    case 2:
        scoresFile.open("./savegames/savegame2.txt");
        break;
    case 3:
        scoresFile.open("./savegames/savegame3.txt");
        break;
    case 4:
        scoresFile.open("./savegames/antiragequitsave.txt");
        break;
    default:
        std::cout << "Can´t open file." << std::endl;
        break;
    }

    //Angaben, wie viele Zeilen vorhanden sind
    lines = playerAmountSave + 2;

    scoresFile << lines << std::endl;

    //Speichern der Playerinfo
    for (int i = 0; i < playerAmountSave; i++) {
        scoresFile << playerScore[i]->id << std::endl;
        scoresFile << playerScore[i]->bot << std::endl;
        scoresFile << playerScore[i]->name << std::endl;
        scoresFile << playerScore[i]->laidCards << std::endl;
        scoresFile << playerScore[i]->hasPlusTwo << std::endl;
        scoresFile << playerScore[i]->hasPlusFour << std::endl;
        std::vector<Card*> playerScoreCards;
        if (!playerScoreCards.empty()) {
            playerScoreCards.clear();
        }
        playerScoreCards = playerScore[i]->playerCards;
        for (int j = 0; j < playerScoreCards.size(); j++) {
            scoresFile << playerScoreCards[j]->number << ",";
        }
        scoresFile << std::endl;
        for (int j = 0; j < playerScoreCards.size(); j++) {
            scoresFile << playerScoreCards[j]->color << ",";
        }
        scoresFile << std::endl;
    }

    //Speichern des Legestapels
    scoresFile << actualPlaceDeck[0]->number << std::endl;
    scoresFile << actualPlaceDeck[0]->color << std::endl;
    if (actualPlaceDeck[0]->color == "schwarz")
    {
        scoresFile << wishedColorSave << std::endl;
    }

    //Speichern des Ziehstapels
    for (int i = 0; i < actualDrawDeck.size(); i++) {
        scoresFile << actualDrawDeck[i]->number << ",";
    }
    scoresFile << std::endl;
    for (int i = 0; i < actualDrawDeck.size(); i++) {
        scoresFile << actualDrawDeck[i]->color << ",";
    }
    scoresFile << std::endl;

    //Speichern der PlayerID des Spielers der nach dem Speichern folgen würde
    scoresFile << actualPlayerID << std::endl;

    //Speichern ob Specialrules aktiviert sind
    scoresFile << rulesActive << std::endl;

    scoresFile.close();
}

void loadSaveGame() //Auswahl welcher Spielstand geladen werden soll
{
    bool correctInput = false;
    int selection;
    std::string sg1 = "./savegames/savegame1.txt";
    std::string sg2 = "./savegames/savegame2.txt";
    std::string sg3 = "./savegames/savegame3.txt";

    std::cout << "Waehle den gewuenschten Speicherstand aus." << std::endl;

    if (fileEmpty(sg1))
        std::cout << "[1]\t Speicherstand 1 [leer]" << std::endl;
    else
        std::cout << "[1]\t Speicherstand 1 [voll]" << std::endl;

    if (fileEmpty(sg2))
        std::cout << "[2]\t Speicherstand 2 [leer]" << std::endl;
    else
        std::cout << "[2]\t Speicherstand 2 [voll]" << std::endl;

    if (fileEmpty(sg3))
        std::cout << "[3]\t Speicherstand 3 [leer]" << std::endl;
    else
        std::cout << "[3]\t Speicherstand 3 [voll]" << std::endl;

    std::cout << "[4]\t Spielstand loeschen" << std::endl;
    std::cout << "[5]\t Zurueck zum Menue" << std::endl;

    while (!correctInput)
    {
        std::cin >> selection;
        switch (selection)
        {
        case 1:
            if (!fileEmpty(sg1))
            {
                readSaveGame(selection);
                correctInput = true;
            }
            else
            {
                std::cout << "==========================================" << std::endl
                    << "Spielstand leer. Waehle einen anderen aus." << std::endl
                    << "==========================================" << std::endl;
                loadSaveGame();
            }
            break;
        case 2:
            if (!fileEmpty(sg2))
            {
                readSaveGame(selection);
                correctInput = true;
            }
            else
            {
                std::cout << "==========================================" << std::endl
                    << "Spielstand leer. Waehle einen anderen aus." << std::endl
                    << "==========================================" << std::endl;
                loadSaveGame();
            }
            break;
        case 3:
            if (!fileEmpty(sg3))
            {
                readSaveGame(selection);
                correctInput = true;
            }
            else
            {
                std::cout << "==========================================" << std::endl
                    << "Spielstand leer. Waehle einen anderen aus." << std::endl
                    << "==========================================" << std::endl;
                loadSaveGame();
            }
            break;
        case 4:
            deleteSelection();
            correctInput = true;
            break;
        case 5:
            clearScreen();
            menu();
            correctInput = true;
            break;
        default:
            std::cout << "Couldn´t resolve action." << std::endl;
            break;
        }
    }
}

void readSaveGame(int selection) //Liest Speicherstände aus
{

    if (!playerDeckLoad.empty()) 
    {
        playerDeckLoad.clear();
    }
    if (!playerScoreLoad.empty()) 
    {
        playerScoreLoad.clear();
    }
    if (!cardColor.empty()) 
    {
        cardColor.clear();
    }
    if (!cardNumber.empty()) 
    {
        cardNumber.clear();
    }


    std::ifstream readScore;
    char mychar;
    bool rules = false;
    std::string reading;
    std::string rd;

    switch (selection)
    {
    case 1:
        readScore.open("./savegames/savegame1.txt");
        break;
    case 2:
        readScore.open("./savegames/savegame2.txt");
        break;
    case 3:
        readScore.open("./savegames/savegame3.txt");
        break;
    case 4:
        readScore.open("./savegames/antiragequitsave.txt");
        break;
    default:
        std::cout << "Can´t open file." << std::endl;
        break;
    }
    if (readScore.is_open()) {

        //Spieleranzahl ermitteln
        getline(readScore, reading);
        int players = atoi(reading.c_str());
        players = players - 2;

        int id;
        bool bot;
        int laidCards;
        int plusTwo;
        bool plusFour;
        std::string botstate;
        std::string name;
        std::string line;
        std::string delimiter_char = ",";
        std::string token;
        size_t pos = 0;

        for (int i = 0; i < players; i++)
        {
            //Lesen der Spielerinformationen
            Player* player = new Player;

            getline(readScore, reading);
            id = atoi(reading.c_str());
            player->id = id;

            getline(readScore, reading);
            botstate = reading;
            player->bot = resolve(botstate);

            getline(readScore, reading);
            name = reading;
            player->name = name;

            getline(readScore, reading);
            laidCards = atoi(reading.c_str());
            player->id = laidCards;

            getline(readScore, reading);
            plusTwo = atoi(reading.c_str());
            player->hasPlusTwo = plusTwo;
            plustwoLoad = plusTwo;

            getline(readScore, reading);
            std::string hasPlusFour = reading;
            player->hasPlusFour = resolve(hasPlusFour);

            //Lesen der Karteninformationen für den Spieler 0
            //Lesen der Kartennummern
            getline(readScore, line);
            while ((pos = line.find(delimiter_char)) != std::string::npos) {
                token = line.substr(0, pos);
                //einzelne Teile des gelesenen und aufgeteilten
                int number = atoi(token.c_str());
                cardNumber.push_back(number);
                line.erase(0, pos + delimiter_char.length());
            }
            //Lesen der Kartenfarbe
            getline(readScore, line);
            while ((pos = line.find(delimiter_char)) != std::string::npos) {
                token = line.substr(0, pos);
                cardColor.push_back(token);
                line.erase(0, pos + delimiter_char.length());
            }
            //Speichern der Farbe und Nummer in playerDeckLoad
            for (int i = 0; i < cardNumber.size(); i++) {
                Card* card = new Card;
                card->color = cardColor[i];
                card->number = cardNumber[i];
                playerDeckLoad.push_back(card);
            }
            //Speichern der Spieler
            player->playerCards = playerDeckLoad;
            playerScoreLoad.push_back(player);

            //Bevor der nächste Spieler eingelesen werden kann, muss jeder Vektor gecleart werden
            if (!playerDeckLoad.empty()) {
                playerDeckLoad.clear();
            }
            if (!cardColor.empty()) {
                cardColor.clear();
            }
            if (!cardNumber.empty()) {
                cardNumber.clear();
            }
        }

        if (!cardColor.empty()) {
            cardColor.clear();
        }
        if (!cardNumber.empty()) {
            cardNumber.clear();
        }
        if (!drawDeckLoad.empty()) {
            drawDeckLoad.clear();
        }

        //Placedeck
        //Lesen der Kartennummern
        Card* card = new Card;
        getline(readScore, line);
        int number = atoi(line.c_str());
        card->number = number;
        //Lesen der Kartenfarbe
        getline(readScore, line);
        card->color = line;
        placeDeckLoad.push_back(card);

        //Wunschfarbe
        if (card->color == "schwarz")
        {
            getline(readScore, line);
            wishedColorSave = line;
        }

        //Drawdeck
        //Lesen der Kartennummern
        getline(readScore, line);
        while ((pos = line.find(delimiter_char)) != std::string::npos) {
            token = line.substr(0, pos);
            int number = atoi(token.c_str());
            cardNumber.push_back(number);
            line.erase(0, pos + delimiter_char.length());
        }
        //Lesen der Kartenfarbe
        getline(readScore, line);
        while ((pos = line.find(delimiter_char)) != std::string::npos) {
            token = line.substr(0, pos);
            cardColor.push_back(token);
            line.erase(0, pos + delimiter_char.length());
        }

        //Füllen des Ziehstapels
        for (int i = 0; i < cardNumber.size(); i++) {
            Card* card = new Card;
            card->color = cardColor[i];
            card->number = cardNumber[i];
            drawDeckLoad.push_back(card);
        }

        //Lesen der PlayerID für ersten Spieler nach dem Laden
        getline(readScore, line);
        int pID = atoi(line.c_str());
        startPlayerID = pID;

        //Lesen ob special rules aktiv sind
        getline(readScore, reading);
        std::string rules = reading;
        rulesActive = resolve(rules);

    }
    readScore.close();
    if (rulesActive) {
        std::cout << "============================" << std::endl;
        std::cout << "special rules sind aktiviert" << std::endl;
        std::cout << "============================" << std::endl;
    }
    game(drawDeckLoad, placeDeckLoad, playerScoreLoad, rulesActive, wishedColorSave);

    for (Card* card : drawDeckLoad)
    {
        delete card;
    }
    for (Card* card : playerDeckLoad)
    {
        delete card;
    }
}

void deleteSelection() //Auswahl welcher Spielstand gelöscht werden soll
{
    int selection;
    int index = 1;
    std::string sg1 = "./savegames/savegame1.txt";
    std::string sg2 = "./savegames/savegame2.txt";
    std::string sg3 = "./savegames/savegame3.txt";

    if (fileEmpty(sg1) && fileEmpty(sg2) && fileEmpty(sg3))
    {
        std::cout << "Alle Spielstaende sind bereits leer" << std::endl;
        backToMenu();
    }
    else {
        std::cout << "Welcher Spielstand soll geloescht werden?" << std::endl;

        if (!fileEmpty(sg1))
        {
            std::cout << "[1]\t Speicherstand 1" << std::endl;
            index++;
        }
        if (!fileEmpty(sg2))
        {
            std::cout << "[2]\t Speicherstand 2" << std::endl;
            index++;
        }
        if (!fileEmpty(sg3))
        {
            std::cout << "[3]\t Speicherstand 3" << std::endl;
        }


        std::cin >> selection;
        switch (selection)
        {
        case 1:
            deleteSaveGame(sg1);
            std::cout << "Spielstand 1 erfolgreich geloescht." << std::endl;
            break;
        case 2:
            deleteSaveGame(sg2);
            std::cout << "Spielstand 2 erfolgreich geloescht." << std::endl;
            break;
        case 3:
            deleteSaveGame(sg3);
            std::cout << "Spielstand 3 erfolgreich geloescht." << std::endl;
            break;
        default:
            break;
        }
        loadSaveGame();
    }
}

void printCard(Card* card) //Gibt einzelne Karte grafisch aus
{
    std::ifstream f("Cards.txt");
    std::string reading;

    if (f.is_open())
    {
        while (getline(f, reading))
        {
            if (reading == card->getCardInfo())
            {
                for (int i = 0; i < 8; i++)
                {
                    getline(f, reading);
                    std::cout << reading << std::endl;
                }
                f.close();

            }
        }
    }
    else
    {
        std::cout << "File not found." << std::endl;
    }
}

void printPlayerCards(std::vector<Card*> playerCards) //Gibt alle Karten eines Spielers grafisch aus
{
    std::ifstream f;
    std::string reading;
    std::vector<int> rows;
    int count = 0;

    for (int i = 0; i < playerCards.size(); i++)
    {
        if (count < 7)
        {
            f.open("Cards.txt", std::ios::in);
            int rowNumber = 0;
            bool foundCard = false;

            while (!f.eof() && !foundCard)
            {
                getline(f, reading);
                Card* card = playerCards[i];

                if (reading == card->getCardInfo())
                {
                    getline(f, reading);
                    std::cout << reading << " ";
                    rows.push_back(rowNumber);
                    foundCard = true;
                    f.close();
                }
                rowNumber++;
            }
            count++;
            f.close();
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < rows.size(); j++)
        {
            f.open("Cards.txt", std::ios::in);
            for (int k = 0; k < rows[j] + 2; k++)
            {
                getline(f, reading);
            }
            rows[j] = rows[j] + 1;
            getline(f, reading);
            std::cout << reading << " ";
            f.close();
        }
        std::cout << std::endl;
    }

    if (playerCards.size() > 7)
    {
        for (int i = 0; i < 7; i++)
        {
            playerCards.erase(playerCards.begin());
        }
        printPlayerCards(playerCards);
    }

}

bool resolve(std::string in)
{
    bool op;
    if (in == "1") {
        op = true;
    }
    else if (in == "0") {
        op = false;
    }
    return op;
}

bool fileEmpty(std::string filePath) //Überprüft ob Datei in Pfad leer ist
{
    std::ifstream readScore;
    std::string reading;
    readScore.open(filePath);
    bool isEmpty = true;
    while (!readScore.eof())
    {
        getline(readScore, reading);
        if (!reading.empty())
        {
            isEmpty = false;
        }
    }
    readScore.close();
    return isEmpty;
}

void deleteSaveGame(std::string filePath) //Löscht Spielstand in Pfad
{
    std::ofstream scoresFile;
    scoresFile.open(filePath);
    scoresFile.clear();
    scoresFile.close();
}

void drawLine(Player* player) //Gibt Linie von Länge der Anzahl an Karten aus
{
    if (player != NULL)
    {
        int cards = player->playerCards.size();
        int linelength = 0;
        if (cards < 7) linelength = 13 * cards - 1;
        else linelength = 13 * 7 - 1;

        for (int i = 0; i < linelength; i++) std::cout << "=";
        std::cout << std::endl;
    }
    else
    {
        for (int i = 0; i < 50; i++) std::cout << "=";
        std::cout << std::endl;
    }
}

void clearScreen() //Cleart die Konsole
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}
