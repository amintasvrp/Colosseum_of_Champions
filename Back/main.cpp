#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

vector<string> champions;
vector<string> team;
vector<string> enemy;

void createChampions();
void createTeam();
void createEnemy();
void addTeammate();
void randomizeChampion(vector<string> &vector);
int randomizeIndex();
void moveChampion(vector<string> &srcVector, vector<string> &destVector, int index);
void addChampion(vector<string> &srcVector, vector<string> &destVector, int index);
void removeChampion(vector<string> &vector, int index);
int calculateDamageWithAdvantage(string damage, string attackerClass, string defenderClass);
vector<string> generateAttributesOfChampions(string str);

int main() {
    createChampions();
    createTeam();
    createEnemy();

    return 0;
}

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

// Randomize three champions and add them to the `team` vector
void createTeam() {
    for (int i = 0; i < 3; ++i) {
        randomizeChampion(team);
    }
}

// Randomize a champion and add it to the `enemy` vector
void createEnemy() {
    randomizeChampion(enemy);
}

// Add the defeated enemy to the `team` vector
void addTeammate() {
    moveChampion(enemy, team, 0);
}

// Randomize a champion and add it to a vector
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

int calculateDamageWithAdvantage(string damage, string attackerClass, string defenderClass) {
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
