#include <string>
#include <ctime>
#include <vector>

using namespace std;

void createChampions(vector<string> &);

void createTeam(vector<string> &, vector<string> &);

unsigned int randomIndex(unsigned int upper);

void addChampion(vector<string> &, vector<string> &, unsigned int index);

void removeChampion(vector<string> &, unsigned int index);

int main() {
    vector<string> champions;
    vector<string> team;

    createChampions(champions);
    createTeam(champions, team);

    return 0;
}

void createChampions(vector<string> &vector) {
    vector.emplace_back("Cosmic.Thanos.250.60.120.40");
    vector.emplace_back("Cosmic.Thor.200.50.100.30");
    vector.emplace_back("Mutant.Deadpool.200.50.100.30");
    vector.emplace_back("Mutant.Wolverine.200.50.100.30");
    vector.emplace_back("Mystic.Doctor Strange.200.50.100.30");
    vector.emplace_back("Mystic.Loki.200.50.100.30");
    vector.emplace_back("Science.Captain America.200.50.100.30");
    vector.emplace_back("Science.Spider-Man.200.50.100.30");
    vector.emplace_back("Skill.Black Panther.200.50.100.30");
    vector.emplace_back("Skill.Winter Soldier.200.50.100.30");
    vector.emplace_back("Tech.Iron Man.200.50.100.30");
    vector.emplace_back("Tech.Ultron.200.50.100.30");
}

void createTeam(vector<string> &srcVector, vector<string> &destVector) {
    for (unsigned int i = 0; i < 3; i++) {
        unsigned int index = randomIndex(srcVector.size() - 1);

        addChampion(srcVector, destVector, index);
        removeChampion(srcVector, index);
    }
}

unsigned int randomIndex(unsigned int upper) {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % upper;
}

void addChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index) {
    destVector.emplace_back(srcVector.at(index));
}

void removeChampion(vector<string> &vector, unsigned int index) {
    vector.erase(vector.begin() + index);
}

