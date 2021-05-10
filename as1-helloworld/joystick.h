#ifndef JOYSTICK_CONTROL
#define JOYSTICK_CONTROL

enum eJoystickDirections{
    JOYSTICK_UP = 0,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT,
    JOYSTICK_NUMBER_OF_DIRECTIONS,
};

_Bool Joystick_isDirectionPressed(enum eJoystickDirections direction);


#endif