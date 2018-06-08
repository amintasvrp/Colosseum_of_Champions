// Libraries

#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int enemyAdavantageMod = 2;
int partyMembers;
vector<string> champions;
vector<string> enemy;
vector<string> party;
vector<string> team;

// Functions implemented by Back Team

bool checkFinalVictory();
int calDamageWithAdvantage(const string &damage, const string &attackerClass, const string &defenderClass);
unsigned int randomizeIndex();
vector<string> generateAttributesOfChampions(const string &str);
void addChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index);
void addTeammate();
void createChampions();
void createEnemy();
void createTeam();
void moveChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index);
void randomizeChampion(vector<string> &vector);
void removeChampion(vector<string> &vector, int index);

// Functions implemented by Front Team

int enemyDefenseInteger(vector<string> champion);
int enemyHpInteger(vector<string> champion);
int enemyNormalAtkInteger(vector<string> champion);
int teamDefenseInteger(vector<string> team, int indexOfTeam);
int teamHpInteger(vector<string> team, int indexOfTeam);
string split(string word, char characterToBreak);
void battleLost();
void battleWon();
void gameWon();
void menu();
void specifyEnemy(vector<string> enemy);
void specifyChampions(vector<string> champions);
void startGame();

/*     -------         MAIN EXECUTION      --------    */

int main() {
    menu();
    return 0;
}

/*     -------         BACK IMPLEMENTATIONS      --------    */

// Populate the `champions` vector
void createChampions() {
    champions.emplace_back("Science.Spider-Man.200.33.50.31");
    champions.emplace_back("Skill.Black Panther.220.38.57.30");
    champions.emplace_back("Skill.Winter Soldier.240.43.65.29");
    champions.emplace_back("Science.Captain America.260.48.72.28");
    champions.emplace_back("Tech.Iron Man.280.53.80.27");
    champions.emplace_back("Mutant.Wolverine.300.58.87.26");
    champions.emplace_back("Mutant.Deadpool.320.63.95.25");
    champions.emplace_back("Mystic.Loki.340.68.102.24");
    champions.emplace_back("Tech.Ultron.360.73.110.23");
    champions.emplace_back("Mystic.Doctor Strange.380.78.117.22");
    champions.emplace_back("Cosmic.Thanos.400.83.125.21");
    champions.emplace_back("Cosmic.Thor.420.88.132.20");
}

// Randomize three champions from the `champions` vector and move them to the `team` vector
void createTeam() {
    for (unsigned int i = 0; i < 3; ++i) {
        srand(static_cast<unsigned int>(time(nullptr)));
        auto index = static_cast<unsigned int>(rand() % ((champions.size() / 2) - 1)); // NOLINT
        moveChampion(champions, team, index);
    }
}

// Randomize a champion from the `champions` vector and move him/her to the `enemy` vector
void createEnemy() {
    if (champions.size() == 1) {
        moveChampion(champions, enemy, 0);
    } else {
        randomizeChampion(enemy);
    }
}

// Move the defeated enemy to the `team` vector
void addTeammate() {
    moveChampion(enemy, team, 0);
}

// Randomize a champion from the `champions` vector and move him/her to a vector
void randomizeChampion(vector<string> &vector) {
    unsigned int index = randomizeIndex();
    moveChampion(champions, vector, index);
}

// Randomize an index from the `champions` vector
unsigned int randomizeIndex() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return static_cast<unsigned int>(rand() % (champions.size() - 1)); // NOLINT
}

// Move a champion from the n-th index on `source vector` to the `destination vector`
void moveChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index) {
    addChampion(srcVector, destVector, index);
    removeChampion(srcVector, index);
}

// Add a champion from the n-th index on `source vector` to the `destination vector`
void addChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index) {
    destVector.push_back(srcVector.at(index));
}

// Remove a champion from the n-th position on a vector
void removeChampion(vector<string> &vector, int index) {
    vector.erase(vector.begin() + index);
}

