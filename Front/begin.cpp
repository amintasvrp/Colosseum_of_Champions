#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


    char battleWon() {
        std::cout << "Very good, you advanced to the next level!!!\n" << std::endl;
        std::cout << "Are still missing "<< jogadasQueFaltam << " battles" << std::endl;

        //recebeHeroi()
    }

    char battleLost() {
        std::cout << "Game Over, more luck in the next attempt, if you have the courage..." << std::endl;
    }

    char gameWon() {
        std::cout << "Congratulations, you belong to the glory of the champions!!!" << std::endl;
    }

int main(){
    std::cout << "Welcome to the Colosseum of Champions!!!" << std::endl;
    std::cout << "Get ready for a great adventure that could result in your glory..." << std::endl;
    std::cout << "...or in its oblivion...." << std::endl;    

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
