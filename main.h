#ifndef _MAIN_H_
#define _MAIN_H_

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* SDL & std headers */
#include <SDL.h>
#include <stdbool.h>
#include <SDL_image.h>
#include "SDL_ttf.h"

/* Window or screen variables */
extern SDL_Window *screen;
extern SDL_Renderer *renderer;

/* Function defs */
bool create_game_window(void);


#endif