// Calculates the attacker's damage, checking his advantage
int calDamageWithAdvantage(const string &damage, const string &attackerClass, const string &defenderClass) {
    int result = stoi(damage, nullptr);
    float advantageDamageMod = result / 4;
    if ((attackerClass.compare("Mutant") == 0) && (defenderClass.compare("Skill") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    } else if ((attackerClass.compare("Skill") == 0) && (defenderClass.compare("Science") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    } else if ((attackerClass.compare("Science") == 0) && (defenderClass.compare("Mystic") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    } else if ((attackerClass.compare("Mystic") == 0) && (defenderClass.compare("Cosmic") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    } else if ((attackerClass.compare("Cosmic") == 0) && (defenderClass.compare("Tech") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    } else if ((attackerClass.compare("Tech") == 0) && (defenderClass.compare("Mutant") == 0)) { // NOLINT
        result = result + advantageDamageMod;
    }
    return result;
}

// Splits a Champion's string into a Champion's vector
vector<string> generateAttributesOfChampions(const string &str) {
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
    return champions.empty();
}

/*     -------         FRONT IMPLEMENTATIONS      --------    */

string split(string word, char characterToBreak) {
    string temporaryWord = "(";

    int countSpace = 0;

    for (char i : word) {
        if (i == characterToBreak) {
            if (countSpace == 0) {
                temporaryWord += ") ";
                countSpace++;
            } else {
                temporaryWord += " ";
                countSpace++;
            }
            if (countSpace == 2) {
                break;
            }
        } else {
            temporaryWord += i;
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

    cout << "GAME OVER!" << endl;
    cout << "\nMore luck in your next attempt, if you have the courage...\n" << endl;
}

/*
 * The message shown when the player wins the game.
 */
void gameWon() {
    cout << "CONGRATULATIONS!" << endl;
    cout << "\nYou belong to the glory of the champions!!!" << endl;
}

/*
 * The message shown when the player wins a battle.
 */
void battleWon() {
    cout << "You Won!!! Let's go to the next battle!!!\n" << endl;
}

/*
 * Method to print the enemy.
 */
void specifyEnemy(vector<string> enemy) {
    int numberOfChampions, i;

    numberOfChampions = static_cast<int>(enemy.size());

    for (i = 0; i < numberOfChampions; i++) {
        cout << split(enemy[i], '.') << "\n";
    }
    cout << endl;
}

/*
 * Method to print a given list of champions (all of then, just the team, the party).
 */
void specifyChampions(vector<string> champions) {
    int numberOfChampions, i;

    numberOfChampions = static_cast<int>(champions.size());

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
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber;
    for (char i : numberStr) {
        if (counts == 2)
            integerNumber += i;
        if (i == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str()); // NOLINT
}

int enemyHpInteger(vector<string> champion) {
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber;
    for (char i : numberStr) {
        if (counts == 2)
            integerNumber += i;
        if (i == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str()); // NOLINT
}

int enemyNormalAtkInteger(vector<string> champion) {
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber;
    for (char i : numberStr) {
        if (counts == 3)
            integerNumber += i;
        if (i == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str()); // NOLINT
}

int enemyDefenseInteger(vector<string> champion) {
    int counts = 0;

    string numberStr = champion[0];
    string integerNumber;
    for (char i : numberStr) {
        if (counts == 5)
            integerNumber += i;
        if (i == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str()); // NOLINT
}

int teamDefenseInteger(vector<string> team, int indexOfTeam) {
    int counts = 0;

    string numberStr = team[indexOfTeam];
    string integerNumber;
    for (char i : numberStr) {
        if (counts == 5)
            integerNumber += i;
        if (i == '.')
            counts += 1;
    }

    return atoi(integerNumber.c_str()); // NOLINT
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
    int defenseEnemy = enemyDefenseInteger(enemy);
    int defenseFighter1 = teamDefenseInteger(party, 0);
    int defenseFighter2 = teamDefenseInteger(party, 1);
    int defenseFighter3 = teamDefenseInteger(party, 2);

    string option;

    int normalAttackAmount = 0; // conta a quantidade de ataques normais do usuário
    int enemyNormalAttackAmount = 0; // conta a quantidade de ataques normais do enemy

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
                int tempNormalAtkFighter1 = calDamageWithAdvantage(generateAttributesOfChampions(party[0]).at(3),
                                                                   generateAttributesOfChampions(party[0]).at(0),
                                                                   enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter1 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }

            } else if (hpFighter2 > 0) {
                int tempNormalAtkFighter2 = calDamageWithAdvantage(generateAttributesOfChampions(party[1]).at(3),
                                                                   generateAttributesOfChampions(party[1]).at(0),
                                                                   enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter2 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }
            } else if (hpFighter3 > 0) {
                int tempNormalAtkFighter3 = calDamageWithAdvantage(generateAttributesOfChampions(party[2]).at(3),
                                                                   generateAttributesOfChampions(party[2]).at(0),
                                                                   enemy.at(0));
                hpEnemy -= (tempNormalAtkFighter3 - defenseEnemy);
                if (hpEnemy > 0) {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": " << hpEnemy
                         << "\n"
                         << endl;
                } else {
                    cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                }
            }
            if (normalAttackAmount < 5) normalAttackAmount += 1;
        } else if (option == "2") {
            if (normalAttackAmount >= 5) {
                if (hpFighter1 > 0) {
                    int tempSpecialAtkFighter1 = calDamageWithAdvantage(generateAttributesOfChampions(party[0]).at(4),
                                                                        generateAttributesOfChampions(party[0]).at(0),
                                                                        enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter1 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": "
                             << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }
                } else if (hpFighter2 > 0) {
                    int tempSpecialAtkFighter2 = calDamageWithAdvantage(generateAttributesOfChampions(party[1]).at(4),
                                                                        generateAttributesOfChampions(party[1]).at(0),
                                                                        enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter2 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": "
                             << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }
                } else if (hpFighter3 > 0) {
                    int tempSpecialAtkFighter3 = calDamageWithAdvantage(generateAttributesOfChampions(party[2]).at(4),
                                                                        generateAttributesOfChampions(party[2]).at(0),
                                                                        enemy.at(0));
                    hpEnemy -= (tempSpecialAtkFighter3 - defenseEnemy);
                    if (hpEnemy > 0) {
                        cout << "\nRemaining life of " << generateAttributesOfChampions(enemy[0]).at(1) << ": "
                             << hpEnemy
                             << "\n"
                             << endl;
                    } else {
                        cout << "\n" << generateAttributesOfChampions(enemy[0]).at(1) << " was defeated. \n" << endl;
                    }

                }
                normalAttackAmount -= 5;
            } else {
                cout << "\nIt is not possible to use the special attack.\n" << endl;
                goto atack;
            }
        } else {
            cout << "Invalid Option" << endl;
        }

        cout << "Status Enemy Special Attack (" << enemyNormalAttackAmount << "/5)" << endl;
        enemyNormalAttackAmount += 1;

        if (enemyNormalAttackAmount <= 5) {
            cout << "Enemy Normal Attack" << endl;
            if (hpFighter1 >= 0) {
                int tempNormalAtkEnemy = normalAtkEnemy;
                normalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                        generateAttributesOfChampions(enemy[0]).at(0),
                                                        generateAttributesOfChampions(party[0]).at(0));
                hpFighter1 -= tempNormalAtkEnemy - defenseFighter1;
                if (hpFighter1 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[0]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[0]).at(1) << ": "
                         << hpFighter1
                         << "\n" << endl;
                }
            } else if (hpFighter2 >= 0) {
                int tempNormalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                                generateAttributesOfChampions(enemy[0]).at(0),
                                                                generateAttributesOfChampions(party[1]).at(0));
                hpFighter2 -= tempNormalAtkEnemy - defenseFighter2;
                if (hpFighter2 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[1]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[1]).at(1) << ": "
                         << hpFighter2
                         << "\n" << endl;
                };
            } else if (hpFighter3 >= 0) {
                int tempNormalAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                                generateAttributesOfChampions(enemy[0]).at(0),
                                                                generateAttributesOfChampions(party[2]).at(0));
                hpFighter3 -= tempNormalAtkEnemy - defenseFighter3;
                if (hpFighter3 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[2]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[2]).at(1) << ": "
                         << hpFighter3
                         << "\n" << endl;
                }
            }

        } else {
            cout << "Enemy Special Attack" << endl;
            if (hpFighter1 >= 0) {
                int tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                                 generateAttributesOfChampions(enemy[0]).at(0),
                                                                 generateAttributesOfChampions(party[0]).at(0));
                hpFighter1 -= tempSpecialAtkEnemy - defenseFighter1;
                if (hpFighter1 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[0]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[0]).at(1) << ": "
                         << hpFighter1
                         << "\n" << endl;
                }

            } else if (hpFighter2 >= 0) {
                int tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                                 generateAttributesOfChampions(enemy[0]).at(0),
                                                                 generateAttributesOfChampions(party[1]).at(0));
                hpFighter2 -= tempSpecialAtkEnemy - defenseFighter2;
                if (hpFighter2 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[1]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[1]).at(1) << ": "
                         << hpFighter2
                         << "\n" << endl;
                }

            } else if (hpFighter3 >= 0) {
                int tempSpecialAtkEnemy = calDamageWithAdvantage(generateAttributesOfChampions(enemy[0]).at(3),
                                                                 generateAttributesOfChampions(enemy[0]).at(0),
                                                                 generateAttributesOfChampions(party[2]).at(0));
                hpFighter3 -= tempSpecialAtkEnemy - defenseFighter3;
                if (hpFighter3 <= 0) {
                    cout << "\n" << generateAttributesOfChampions(party[2]).at(1) << " was defeated. \n" << endl;
                    normalAttackAmount = 0;
                } else {
                    cout << "\nRemaining life of " << generateAttributesOfChampions(party[2]).at(1) << ": "
                         << hpFighter3
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
    cout << "Choose your party (select the number then hit ENTER): \n";
    choose1:
    cin >> partyMembers;
    if (partyMembers > team.size()) {
        cout << "This champion doesn't exist" << endl;
        goto choose1;
    } else {
        addChampion(team, party, static_cast<unsigned int>(partyMembers - 1));
    }
    choose2:
    cin >> partyMembers;
    if (partyMembers > team.size()) {
        cout << "This champion doesn't exist" << endl;
        goto choose2;
    } else if (generateAttributesOfChampions(party[0]).at(1) !=
               generateAttributesOfChampions(team[partyMembers - 1]).at(1)) {
        addChampion(team, party, static_cast<unsigned int>(partyMembers - 1));
    } else {
        cout << "This champion was already chosen" << endl;
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
        addChampion(team, party, static_cast<unsigned int>(partyMembers - 1));
    } else {
        cout << "This champion was already chosen" << endl;
        goto choose3;
    }
    cout << endl;
    specifyChampions(party);
    cout << "Enemy" << endl;
    createEnemy();
    specifyEnemy(enemy);
    fight();
}

/*
 * Here is where the program will begin, printing some messages welcoming the player, then it will populate the
 * champions vector, and create the team, the team will primary be made from 3 of the 5 weaker champions, it will than
 * go into a loop for the fights.
 */
void menu() {
    string option;

    cout << "Welcome to the Colosseum of Champions!!!" << endl;
    cout << "Get ready for a great adventure that could result in your glory..." << endl;
    cout << "...or in your oblivion...\n" << endl;

    createChampions();
    createTeam();

    while (!champions.empty()) {

        cout << "Do you want to play? \n(1) Yes\n(2) No\n\nOption: ";
        cin >> option;

        if (option == "1") {
            if (team.size() < 3) {
                champions.clear();
                createChampions();
                createTeam();
            }
            cout << "\nThis is your team:" << endl;
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
