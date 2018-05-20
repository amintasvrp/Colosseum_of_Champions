#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

void createChampions(vector<string> &vector) {
    vector.push_back("Cosmic.Thanos.250.60.120.40");
    vector.push_back("Cosmic.Thor.200.50.100.30");
    vector.push_back("Mutant.Deadpool.200.50.100.30");
    vector.push_back("Mutant.Wolverine.200.50.100.30");
    vector.push_back("Mystic.Doctor Strange.200.50.100.30");
    vector.push_back("Mystic.Loki.200.50.100.30");
    vector.push_back("Science.Captain America.200.50.100.30");
    vector.push_back("Science.Spider-Man.200.50.100.30");
    vector.push_back("Skill.Black Panther.200.50.100.30");
    vector.push_back("Skill.Winter Soldier.200.50.100.30");
    vector.push_back("Tech.Iron Man.200.50.100.30");
    vector.push_back("Tech.Ultron.200.50.100.30");
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

void createChampions(vector<string> &vector);

// A função main() inicia a execução do programa
int main()
{
    menu();

    return 0;
}
