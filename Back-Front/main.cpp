// Libraries

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Functions implemented by Back Team

vector<string> champions;
vector<string> team;
vector<string> enemy;
const int enemyAdavantageMod = 1.5;

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
bool checkFinalVictory();
bool checkPartialVictory(int championHP);
bool checkBattleLost(int firstTeammateHP, int secondTeammateHP, int thirdTeammateHP);

// Functions implemented by Front Team

string split(string word, char characterToBreak);
void battleLost();
void gameWon();
int enemyHpInteger(vector <string> champion);
int teamHpInteger(vector <string> team, int indexOfTeam);
int enemyNormalAtkInteger(vector <string> champion);
int teamNormalAtkInteger(vector <string> team, int indexOfTeam);
int enemySpecialAtkInteger(vector <string> champion);
int teamSpecialAtkInteger(vector <string> team, int indexOfTeam);
int enemyDefenseInteger(vector <string> champion);
int teamDefenseInteger(vector <string> team, int indexOfTeam);
void specifyChampions(vector<string> champions);
void startGame();
void menu();

/*     -------         MAIN EXECUTION      --------    */

int main() {
    menu();
    /*createChampions();
    createTeam();
    specifyChampions(team);*/

    return 0;
}

/*     -------         BACK IMPLEMENTATIONS      --------    */

// Populate the `champions` vector
void createChampions() {
    champions.push_back("Science.Spider-Man.200.33.50.31");
    champions.push_back("Skill.Black Panther.220.38.57.30");
    champions.push_back("Skill.Winter Soldier.240.43.65.29");
    champions.push_back("Science.Captain America.260.48.72.28");
    champions.push_back("Tech.Iron Man.280.53.80.27");
    champions.push_back("Mutant.Wolverine.300.58.87.26");
    champions.push_back("Mutant.Deadpool.320.63.95.25");
    champions.push_back("Mystic.Loki.340.68.102.24");
    champions.push_back("Tech.Ultron.360.73.110.23");
    champions.push_back("Mystic.Doctor Strange.380.78.117.22");
    champions.push_back("Cosmic.Thanos.400.83.125.21");
    champions.push_back("Cosmic.Thor.420.88.132.20");
}


