#ifndef _EVENTS_H_
#define _EVENTS_H_
#include "main.h"
#include "player.h"
#include "map.h"

void handle_keyboard_event(Player *self, SDL_Event e);
bool check_collision(Player *self, SDL_Rect A, SDL_Rect B);
bool collision(Player *self, int map[MAP_HEIGHT][MAP_WIDTH]);

#endif
