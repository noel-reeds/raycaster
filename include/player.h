#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"

/* Player structs and coordinates */
typedef struct {
	double pos_x, pos_y, pveloc;
	double dir_x, dir_y;
	SDL_Rect collider;
	double vel_x, vel_y;
	double p_width, p_height;
} Player;

/* Camera plane  coordinates */
typedef struct {
	double _x, _y;
} Plane;

/* Defines a Player p8 */
extern Player p8;
extern Plane *camera_p;

/* det. the grid/square the ray is in the map */
extern int map_x;
extern int map_y;
/* if x-side is hit, side = 0, if y-side is hit, side = 1 */
extern int side;
/* perpendicular dist from camera plane to the wall */
extern double pw_dist;
/* maps camera plane to determine ray directions */
extern double camera_x;
/* ray directions */
extern double raydir_x, raydir_y;
/* length of the ray from player pos to next x or y-side */
extern double initial_raydist_x, initial_raydist_y;
/*length of ray from one x or y-side to next x or y-side */
extern double raydist_x, raydist_y;
/* what dir to step in x or y-dir (either +1 or -1) */
extern int step_x, step_y, hit;

/* Player function defs */
void start_cast_rays(Player *self);
void init_player_vars(Player *self);
void draw_player(Player *self, SDL_Renderer *renderer);
void handle_keyboard_event(Player *self, SDL_Event e);
void render_player(SDL_Renderer *rndr, _Texture *custom_texture, int player_posx, int player_posy, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip);
bool loads_player_texture(Player *self, SDL_Renderer *rdr);
void draw_player_map(Player *self, SDL_Renderer *rdr);
void move_player(Player *self, SDL_Rect wall);
bool check_collision(Player *self, SDL_Rect A, SDL_Rect B);



#endif
