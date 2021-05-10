#include <stdio.h>
#include "game.h"

int main() {
printf("Hello embedded world, from Andrew Turner \n");
int exitFlag = 1;
game_init();
while(exitFlag==1){

    printf("Press joystick; current score");
    game_displayScore();

    int selected = game_selectLight();
    int input = game_getInput();
    if(input == 0 || input == 1){
        if(input == selected){
            printf("Correct!\n");
            game_updateScore(1);
        } else {
            printf("Incorrect!\n");
            game_updateScore(0);
        }
        game_waitForNeutral();
    } else if(input == 2 || input == 3) {
        exitFlag = 0;
        printf("Your final score was ");
        game_displayScore();
        game_cleanup();
    }


}
return 0;
}
