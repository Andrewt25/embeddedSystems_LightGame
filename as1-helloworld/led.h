#ifndef LED_CONTROL
#define LED_CONTROL

enum eLedLights{
    LED_0 = 0,
    LED_1,
    LED_2,
    LED_3,
    LED_NUMBER_OF_LIGHTS,
};
enum eLedState{
    LED_OFF = 0,
    LED_ON,
};
void led_init(void);
void led_cleanUp(void);
void led_toggle(enum eLedLights led);

void led_flashCorrect(void);
void led_flashIncorrect(void);


#endif