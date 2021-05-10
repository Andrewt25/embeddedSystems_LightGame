#ifndef HELLOWORLD_GAME
#define HELLOWORLD_GAME

void game_init(void);
void game_cleanup(void);

int game_selectLight(void);
void game_waitForNeutral(void);

int game_getInput(void);

void game_updateScore(_Bool success);
void game_displayScore(void);



#endif