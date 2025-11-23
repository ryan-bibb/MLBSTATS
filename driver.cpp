// setup
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;
#include "player.h"

// prototypes
void readFile(vector<Player>& playerList);
int menu();
void displayAll(const vector<Player>& playerList);
void displayHitsLeaders(const vector<Player>& playerList);
void displaySinglesLeaders(const vector<Player>& playerList);
void displayDoublesLeaders(const vector<Player>& playerList);
void displayTriplesLeaders(const vector<Player>& playerList);
void displayHomeRunsLeaders(const vector<Player>& playerList);
void displayAVGLeaders(const vector<Player>& playerList);
void displayOBPLeaders(const vector<Player>& playerList);
void displaySLGLeaders(const vector<Player>& playerList);
void displayOPSLeaders(const vector<Player>& playerList);
void displayStolenBasesLeaders(const vector<Player>& playerList);
void searchByName(const vector<Player>& playerList);
void compareTwo(const vector<Player>& playerList);


vector<Player> sortByHits(const vector<Player>& playerList);
vector<Player> sortBySingles(const vector<Player>& playerList);
vector<Player> sortByDoubles(const vector<Player>& playerList);
vector<Player> sortByTriples(const vector<Player>& playerList);
vector<Player> sortByHomeRuns(const vector<Player>& playerList);
vector<Player> sortByAVG(const vector<Player>& playerList);
vector<Player> sortByOBP(const vector<Player>& playerList);
vector<Player> sortBySLG(const vector<Player>& playerList);
vector<Player> sortByOPS(const vector<Player>& playerList);
vector<Player> sortByStolenBases(const vector<Player>& playerList);

int main()
{
	vector<Player> list;
    vector<Player> listHits;
    vector<Player> listSingles;
    vector<Player> listDoubles;
    vector<Player> listTriples;
    vector<Player> listHomeRuns;
    vector<Player> listAVG;
    vector<Player> listSLG;
    vector<Player> listOBP;
    vector<Player> listOPS;
    vector<Player> listStolenBases;
    int choice;

    readFile(list);
    listHits = sortByHits(list);
    listSingles = sortBySingles(list);
    listDoubles = sortByDoubles(list);
    listTriples = sortByTriples(list);
    listHomeRuns = sortByHomeRuns(list);
    listAVG = sortByAVG(list);
    listSLG = sortBySLG(list);
    listOBP = sortByOBP(list);
    listOPS = sortByOPS(list);
    listStolenBases = sortByStolenBases(list);
    
    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            displayAll(list);
            break;
        case 2:
            displayHitsLeaders(listHits);
            break;
        case 3: 
            displaySinglesLeaders(listSingles);
            break;
        case 4:
            displayDoublesLeaders(listDoubles);
            break;
        case 5: 
            displayTriplesLeaders(listTriples);
            break;
        case 6:
            displayHomeRunsLeaders(listHomeRuns);
            break;
        case 7: 
            displayAVGLeaders(listAVG);
            break;
        case 8:
            displayOBPLeaders(listOBP);
            break;
        case 9:
            displaySLGLeaders(listSLG);
            break;
        case 10:
            displayOPSLeaders(listOPS);
            break;
        case 11: 
            displayStolenBasesLeaders(listStolenBases);
            break;
        case 12:
            searchByName(list);
            break;
        case 13:
            compareTwo(list);
            break;
        case 14:
            cout << "Exiting MLB Stat Hub...";
            exit(0);
            break;
        default:
            cout << "Invalid choice entered" << endl;
            break;
        }
    } while (choice != '99');

	return 0;
}

// defintions

int menu()
{
    int choice; 

    cout << "----------MLB STATS HUB----------" << endl
        << "1) Display All Hitters" << endl
        << "2) Display Hits Leaders" << endl
        << "3) Display Singles Leaders" << endl
        << "4) Display Doubles Leaders" << endl
        << "5) Display Triples Leaders" << endl
        << "6) Display Home Run Leaders" << endl
        << "7) Display AVG Leaders" << endl
        << "8) Display OBP Leaders" << endl
        << "9) Display SLG Leaders" << endl
        << "10) Display OPS Leaders" << endl
        << "11) Display Stolen Bases Leaders" << endl
        << "12) Search By Name" << endl
        << "13) Compare Two Players" << endl
        << "14) Exit" << endl
        << "Enter Choice: ";

    while (choice > 13 || choice < 1)
    {
        cout << "Invalid choice...re-enter choice: ";
        cin >> choice;
    }

    return choice;
}

