#ifndef _MAIN_H_
#define _MAIN_H_

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480

/* SDL & std headers */
#include <SDL.h>
#include <stdbool.h>
#include <SDL_image.h>
#include "SDL_ttf.h"
#include "SDL_keyboard.h"
#include "SDL_scancode.h"
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int map[MAP_WIDTH][MAP_HEIGHT];

/* Window or screen variables */
typedef struct {
	SDL_Window *screen;
	SDL_Renderer *renderer;
} SDL_Context;

typedef struct {
	SDL_Texture *Texture;
	int w;
	int h;
} _Texture;

extern _Texture *custom_texture;
extern SDL_Context *ctx;
extern int map[MAP_WIDTH][MAP_HEIGHT];

/* Function defs */
bool create_game_window(void);
void free_allocated_mem(void);
bool load_from_file(_Texture *T, const char *str_path);

#endif
