#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

    char battleWon() {
        cout << "Very good, you advanced to the next level!!!\n" << endl;
        cout << "Are still missing "<< jogadasQueFaltam << " battles" << endl;

        //recebeHeroi()
    }
    
    // battleLost poerá ser uma função sem retorno, basta chamar para ela executar o game over!
    // caso haja retorno teríamos que concatenar, daria muito trabalho... ??? (podemos ver)
    void battleLost()  {

    cout << " $$$$$$\   $$$$$$\  $$\      $$\ $$$$$$$$\        $$$$$$\  $$\    $$\ $$$$$$$$\ $$$$$$$\  " << endl;
    cout << "$$  __$$\ $$  __$$\ $$$\    $$$ |$$  _____|      $$  __$$\ $$ |   $$ |$$  _____|$$  __$$\ " << endl;
    cout << "$$ /  \__|$$ /  $$ |$$$$\  $$$$ |$$ |            $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |" << endl;
    cout << "$$ |$$$$\ $$$$$$$$ |$$\$$\$$ $$ |$$$$$\          $$ |  $$ |\$$\  $$  |$$$$$\    $$$$$$$  |" << endl;
    cout << "$$ |\_$$ |$$  __$$ |$$ \$$$  $$ |$$  __|         $$ |  $$ | \$$\$$  / $$  __|   $$  __$$< " << endl;
    cout << "$$ |  $$ |$$ |  $$ |$$ |\$  /$$ |$$ |            $$ |  $$ |  \$$$  /  $$ |      $$ |  $$ |" << endl;
    cout << "\$$$$$$  |$$ |  $$ |$$ | \_/ $$ |$$$$$$$$\        $$$$$$  |   \$  /   $$$$$$$$\ $$ |  $$ |" << endl;
    cout << " \______/ \__|  \__|\__|     \__|\________|       \______/     \_/    \________|\__|  \__|" << endl;

    cout << "\nMore luck in the next attempt, if you have the courage..." << endl;

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


int main(){
    cout << "Welcome to the Colosseum of Champions!!!" << endl;
    cout << "Get ready for a great adventure that could result in your glory..." << std::endl;
    cout << "...or in its oblivion...." << endl;    

    int jogadasQueFaltam = 10; 
    int x;
    x = 5;
    int y;
    y = 0;


    /* 
     * Printar lista com os herois do jogador com o seu index + 1
    */



    if(y == 10) {
        battleLost();
    }
    
    // if(vitoriaBatalha) {
    //    battleWon(); 
    // }
    /*if(gameWon) {

    }*/
 return 0;
}
