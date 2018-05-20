// Libraries

#include <ctime>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Functions implemented by Back Team

void createChampions();
void createTeam();
void createEnemy();
void addTeammate();
void randomizeChampion(vector<string> &vector);
int randomizeIndex();
void moveChampion(vector<string> &srcVector, vector<string> &destVector, int index);
void addChampion(vector<string> &srcVector, vector<string> &destVector, int index);
void removeChampion(vector<string> &vector, int index);
int calDamageWithAdvantage(string damage, string attackerClass, string defenderClass);
vector<string> generateAttributesOfChampions(string str);

// Functions implemented by Front Team

string split(string word, char characterToBreak);
void battleLost();
void gameWon();
void specifyChampions(vector <string> champions);
void startGame();
void menu();


int main() {
    menu();
    return 0;
}

/*     -------         BACK IMPLEMENTATIONS      --------    */

// Populate the `champions` vector
void createChampions() {
    champions.push_back("Cosmic.Thanos.250.60.120.40");
    champions.push_back("Cosmic.Thor.200.50.100.30");
    champions.push_back("Mutant.Deadpool.200.50.100.30");
    champions.push_back("Mutant.Wolverine.200.50.100.30");
    champions.push_back("Mystic.Doctor Strange.200.50.100.30");
    champions.push_back("Mystic.Loki.200.50.100.30");
    champions.push_back("Science.Captain America.200.50.100.30");
    champions.push_back("Science.Spider-Man.200.50.100.30");
    champions.push_back("Skill.Black Panther.200.50.100.30");
    champions.push_back("Skill.Winter Soldier.200.50.100.30");
    champions.push_back("Tech.Iron Man.200.50.100.30");
    champions.push_back("Tech.Ultron.200.50.100.30");
}

// Randomize three champions from the `champions` vector and move them to the `team` vector
void createTeam() {
    for (int i = 0; i < 3; ++i) {
        randomizeChampion(team);
    }
}

// Randomize a champion from the `champions` vector and move him/her to the `enemy` vector
void createEnemy() {
    randomizeChampion(enemy);
}

// Move the defeated enemy to the `team` vector
void addTeammate() {
    moveChampion(enemy, team, 0);
}

// Randomize a champion from the `champions` vector and move him/her to a vector
void randomizeChampion(vector<string> &vector) {
    int index = randomizeIndex();
    moveChampion(champions, vector, index);
}

// Randomize an index from the `champions` vector
int randomizeIndex() {
    srand(time(nullptr));
    return rand() % (champions.size() - 1);
}

// Move a champion from the n-th index on `source vector` to the `destination vector`
void moveChampion(vector<string> &srcVector, vector<string> &destVector, int index) {
    addChampion(srcVector, destVector, index);
    removeChampion(srcVector, index);
}

// Add a champion from the n-th index on `source vector` to the `destination vector`
void addChampion(vector<string> &srcVector, vector<string> &destVector, int index) {
    destVector.push_back(srcVector.at(index));
}

// Remove a champion from the n-th position on a vector
void removeChampion(vector<string> &vector, int index) {
    vector.erase(vector.begin() + index);
}

// Calculates the attacker's damage, checking his advantage
int calDamageWithAdvantage(string damage, string attackerClass, string defenderClass) {
    int result = stoi(damage, nullptr);
    if ((attackerClass.compare("Mutant") == 0) && (defenderClass.compare("Skill") == 0)) {
        result *= 1.25;
    } else if ((attackerClass.compare("Skill") == 0) && (defenderClass.compare("Science") == 0)) {
        result *= 1.25;
    } else if ((attackerClass.compare("Science") == 0) && (defenderClass.compare("Mystic") == 0)) {
        result *= 1.25;
    } else if ((attackerClass.compare("Mystic") == 0) && (defenderClass.compare("Cosmic") == 0)) {
        result *= 1.25;
    } else if ((attackerClass.compare("Cosmic") == 0) && (defenderClass.compare("Tech") == 0)) {
        result *= 1.25;
    } else if ((attackerClass.compare("Tech") == 0) && (defenderClass.compare("Mutant") == 0)) {
        result *= 1.25;
    }
    return result;
}