void readFile(vector<Player>& playerList)
{
    // this is the name of my file, change as needed
    ifstream inFile("MLBSTATSUPDATED.txt"); 

    if (!inFile) {
        cerr << "Error: Could not open file!" << endl;
    }

    string line;
    while (getline(inFile, line)) {
        Player player;
        stringstream ss(line);
        string token;

        // Read lastName
        getline(ss, token, ',');
        strcpy_s(player.lastName, token.c_str());

        // Read firstName
        getline(ss, token, ',');
        token.erase(0, token.find_first_not_of(" ")); 
        strcpy_s(player.firstName, token.c_str());

        // Read playerID
        getline(ss, token, ',');
        player.playerID = stoi(token);

        // Read year
        getline(ss, token, ',');
        player.year = stoi(token);

        // Read hits
        getline(ss, token, ',');
        player.hits = stoi(token);

        // Read singles
        getline(ss, token, ',');
        player.singles = stoi(token);

        // Read doubles
        getline(ss, token, ',');
        player.doubles = stoi(token);

        // Read triples
        getline(ss, token, ',');
        player.triples = stoi(token);

        // Read homeRuns
        getline(ss, token, ',');
        player.homeRuns = stoi(token);

        // Read avg
        getline(ss, token, ',');
        player.avg = stod(token);

        // Read slg
        getline(ss, token, ',');
        player.slg = stod(token);

        // Read obp
        getline(ss, token, ',');
        player.obp = stod(token);

        // Read ops
        getline(ss, token, ',');
        player.ops = stod(token);

        // Read stolenBases
        getline(ss, token, ',');
        player.stolenBases = stoi(token);

        playerList.push_back(player);
    }

    inFile.close();
}

void displayAll(const vector<Player>& playerList)
{
    cout << "Players: " << endl;

    for (int i = 0; i < playerList.size(); i++)
    {
        cout << playerList[i].firstName
            << " "
            << playerList[i].lastName
            << endl;
    }
}

// displayLeader functions display the top ten of the given category
void displayHitsLeaders(const vector<Player>& playerList)
{
    cout << "----- Hit Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Hits: "
            << playerList[i].hits << endl;
    }
}

void displaySinglesLeaders(const vector<Player>& playerList)
{
    cout << "----- Singles Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Singles: "
            << playerList[i].singles << endl;
    }
}

void displayDoublesLeaders(const vector<Player>& playerList)
{
    cout << "----- Doubles Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Doubles: "
            << playerList[i].doubles << endl;
    }
}

void displayTriplesLeaders(const vector<Player>& playerList)
{
    cout << "----- Triples Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Triples: "
            << playerList[i].triples << endl;
    }
}

void displayHomeRunsLeaders(const vector<Player>& playerList)
{
    cout << "----- Home Run Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Home Runs: "
            << playerList[i].homeRuns << endl;
    }
}

void displayAVGLeaders(const vector<Player>& playerList)
{
    cout << "----- Batting Average Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " AVG: "
            << playerList[i].avg << endl;
    }
}

void displayOBPLeaders(const vector<Player>& playerList)
{
    cout << "----- On Base Percentage Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " OBP: "
            << playerList[i].obp << endl;
    }
}

void displaySLGLeaders(const vector<Player>& playerList)
{
    cout << "----- Slugging Percentage Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " SLG: "
            << playerList[i].slg << endl;
    }
}

void displayOPSLeaders(const vector<Player>& playerList)
{
    cout << "----- OBP Plus SLG Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " OPS: "
            << playerList[i].ops << endl;
    }
}

void displayStolenBasesLeaders(const vector<Player>& playerList)
{
    cout << "----- Stolen Bases Leaders -----" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << ") "
            << playerList[i].firstName << " "
            << playerList[i].lastName << " Stolen Bases: "
            << playerList[i].stolenBases << endl;
    }
}

