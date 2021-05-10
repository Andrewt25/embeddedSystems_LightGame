#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "joystick.h"

static void assertDirectionOk(enum eJoystickDirections direction);
static char readValue(char *filename);

struct DirectionInfo {
    const char* name;
    const int portNumber;
};

const struct DirectionInfo directions[] = {
    {"Up", 26,},
    {"Down", 46,},
    {"Left", 65,},
    {"Right", 47,},
};

_Bool Joystick_isDirectionPressed(enum eJoystickDirections direction){
    assertDirectionOk(direction);
    char filename[30];
    sprintf(filename,"/sys/class/gpio/gpio%d/value", directions[direction].portNumber);
    if(readValue(filename) == '0'){
        return 1;
    }
    return 0;
}

static void assertDirectionOk(enum eJoystickDirections direction){
    assert(direction >= 0 && direction < JOYSTICK_NUMBER_OF_DIRECTIONS);
}

static char readValue(char *filename) {
        //Open File
        FILE *pFile = fopen(filename, "r");
        if(pFile == NULL) {
            printf("Error: Unable to open file (%s) for read\n", filename);
            exit(-1);
        } 
        const int MAX_LENGTH = 2;
        char buff[MAX_LENGTH];
        fgets(buff, MAX_LENGTH, pFile);
        fclose(pFile);

        return buff[0];
}
