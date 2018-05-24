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
vector<string> party;
int partyMembers;
const int enemyAdavantageMod = 2;

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
void battleWon();
int enemyHpInteger(vector<string> champion);
int teamHpInteger(vector<string> team, int indexOfTeam);
int enemyNormalAtkInteger(vector<string> champion);
int teamNormalAtkInteger(vector<string> team, int indexOfTeam);
int enemySpecialAtkInteger(vector<string> champion);
int teamSpecialAtkInteger(vector<string> team, int indexOfTeam);
int enemyDefenseInteger(vector<string> champion);
int teamDefenseInteger(vector<string> team, int indexOfTeam);
void specifyChampions(vector<string> champions);
void startGame();
void menu();

/*     -------         MAIN EXECUTION      --------    */

int main() {
    menu();
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
        int index = rand() % ((champions.size() / 2) - 1);
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
    int advantageDamageMod = 4;
    if ((attackerClass.compare("Mutant") == 0) && (defenderClass.compare("Skill") == 0)) {
        result += result / advantageDamageMod;
    } else if ((attackerClass.compare("Skill") == 0) && (defenderClass.compare("Science") == 0)) {
        result += result / advantageDamageMod;
    } else if ((attackerClass.compare("Science") == 0) && (defenderClass.compare("Mystic") == 0)) {
        result += result / advantageDamageMod;
    } else if ((attackerClass.compare("Mystic") == 0) && (defenderClass.compare("Cosmic") == 0)) {
        result += result / advantageDamageMod;
    } else if ((attackerClass.compare("Cosmic") == 0) && (defenderClass.compare("Tech") == 0)) {
        result += result / advantageDamageMod;
    } else if ((attackerClass.compare("Tech") == 0) && (defenderClass.compare("Mutant") == 0)) {
        result += result / advantageDamageMod;
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
    return checkPartialVictory(firstTeammateHP) && checkPartialVictory(secondTeammateHP) &&
           checkPartialVictory(thirdTeammateHP);
}

/*     -------         FRONT IMPLEMENTATIONS      --------    */

string split(string word, char characterToBbreak) {
    int i;
    string temporaryWord = "";

    int countSpace = 0;

    for (i = 0; i < word.length(); i++) {
        if (word.at(i) == characterToBbreak) {
            temporaryWord += " ";
            countSpace++;
            if (countSpace == 2) {
                break;
            }
        } else {
            temporaryWord += word.at(i);
        }
    }
    return temporaryWord;
}

/*
 * Show message shown when the player lose a battle/game and clear the enemy and the team vector for a new game.
 */
void battleLost() {
    cout << "This is the team you had:" << endl;
    specifyChampions(team);
    enemy.clear();
    team.clear();

    /*cout << "$$  __$$\ $$  __$$\ $$$\    $$$ |$$  _____|      $$  __$$\ $$ |   $$ |$$  _____|$$  __$$\ " << endl;
    cout << "$$ /  \__|$$ /  $$ |$$$$\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |" << endl;
    cout << "$$ |$$$$\ $$$$$$$$ |$$\$$\$$ $$ |$$$$$\          $$ |  $$ |\$$\  $$  |$$$$$\    $$$$$$$  |" << endl;
    cout << "$$ |\_$$ |$$  __$$ |$$ \$$$  $$ |$$  __|         $$ |  $$ | \$$\$$  / $$  __|   $$  __$$< " << endl;
    cout << "$$ |  $$ |$$ |  $$ |$$ |\$  /$$ |$$ |            $$ |  $$ |  \$$$  /  $$ |      $$ |  $$ |" << endl;
    cout << "\$$$$$$  |$$ |  $$ |$$ | \_/ $$ |$$$$$$$$\        $$$$$$  |   \$  /   $$$$$$$$\ $$ |  $$ |" << endl;
    cout << " \______/ \__|  \__|\__|     \__|\________|       \______/     \_/    \________|\__|  \__|" << endl;*/

    cout << "\n\nmore luck in the next attempt, if you have the courage..." << endl;
}

/*
 * The message shown when the player wins the game.
 */
void gameWon() {

    /*cout << "   ___                            _         _       _   _" << endl;
    cout << "  / __\___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___" << endl;
    cout << " / /  / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __|" << endl;
    cout << "/ /__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \ " << endl;
    cout << "\____/\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___/" << endl;
    cout << "                  |___/" << endl;*/

    cout << "\n\nTo you belong to the glory of the champions!!!" << endl;
}

/*
 * The message shown when the player wins a battle.
 */
void battleWon() {
    cout << "\n\nYou Won!!! Let's go to the next battle!!" << endl;
}

/*
 * Method to print a given list of champions (all of then, just the team, the party).
 */
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

int teamHpInteger(vector<string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 2)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemyHpInteger(vector<string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 2)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamNormalAtkInteger(vector<string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 3)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemyNormalAtkInteger(vector<string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 3)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamSpecialAtkInteger(vector<string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 4)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemySpecialAtkInteger(vector<string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 4)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int enemyDefenseInteger(vector<string> champion) {
    int i;
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 5)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

int teamDefenseInteger(vector<string> team, int indexOfTeam) {
    int i;
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber = "";
    for (i = 0; i < numberStr.length(); i++) {
        if (counts == 5)
            integerNumber += numberStr.at(i);
        if (numberStr.at(i) == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str());
}

/*
 * This is where the magic happens, first we have the transformation of the string attributes into ints so we can make
 * operations with, then we have the logic of the fight, with normal and special attacks, defense and advantages.
 */
void fight() {
    int hpEnemy = enemyHpInteger(enemy) + (enemyHpInteger(enemy) / enemyAdavantageMod);

    int hpFighter1 = teamHpInteger(party, 0);
    int hpFighter2 = teamHpInteger(party, 1);
    int hpFighter3 = teamHpInteger(party, 2);

    int normalAtkEnemy = enemyNormalAtkInteger(enemy);

    int normalAtkFighter1 = teamNormalAtkInteger(party, 0);
    int normalAtkFighter2 = teamNormalAtkInteger(party, 1);
    int normalAtkFighter3 = teamNormalAtkInteger(party, 2);

    int specialAtkEnemy = enemySpecialAtkInteger(enemy);

    int specialAtkFighter1 = teamSpecialAtkInteger(party, 0);
    int specialAtkFighter2 = teamSpecialAtkInteger(party, 1);
    int specialAtkFighter3 = teamSpecialAtkInteger(party, 2);

    int defenseEnemy = enemyDefenseInteger(enemy);

    int defenseFighter1 = teamDefenseInteger(party, 0);
    int defenseFighter2 = teamDefenseInteger(party, 1);
    int defenseFighter3 = teamDefenseInteger(party, 2);

    string option;

    int normalAttackAmount = 0; // conta a quantidade de ataques normais do usuário
    int enemyNormalAttackAmount = 0; // conta a quantidade de ataques normais do enemy

    cout << "\n" << endl;

    while (true) {

        if (hpEnemy <= 0 || (hpFighter1 <= 0 && hpFighter2 <= 0 && hpFighter3 <= 0))
            break;
        atack:
        if (hpFighter1 >= 0) {
            cout << generateAttributesOfChampions(party[0]).at(1) << endl;
        } else if (hpFighter2 >= 0) {
            cout << generateAttributesOfChampions(party[1]).at(1) << endl;
        } else {
            cout << generateAttributesOfChampions(party[2]).at(1) << endl;
        }
        cout << "What do you want to do?\n(1) Normal Attack\n(2) Special Attack (" << normalAttackAmount << "/5)"
             << ";\nOption: ";
        cin >> option;

        if (option == "1") {

            if (hpFighter1 > 0) {
                int tempNormalAtkFighter1 = normalAtkFighter1;
                tempNormalAtkFighter1 = calDamageWithAdvantage(generateAttributesOfChampions(party[0]).at(3),
                                                               generateAttributesOfChampions(party[0]).at(0),
                                                               enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter1 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }

            } else if (hpFighter2 > 0) {
                int tempNormalAtkFighter2 = normalAtkFighter2;
                tempNormalAtkFighter2 = calDamageWithAdvantage(generateAttributesOfChampions(party[1]).at(3),
                                                               generateAttributesOfChampions(party[1]).at(0),
                                                               enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter2 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }
            } else if (hpFighter3 > 0) {
                int tempNormalAtkFighter3 = normalAtkFighter3;
                tempNormalAtkFighter3 = calDamageWithAdvantage(generateAttributesOfChampions(party[2]).at(3),
                                                               generateAttributesOfChampions(party[2]).at(0),
                                                               enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter3 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }
            }
            if (normalAttackAmount < 5) normalAttackAmount += 1;
        } else if (option == "2") {
            if (normalAttackAmount >= 5) {
                if (hpFighter1 > 0) {
                    int tempSpecialAtkFighter1 = specialAtkFighter1;
                    tempSpecialAtkFighter1 = calDamageWithAdvantage(generateAttributesOfChampions(party[0]).at(4),
                                                                    generateAttributesOfChampions(party[0]).at(0),
                                                                    enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter1 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }
                } else if (hpFighter2 > 0) {
                    int tempSpecialAtkFighter2 = specialAtkFighter2;
                    tempSpecialAtkFighter2 = calDamageWithAdvantage(generateAttributesOfChampions(party[1]).at(4),
                                                                    generateAttributesOfChampions(party[1]).at(0),
                                                                    enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter2 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }
                } else if (hpFighter3 > 0) {
                    int tempSpecialAtkFighter3 = specialAtkFighter3;
                    tempSpecialAtkFighter3 = calDamageWithAdvantage(generateAttributesOfChampions(party[2]).at(4),
                                                                    generateAttributesOfChampions(party[2]).at(0),
                                                                    enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter3 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "Remaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }

                }
                normalAttackAmount -= 5;
            } else {
                cout << "it is not possible to use the special attack" << endl;
                goto atack;
            }
        } else {
            cout << "Invalid Option" << endl;
        }

        cout << "\nStatus Enemy Attack (" << enemyNormalAttackAmount << "/5)" << endl;
        enemyNormalAttackAmount += 1;

        if (enemyNormalAttackAmount <= 5) {
            cout << "Enemy Normal Attack\n" << endl;
            if (hpFighter1 >= 0) {
                int tempNormalAtkEnemy = normalAtkEnemy;
                normalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                        generateAttributesOfChampions(enemy[0]).at(0),
                                                        generateAttributesOfChampions(party[0]).at(0));
                hpFighter1 -= tempNormalAtkEnemy - defenseFighter1;
                if (hpFighter1 <= 0) {
                    cout << generateAttributesOfChampions(party[0]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[0]).at(1) << ": " << hpFighter1
                         << "\n" << endl;
                }
            } else if (hpFighter2 >= 0) {
                int tempNormalAtkEnemy = normalAtkEnemy;
                tempNormalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                            generateAttributesOfChampions(enemy[0]).at(0),
                                                            generateAttributesOfChampions(party[1]).at(0));
                hpFighter2 -= tempNormalAtkEnemy - defenseFighter2;
                if (hpFighter2 <= 0) {
                    cout << generateAttributesOfChampions(party[1]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[1]).at(1) << ": " << hpFighter2
                         << "\n" << endl;
                };
            } else if (hpFighter3 >= 0) {
                int tempNormalAtkEnemy = normalAtkEnemy;
                tempNormalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                            generateAttributesOfChampions(enemy[0]).at(0),
                                                            generateAttributesOfChampions(party[2]).at(0));
                hpFighter3 -= tempNormalAtkEnemy - defenseFighter3;
                if (hpFighter3 <= 0) {
                    cout << generateAttributesOfChampions(party[2]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[2]).at(1) << ": " << hpFighter3
                         << "\n" << endl;
                }
            }

        } else {
            cout << "Enemy Special Attack\n" << endl;
            if (hpFighter1 >= 0) {
                int tempSpecialAtkEnemy = specialAtkEnemy;
                tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                             generateAttributesOfChampions(enemy[0]).at(0),
                                                             generateAttributesOfChampions(party[0]).at(0));
                hpFighter1 -= tempSpecialAtkEnemy - defenseFighter1;
                if (hpFighter1 <= 0) {
                    cout << generateAttributesOfChampions(party[0]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[0]).at(1) << ": " << hpFighter1
                         << "\n" << endl;
                }

            } else if (hpFighter2 >= 0) {
                int tempSpecialAtkEnemy = specialAtkEnemy;
                tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                             generateAttributesOfChampions(enemy[0]).at(0),
                                                             generateAttributesOfChampions(party[1]).at(0));
                hpFighter2 -= tempSpecialAtkEnemy - defenseFighter2;
                if (hpFighter2 <= 0) {
                    cout << generateAttributesOfChampions(party[1]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[1]).at(1) << ": " << hpFighter2
                         << "\n" << endl;
                }

            } else if (hpFighter3 >= 0) {
                int tempSpecialAtkEnemy = specialAtkEnemy;
                tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                             generateAttributesOfChampions(enemy[0]).at(0),
                                                             generateAttributesOfChampions(party[2]).at(0));
                hpFighter3 -= tempSpecialAtkEnemy - defenseFighter3;
                if (hpFighter3 <= 0) {
                    cout << generateAttributesOfChampions(party[2]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "Remaining life of " << generateAttributesOfChampions(party[2]).at(1) << ": " << hpFighter3
                         << "\n" << endl;
                }
            }

            enemyNormalAttackAmount = 0;
        }
    }
    if (hpEnemy <= 0) {
        addTeammate();
        battleWon();
    } else {
        battleLost();
    }
}

