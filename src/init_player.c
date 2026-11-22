#include "../include/main.h"
#include "../include/player.h"
#include "../include/map.h"
#include "../include/ray.h"

Map *tile_map;
Wall *wall;
Ray *ray;

void init_player_vars(Player *self) {
	self->posx = 20;
	self->posy = 20;

	self->p_width = 20;
	self->p_height = 20;

	self->pveloc = 5;

	self->collider.w = self->p_width;
	self->collider.h = self->p_height;

	self->velx = 0;
	self->vely = 0;

	self->dirx = -1;
	self->diry = 0;

	camera_p->x = 0;
	camera_p->y = 0.66;
	tile_map->mapx = (int)self->posx;
	tile_map->mapy = (int)self->posy;
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
