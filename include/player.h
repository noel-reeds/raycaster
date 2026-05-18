#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "main.h"

typedef struct {
	double pos_x, pos_y, pveloc;
	double dir_x, dir_y;
	SDL_Rect collider;
	double vel_x, vel_y;
	double p_width, p_height;
} Player;

extern Player p8;

bool loads_player_texture(Player *self, SDL_Renderer *rdr);
void move_player(Player *self, int map[MAP_HEIGHT][MAP_WIDTH]);
void draw_player(Player *self, SDL_Renderer *renderer);
void render_player(SDL_Renderer *rndr, _Texture *custom_texture, int player_posx, int player_posy, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip);
void init_player_vars(Player *self);

#endif
