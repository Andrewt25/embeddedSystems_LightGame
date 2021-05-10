#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "led.h"
// 0 off, 1 on

static void led_changeBrightness(enum eLedLights led, enum eLedState state);
static void led_flashLedAll();

static int ledState[] = {0,0,0,0};

const char* FILE_PATH = "/sys/class/leds/beaglebone:green:usr%d/brightness";

void led_init(){
    for(int i = 0; i < LED_NUMBER_OF_LIGHTS; i++){ 
         led_changeBrightness(i, LED_OFF);
    }

}

void led_cleanUp(){
        for(int i = 0; i < LED_NUMBER_OF_LIGHTS; i++){ 
         led_changeBrightness(i, LED_OFF);
    }

}

void led_toggle(enum eLedLights led){
    if(ledState[led] == 0){
        led_changeBrightness(led, 1);
        ledState[led] = 1;
    } else{
        led_changeBrightness(led, 0);
        ledState[led] = 0;
    }

}

void led_flashCorrect(){
    led_flashLedAll();

}
void led_flashIncorrect(){
    for(int i = 0; i < 5; i++){
        led_flashLedAll();
    }

}


static void led_changeBrightness(enum eLedLights led, enum eLedState state){
    char filename[55];
    sprintf(filename,FILE_PATH, led);

    FILE *pFile = fopen(filename, "w");
    if(pFile == NULL){
        printf("ERROR OPENING %s", filename);
        exit(-1);
    }

    int charWriter = fprintf(pFile, "%d", (int)state);
    fflush(pFile);
    
    if(charWriter <= 0){
        printf("ERROR WRITING DATA");
        exit(-1);
    }
    ledState[led] = state;
    fclose(pFile);

}

static void led_flashLedAll(){
    int seconds = 0;
    long nanoseconds = 100000000;
    struct timespec delay = {seconds, nanoseconds};
    for(int i = 0; i < LED_NUMBER_OF_LIGHTS; i++){ 
        led_changeBrightness(i, LED_ON);
    }
    nanosleep(&delay, (struct timespec *) NULL);
    for(int i = 0; i < LED_NUMBER_OF_LIGHTS; i++){ 
        led_changeBrightness(i, LED_OFF);
    }
    nanosleep(&delay, (struct timespec *) NULL);

    
}