// Randomize three champions from the `champions` vector and move them to the `team` vector
void createTeam() {

    for (int i = 0; i < 3; ++i) {
        srand(time(nullptr));
        int index = rand() % ((champions.size()/2) - 1);
        moveChampion(champions, team, index);
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
    float advantageMod = 1.25;
    if ((attackerClass.compare("Mutant") == 0) && (defenderClass.compare("Skill") == 0)) {
        result *= advantageMod;
    } else if ((attackerClass.compare("Skill") == 0) && (defenderClass.compare("Science") == 0)) {
        result *= advantageMod;
    } else if ((attackerClass.compare("Science") == 0) && (defenderClass.compare("Mystic") == 0)) {
        result *= advantageMod;
    } else if ((attackerClass.compare("Mystic") == 0) && (defenderClass.compare("Cosmic") == 0)) {
        result *= advantageMod;
    } else if ((attackerClass.compare("Cosmic") == 0) && (defenderClass.compare("Tech") == 0)) {
        result *= advantageMod;
    } else if ((attackerClass.compare("Tech") == 0) && (defenderClass.compare("Mutant") == 0)) {
        result *= advantageMod;
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
bool checkFinalVictory() {
    return champions.size() == 0;
}

//Check if the player won the battle (partial victory)
bool checkPartialVictory(int championHP) {
    return championHP <= 0;
}

//Check if the player has lost the battle.
bool checkBattleLost(int firstTeammateHP, int secondTeammateHP, int thirdTeammateHP) {
    return checkPartialVictory(firstTeammateHP) && checkPartialVictory(secondTeammateHP) && checkPartialVictory(thirdTeammateHP);
}

/*     -------         FRONT IMPLEMENTATIONS      --------    */

string split(string word, char characterToBbreak) {
    int i;
    string temporaryWord = "";

    int countSpace = 0;

    for(i = 0; i < word.length(); i++)
    {
        if (word.at(i) == characterToBbreak)
        {
            temporaryWord += " ";
            countSpace ++;
            if (countSpace == 2)
            {
                break;
            }
        }
        else
        {
            temporaryWord += word.at(i);
        }
    }
    return temporaryWord;
}


void battleLost() {

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

void specifyChampions(vector<string> champions) {
    int numberOfChampions, i;

    numberOfChampions = champions.size();

    for (i = 0; i < numberOfChampions; i++) {
        if (i < 9) {
            cout << "0" << (i + 1) << " - " << split(champions[i], '.') << "\n";
        } else {
            cout << (i + 1) << " - " << split(champions[i], '.') << "\n";
        }
    }

    cout << endl;
}

int teamHpInteger(vector <string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 2)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}


int enemyHpInteger(vector <string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 2)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamNormalAtkInteger(vector <string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 3)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemyNormalAtkInteger(vector <string> champion)  {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 3)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamSpecialAtkInteger(vector <string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 4)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemySpecialAtkInteger(vector <string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 4)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}


int enemyDefenseInteger(vector <string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 5)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamDefenseInteger(vector <string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for(i = 0; i < numberStr.length(); i++)
    {
        if (counts == 5)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

void fight() {
    int hpEnemy = enemyHpInteger(enemy);

    int hpFighter1 = teamHpInteger(team, 0);
    int hpFighter2 = teamHpInteger(team, 1);
    int hpFighter3 = teamHpInteger(team, 2);

    int normalAtkEnemy = enemyNormalAtkInteger(enemy);

    int normalAtkFighter1 = teamNormalAtkInteger(team, 0);
    int normalAtkFighter2 = teamNormalAtkInteger(team, 1);
    int normalAtkFighter3 = teamNormalAtkInteger(team, 2);

    int specialAtkEnemy = enemySpecialAtkInteger(enemy);

    int specialAtkFighter1 = teamSpecialAtkInteger(team, 0);
    int specialAtkFighter2 = teamSpecialAtkInteger(team, 1);
    int specialAtkFighter3 = teamSpecialAtkInteger(team, 2);

    int defenseEnemy = enemyDefenseInteger(enemy);

    int defenseFighter1 = teamDefenseInteger(team, 0);
    int defenseFighter2 = teamDefenseInteger(team, 1);
    int defenseFighter3 = teamDefenseInteger(team, 2);

    string option;

    int normalAttackAmount = 0; // conta a quantidade de ataques normais do usuário
    int enemyNormalAttackAmount = 0; // conta a quantidade de ataques normais do enemy

    while (true) {

        if (hpEnemy <= 0 || (hpFighter1 <= 0 && hpFighter2 <= 0 && hpFighter3 <= 0))
            break;
        cout << "What do you want to do?\n(1) Normal Attack\n(2) Special Attack\nOption: ";
        cin >> option;

        if (option == "1") {
            if (hpFighter1 > 0) {
                hpEnemy -= (normalAtkFighter1 - defenseEnemy);
            } else if (hpFighter2 > 0) {
                hpEnemy -= (normalAtkFighter2 - defenseEnemy);
            } else if (hpFighter3 > 0) {
                hpEnemy -= (normalAtkFighter3 - defenseEnemy);
            }
            normalAttackAmount += 1;
        } else if (option == "2") {
            if (normalAttackAmount >= 3) {
                if (hpFighter1 > 0) {
                    hpEnemy -= (specialAtkFighter1 - defenseEnemy);
                } else if (hpFighter2 > 0) {
                    hpEnemy -= (specialAtkFighter2 - defenseEnemy);
                } else if (hpFighter3 > 0) {
                    hpEnemy -= (specialAtkFighter3 - defenseEnemy);
                }
                normalAttackAmount = 0;
        } else {
                cout << "it is not possible to use the special attack" << endl;
            }
        } else {
            cout << "Invalid Option" << endl;
        }

        cout << "\nStatus Enemy Attack" << endl;
        enemyNormalAttackAmount += 1;

        if (enemyNormalAttackAmount <= 3) {
            cout << "Enemy Normal Attack\n" << endl;
            if (hpFighter1 >= 0) {
                hpFighter1 -= normalAtkEnemy - defenseFighter1;
            } else if (hpFighter2 >= 0) {
                hpFighter2 -= normalAtkEnemy - defenseFighter2;
            } else if (hpFighter3 >= 0) {
                hpFighter3 -= normalAtkEnemy - defenseFighter3;
            }

        } else {
            cout << "Enemy Special Attack\n" << endl;
            if (hpFighter1 >= 0) {
                hpFighter1 -= specialAtkEnemy - defenseFighter1;
            } else if (hpFighter2 >= 0) {
                hpFighter2 -= specialAtkEnemy - defenseFighter2;
            } else if (hpFighter3 >= 0) {
                hpFighter3 -= specialAtkEnemy - defenseFighter3;
            }

            enemyNormalAttackAmount = 0;
        }
    }

    gameWon();
}

void startGame() {

    cout << "\nWelcome to the Colosseum of Champions!!!" << endl;
    cout << "Get ready for a great adventure that could result in your glory..." << endl;
    cout << "...or in its oblivion....\n\n" << endl;

    createChampions();
    cout << "Meet our champions" << endl;
    specifyChampions(champions);
    cout << "This is your team" << endl;
    createTeam();
    specifyChampions(team);
    cout << "Enemy" << endl;
    createEnemy();
    specifyChampions(enemy);
    fight();
}

void menu() {
    string option;

    while (true) {

        cout << "Do you want to play? \n(1) Yes\n(2) No\n\nOption: ";
        cin >> option;

        if (option == "1") {
            startGame();
        } else if (option == "2") {
            break;
        } else {
            cout << "\nInvalid Option\n" << endl;
        }
    }
    cout << "\nThank You!!!\n\n" << endl;
}
