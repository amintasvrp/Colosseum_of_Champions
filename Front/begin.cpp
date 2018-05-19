#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


    char battleWon() {
        printf("Very good, you advanced to the next level!!!\n");
        printf("Are still missing %d battles\n", jogadasQueFaltam);

        //recebeHeroi()
    }

    char battleLost() {
        printf("Game Over, more luck in the next attempt, if you have the courage...");
    }

    char gameWon() {
        printf("Congratulations, you belong to the glory of the champions!!!");
    }

int main(){
    printf("Welcome to the Colosseum of Champions!!!\n" );
    printf("Get ready for a great adventure that could result in your glory...\n");
    printf("...or in its oblivion....\n");
    

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
