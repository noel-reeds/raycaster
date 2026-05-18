#include "../include/main.h"
#include "../include/player.h"
#include "../include/map.h"
#include "../include/ray.h"

Map *tile_map;
Wall *wall;
Ray *ray_r;

void init_player_vars(Player *self) {
	self->pos_x = 20;
	self->pos_y = 20;

	self->p_width = 20;
	self->p_height = 20;

	self->pveloc = 10;

	self->collider.w = self->p_width;
	self->collider.h = self->p_height;

	self->vel_x = 0;
	self->vel_y = 0;

	self->dir_x = -1;
	self->dir_y = 0;

	camera_p->_x = 0;
	camera_p->_y = 0.66;
	tile_map->map_x = (int)self->pos_x;
	tile_map->map_y = (int)self->pos_y;
	wall->hit = 0;
}

bool loads_player_texture(Player *self, SDL_Renderer *rdr) {
	(void)self;
	(void)rdr;
	if (!load_from_file(custom_texture, "assets/player.bmp")) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "An error with media!");
		exit(-1);
		return false;
	}
	return true;
}
