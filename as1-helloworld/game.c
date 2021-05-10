#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "joystick.h"
#include "led.h"

static int score = 0;
static int total = 0;
static int selection = 0;

void game_init(){
    printf("Press the Zen cape's Joystick in the direction of the LED.\n");
    printf("UP for LED 0 (top)\n");
    printf("DOWN for LED 3 (bottom)\n");
    printf("LEFT/RIGHT to exit app.\n");
    led_init();
};
void game_cleanup(){
    printf("Thank you for playing!\n");
    led_cleanUp();
};

int game_selectLight(){
    srand(time(NULL));
    selection = rand() % 2;
    if(selection == 0) {
        led_toggle(LED_0);
    } else if(selection == 1){
        led_toggle(LED_3);
    }
    return selection;
};
void game_waitForNeutral(){
    int seconds = 0;
    long nanoseconds = 300000000;
    struct timespec delay = {seconds, nanoseconds};
    int nuetralFlag = 0;
    while(nuetralFlag == 0){
        nuetralFlag = 1;
        if(Joystick_isDirectionPressed(JOYSTICK_UP)){
            nuetralFlag = 0;
        }
        if(Joystick_isDirectionPressed(JOYSTICK_DOWN)){
            nuetralFlag = 0;
        }
        if(Joystick_isDirectionPressed(JOYSTICK_LEFT)){
            nuetralFlag = 0;
        }
        if(Joystick_isDirectionPressed(JOYSTICK_RIGHT)){
            nuetralFlag = 0;
        }
        nanosleep(&delay, (struct timespec *) NULL);

    }

}

int game_getInput(){
    int seconds = 0;
    long nanoseconds = 100000000;
    struct timespec delay = {seconds, nanoseconds};
    int nuetralFlag = 0;
    int input;
    while(nuetralFlag == 0){
        if(Joystick_isDirectionPressed(JOYSTICK_UP)){
            input = JOYSTICK_UP;
            nuetralFlag = 1;
        }
        else if(Joystick_isDirectionPressed(JOYSTICK_DOWN)){
            input = JOYSTICK_DOWN;
            nuetralFlag = 1;
        }
        else if(Joystick_isDirectionPressed(JOYSTICK_LEFT)){
            input = JOYSTICK_LEFT;
            nuetralFlag = 1;
        }
        else if(Joystick_isDirectionPressed(JOYSTICK_RIGHT)){
            input = JOYSTICK_RIGHT;
            nuetralFlag = 1;
        }
        nanosleep(&delay, (struct timespec *) NULL);

    }

    return input;

}

void game_updateScore(_Bool success){
    total++;
    if(selection == 0) {
        led_toggle(LED_0);
    } else if(selection == 1){
        led_toggle(LED_3);
    }
    if(success){
        score++;
        led_flashCorrect();
    } else {
        led_flashIncorrect();
    }
}
void game_displayScore(){
    printf("(%d/%d)\n", score,total);
}