/*
 * Start the game, first it clear the party for each fight, the ir take a number from the player to choose witch order
 * does he want his champions to fight, there is a validation so you can't put a number that is out of the range neither
 * put the same champion on the party more than once in the same fight, then clear the enemy vector so if the player
 * looses and want to fight again, he doesn't have to fight to enemys, only after that the fight will start.
 */
void startGame() {
    party.clear();
    cout << "Choose your party: (select the number then hit ENTER) \n";
    choose1:
    cin >> partyMembers;
    if (partyMembers > team.size()) {
        cout << "This champion doesn't exist" << endl;
        goto choose1;
    } else {
        addChampion(team, party, partyMembers - 1);
    }
    choose2:
    cin >> partyMembers;
    if (partyMembers > team.size()) {
        cout << "This champion doesn't exist" << endl;
        goto choose2;
    } else if (generateAttributesOfChampions(party[0]).at(1) !=
               generateAttributesOfChampions(team[partyMembers - 1]).at(1)) {
        addChampion(team, party, partyMembers - 1);
    } else {
        cout << "champion already choosen" << endl;
        goto choose2;
    }
    choose3:
    cin >> partyMembers;
    if (partyMembers > team.size()) {
        cout << "This champion doesn't exist" << endl;
        goto choose3;
    } else if (generateAttributesOfChampions(party[0]).at(1) !=
               generateAttributesOfChampions(team[partyMembers - 1]).at(1) &&
               generateAttributesOfChampions(party[1]).at(1) !=
               generateAttributesOfChampions(team[partyMembers - 1]).at(1)) {
        addChampion(team, party, partyMembers - 1);
    } else {
        cout << "champion already choosen" << endl;
        goto choose3;
    }
    cout << endl;
    specifyChampions(party);
    cout << "Enemy" << endl;
    createEnemy();
    specifyChampions(enemy);
    fight();
}

/*
 * Here is where the program will begin, printing some messages welcoming the player, then it will populate the
 * champions vector, and create the team, the team will primary be made from 3 of the 5 weaker champions, it will than
 * go into a loop for the fights.
 */
void menu() {
    string option;

    cout << "\nWelcome to the Colosseum of Champions!!!" << endl;
    cout << "Get ready for a great adventure that could result in your glory..." << endl;
    cout << "...or in your oblivion....\n\n" << endl;

    createChampions();
    createTeam();

    while (champions.size() > 0) {

        cout << "Do you want to play? \n(1) Yes\n(2) No\n\nOption: ";
        cin >> option;

        if (option == "1") {
            if (team.size() < 3) {
                champions.clear();
                createChampions();
                createTeam();
            }
            cout << "\nThis is your team" << endl;
            specifyChampions(team);
            startGame();
        } else if (option == "2") {
            break;
        } else {
            cout << "\nInvalid Option\n" << endl;
        }
    }
    if (checkFinalVictory()) {
        gameWon();
    } else {
        cout << "\nThank You!!!" << endl;
    }
}