// Splits a Champion's string into a Champion's vector
vector<string> generateAttributesOfChampions(string str) {
    char delim = '.';
    stringstream ss(str);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

//Check if the player has won the game.
bool checkFinalVictory()
{
    if (champions.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check if the player won the battle (partial victory)
bool checkPartialVictory(int hpInimigo)
{
    if (hpInimigo <= 0)
    {
        return true;
    }
    else
    {
       return false;
    }
}

//Check if the player has lost the battle.
bool checkBattleLost(int hp1, int hp2, int hp3)
{
    if (hp1 == 0 && hp2 == 0 && hp3 ==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*     -------         FRONT IMPLEMENTATIONS      --------    */

string split(string word, char characterToBreak) {
    int i;
    string temporaryWord = "";

    for(i = 0; i < word.length(); i++)
    {
        if (word.at(i) == characterToBbreak)
        {
            temporaryWord += " ";
        }
        else
        {
            temporaryWord += word.at(i);
        }
    }
    return temporaryWord;
}

void battleLost()  {

    cout << " $$$$$$\   $$$$$$\  $$\      $$\ $$$$$$$$\        $$$$$$\  $$\    $$\ $$$$$$$$\ $$$$$$$\  " << endl;
    cout << "$$  __$$\ $$  __$$\ $$$\    $$$ |$$  _____|      $$  __$$\ $$ |   $$ |$$  _____|$$  __$$\ " << endl;
    cout << "$$ /  \__|$$ /  $$ |$$$$\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |" << endl;
    cout << "$$ |$$$$\ $$$$$$$$ |$$\$$\$$ $$ |$$$$$\          $$ |  $$ |\$$\  $$  |$$$$$\    $$$$$$$  |" << endl;
    cout << "$$ |\_$$ |$$  __$$ |$$ \$$$  $$ |$$  __|         $$ |  $$ | \$$\$$  / $$  __|   $$  __$$< " << endl;
    cout << "$$ |  $$ |$$ |  $$ |$$ |\$  /$$ |$$ |            $$ |  $$ |  \$$$  /  $$ |      $$ |  $$ |" << endl;
    cout << "\$$$$$$  |$$ |  $$ |$$ | \_/ $$ |$$$$$$$$\        $$$$$$  |   \$  /   $$$$$$$$\ $$ |  $$ |" << endl;
    cout << " \______/ \__|  \__|\__|     \__|\________|       \______/     \_/    \________|\__|  \__|" << endl;

    cout << "\n\nmore luck in the next attempt, if you have the courage..." << endl;

}

void gameWon() {

    cout << "   ___                            _         _       _   _" << endl;
    cout << "  / __\___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___" << endl;
    cout << " / /  / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|" << endl;
    cout << "/ /__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \ " << endl;
    cout << "\____/\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/" << endl;
    cout << "                  |___/" << endl;

    cout << "\n\nYou belong to the glory of the champions!!!" << endl;

}

void specifyChampions(vector <string> champions) {
    int numberOfChampions, i;

    cout << "Meet our champions\n" << endl;

    numberOfChampions = champions.size();



    for(i = 0; i < numberOfChampions; i++)
    {
        if (i < 9)
        {
            cout << "0" << (i + 1) << " - " << split(champions[i], '.') << "\n";
        }
        else
        {
            cout << (i + 1) << " - " << split(champions[i], '.') << "\n";
        }
    }

    cout << endl;

}

void startGame() {

    cout << "\nWelcome to the Colosseum of Champions!!!" << endl;
    cout << "Get ready for a great adventure that could result in your glory..." << endl;
    cout << "...or in its oblivion....\n\n" << endl;

    vector <string> champions;

    createChampions(champions);

    specifyChampions(champions);
}

void menu() {
    string option;

    while(true) {

        cout << "Do you want to play? \n(1) Yes\n(2) No\n\nOption: ";
        cin >> option;

        if (option == "1")
        {
            startGame();
        }
        else if (option == "2")
        {
            break;
        }
        else
        {
            cout << "\nInvalid Option\n" << endl;
        }
    }

    cout << "\nTank You!!!\n\n" << endl;

}







