#include <string>
#include <ctime>
#include <vector>

using namespace std;

void createChampions(vector<string> &vector);

void createTeam(vector<string> &srcVector, vector<string> &destVector);

unsigned int randomIndex(unsigned int upper);

void addChampion(vector<string> &srcVector, vector<string> &destVector, unsigned int index);

void removeChampion(vector<string> &vector, unsigned int index);

int calculateDamageWithAdvantage(string damage, string attackerClass, string defenderClass);

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
        unsigned int index = randomIndex(static_cast<unsigned int>(srcVector.size() - 1));

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

int calculateDamageWithAdvantage(string damage, string attackerClass, string defenderClass){
	int result = stoi(damage, nullptr);
	if((attackerClass.compare("Mutant") == 0) && (defenderClass.compare("Skill") == 0)) {
		result *= 1.25;
	} else if((attackerClass.compare("Skill") == 0) && (defenderClass.compare("Science") == 0)){
		result *= 1.25;
	} else if((attackerClass.compare("Science") == 0) && (defenderClass.compare("Mystic") == 0)){
		result *= 1.25;
	} else if((attackerClass.compare("Mystic") == 0) && (defenderClass.compare("Cosmic") == 0)){
		result *= 1.25;
	} else if((attackerClass.compare("Cosmic") == 0) && (defenderClass.compare("Tech") == 0)){
		result *= 1.25;
	} else if((attackerClass.compare("Tech") == 0) && (defenderClass.compare("Mutant") == 0)){
		result *= 1.25;
	}
	return result;
}