// displays all stats of the player that is searched for
void searchByName(const vector<Player>& playerList)
{
    char firstName[50],
        lastName[50];
    bool found = false;

    cout << "Enter Player's Full Name: ";

    cin >> firstName;
    cin >> lastName;;

    for (int i = 0; i < playerList.size(); i++)
    {
        if (strcmp(playerList[i].firstName, firstName) == 0 && strcmp(playerList[i].lastName, lastName) == 0)
        {
            cout << firstName << " " << lastName << endl
                << "Hits: " << playerList[i].hits << endl
                << "Singles: " << playerList[i].singles << endl
                << "Doubles: " << playerList[i].doubles << endl
                << "Triples: " << playerList[i].triples << endl
                << "Home Runs: " << playerList[i].homeRuns << endl
                << "AVG: " << playerList[i].avg << endl
                << "OBP: " << playerList[i].obp << endl
                << "SLG: " << playerList[i].hits << endl
                << "OPS: " << playerList[i].ops << endl
                << "Stolen Bases: " << playerList[i].stolenBases << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Player not found..." << endl;
    }
}

// displays all stats of each player give. An X is places beside the player who is better in that stat
void compareTwo(const vector<Player>& playerList)
{
    Player playerOne;
    Player playerTwo;
    bool foundOne = false, 
        foundTwo = false;
    char firstNameOne[50],
        lastNameOne[50], 
        firstNameTwo[50], 
        lastNameTwo[50];

    cout << "Enter first player's name: ";
    cin >> firstNameOne;
    cin >> lastNameOne;

    cout << "Enter second player's name: ";
    cin >> firstNameTwo;
    cin >> lastNameTwo;

    for (int i = 0; i < playerList.size(); i++)
    {
        if (strcmp(playerList[i].firstName, firstNameOne) == 0 && strcmp(playerList[i].lastName, lastNameOne) == 0)
        {
            playerOne = playerList[i];
            foundOne = true;
        }

        if (strcmp(playerList[i].firstName, firstNameTwo) == 0 && strcmp(playerList[i].lastName, lastNameTwo) == 0)
        {
            playerTwo = playerList[i];
            foundTwo = true;
        }
    }

    if (foundOne && foundTwo)
    {
        cout << "-----Stats VS-----" << endl
            << "Stats\t\t" << playerOne.firstName << " " << playerOne.lastName << "\t" << playerTwo.firstName << " " << playerTwo.lastName << endl;

        if (playerOne.hits > playerTwo.hits)
            cout << "Hits\t\t" << playerOne.hits << " X\t\t\t" << playerTwo.hits << endl;
        else
            cout << "Hits\t\t" << playerOne.hits << "\t\t\t" << playerTwo.hits << " X" << endl;

        if (playerOne.singles > playerTwo.singles)
            cout << "Singles\t\t" << playerOne.singles << " X\t\t\t" << playerTwo.singles << endl;
        else
            cout << "Singles\t\t" << playerOne.singles << "\t\t\t" << playerTwo.singles << " X" << endl;
     
        if (playerOne.doubles > playerTwo.doubles)
            cout << "Doubles\t\t" << playerOne.doubles << " X\t\t\t" << playerTwo.doubles << endl;
        else
            cout << "Doubles\t\t" << playerOne.doubles << "\t\t\t" << playerTwo.doubles << " X" << endl;

        if (playerOne.triples > playerTwo.triples)
            cout << "Triples\t\t" << playerOne.triples << " X\t\t\t" << playerTwo.triples << endl;
        else
            cout << "Triples\t\t" << playerOne.triples << "\t\t\t" << playerTwo.triples << " X" << endl;

        if (playerOne.homeRuns > playerTwo.homeRuns)
            cout << "HR\t\t" << playerOne.homeRuns << " X\t\t\t" << playerTwo.homeRuns << endl;
        else
            cout << "HR\t\t" << playerOne.homeRuns << "\t\t\t" << playerTwo.homeRuns << " X" << endl;
    
        if (playerOne.avg > playerTwo.avg)
            cout << "AVG\t\t" << playerOne.avg << " X\t\t\t" << playerTwo.avg << endl;
        else
            cout << "Singles\t\t" << playerOne.avg<< "\t\t\t" << playerTwo.avg << " X" << endl;

        if (playerOne.obp> playerTwo.obp)
            cout << "OBP\t\t" << playerOne.obp << " X\t\t\t" << playerTwo.obp << endl;
        else
            cout << "OBP\t\t" << playerOne.obp << "\t\t\t" << playerTwo.obp << " X" << endl;

        if (playerOne.slg > playerTwo.slg)
            cout << "SLG\t\t" << playerOne.slg << " X\t\t\t" << playerTwo.slg << endl;
        else
            cout << "SLG\t\t" << playerOne.slg << "\t\t\t" << playerTwo.slg<< " X" << endl;

        if (playerOne.ops > playerTwo.ops)
            cout << "OPS\t\t" << playerOne.ops << " X\t\t\t" << playerTwo.ops << endl;
        else
            cout << "OPS\t\t" << playerOne.ops << "\t\t\t" << playerTwo.ops<< " X" << endl;

        if (playerOne.stolenBases > playerTwo.stolenBases)
            cout << "SB\t\t" << playerOne.stolenBases << " X\t\t\t" << playerTwo.stolenBases << endl;
        else
            cout << "SB\t\t" << playerOne.stolenBases << "\t\t\t" << playerTwo.stolenBases << " X" << endl;
    }
    else
    {
        cout << "Player not found..." << endl;
    }
}

vector<Player> sortByHits(const vector<Player>& playerList)
{
    vector<Player> listHits = playerList;

    sort(listHits.begin(), listHits.end(), [](const Player& a, const Player& b)
        {
            return a.hits > b.hits;
        });

    return listHits;
}

vector<Player> sortBySingles(const vector<Player>& playerList)
{
    vector<Player> listSingles = playerList;

    sort(listSingles.begin(), listSingles.end(), [](const Player& a, const Player& b)
        {
            return a.singles > b.singles;
        });

    return listSingles;
}

vector<Player> sortByDoubles(const vector<Player>& playerList)
{
    vector<Player> listDoubles = playerList;

    sort(listDoubles.begin(), listDoubles.end(), [](const Player& a, const Player& b)
        {
            return a.doubles > b.doubles;
        }
    );

    return listDoubles;
}

vector<Player> sortByTriples(const vector<Player>& playerList)
{
    vector<Player> listTriples = playerList;

    sort(listTriples.begin(), listTriples.end(), [](const Player& a, const Player& b)
        {
            return a.triples > b.triples;
        }
    );

    return listTriples;
}

vector<Player> sortByHomeRuns(const vector<Player>& playerList)
{
    vector<Player> listHomeRuns = playerList;

    sort(listHomeRuns.begin(), listHomeRuns.end(), [](const Player& a, const Player& b)
        {
            return a.homeRuns > b.homeRuns;
        }
    );

    return listHomeRuns;
}

vector<Player> sortByAVG(const vector<Player>& playerList)
{
    vector<Player> listAVG = playerList;

    sort(listAVG.begin(), listAVG.end(), [](const Player& a, const Player& b)
        {
            return a.avg > b.avg;
        }
    );

    return listAVG;
}

vector<Player> sortBySLG(const vector<Player>& playerList)
{
    vector<Player> listSLG = playerList;

    sort(listSLG.begin(), listSLG.end(), [](const Player& a, const Player& b)
        {
            return a.slg > b.slg;
        }
    );

    return listSLG;
}

vector<Player> sortByOBP(const vector<Player>& playerList)
{
    vector<Player> listOBP = playerList;

    sort(listOBP.begin(), listOBP.end(), [](const Player& a, const Player& b)
        {
            return a.slg > b.slg;
        }
    );

    return listOBP;
}

vector<Player> sortByOPS(const vector<Player>& playerList)
{
    vector<Player> listOPS = playerList;

    sort(listOPS.begin(), listOPS.end(), [](const Player& a, const Player& b)
        {
            return a.slg > b.slg;
        }
    );

    return listOPS;
}

vector<Player> sortByStolenBases(const vector<Player>& playerList)
{
    vector<Player> listStolenBases = playerList;

    sort(listStolenBases.begin(), listStolenBases.end(), [](const Player& a, const Player& b)
        {
            return a.stolenBases > b.stolenBases;
        }
    );

    return listStolenBases;
}

