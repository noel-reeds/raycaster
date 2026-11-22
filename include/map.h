#ifndef _MAP_H_
#define _MAP_H_
#include "main.h"
#include "player.h"


typedef struct sq_map {
	int mapx;
	int mapy;
} Map;

extern Map *tile_map;
extern int map[MAP_WIDTH][MAP_HEIGHT];

void draw_player_map(Player *self, SDL_Renderer *rdr);

#endif
