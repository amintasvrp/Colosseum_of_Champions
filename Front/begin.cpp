#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>





    char battleWon() {
        printf("Muito bem, voce avancou ao proximo nivel!!\n");
        printf("Ainda faltam" + jogadasQueFaltam + "batalhas");

        //recebeHeroi()
    }

    char battleLost() {
        printf("Game Over, mais sorte na proxima tentativa, se tiver coragem...");
    }

    char gameWon() {
        printf("Parabens, a voce pertence a gloria dos campeoes!!!");
    }

int main(){
    printf("Welcome to the Colosseum of Champions!! \n" );
    printf("Preparesse para uma grande aventura que pode resultar na sua gloria...\n");
    printf("...ou no seu esquecimento...\n");
    

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