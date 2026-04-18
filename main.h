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
#include <math.h>

/* Window or screen variables */
typedef struct {
	SDL_Window *screen;
	SDL_Renderer *renderer;
} SDL_Context;

extern SDL_Context *context;

/* Function defs */
bool create_game_window(void);
void draw_world_map(void);

#endif
