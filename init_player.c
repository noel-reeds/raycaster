#include "main.h"
#include "player.h"

int map_x, map_y, step_x, step_y, side, hit;
double pw_dist, camera_x, raydir_x, raydir_y, raydist_x;
double initial_raydist_x, initial_raydist_y, raydist_y;

void init_player_vars(Player *self) {
	self->pos_x = 45;
	self->pos_y = 45;
	self->pveloc = 10;
	self->p_size = 15;

	self->collider.w = 45;
	self->collider.h = 45;

	self->vel_x = 0;
	self->vel_y = 0;

	self->dir_x = -1;
	self->dir_y = 0;

	camera_p->_x = 0;
	camera_p->_y = 0.66;
	map_x = (int)self->pos_x;
	map_y = (int)self->pos_y;
	hit = 0;
}

bool loads_player_texture(Player *self, SDL_Renderer *rdr) {
	(void)self;
	(void)rdr;
	if (!load_from_file(custom_texture, "player.bmp")) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "An error with media!");
		exit(-1);
		return false;
	}
	return true;
}

