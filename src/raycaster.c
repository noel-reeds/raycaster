#include "../include/main.h"
#include "../include/player.h"
#include "../include/ray.h"
#include "../include/map.h"
#include "../include/events.h"

_Texture *custom_texture;
Player p8;
Plane *camera_p;

void start_cast_rays(Player *self) {
	/* game loop starts here.. */
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		camera_p->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_r->raydir_x = self->dir_x + camera_p->_x * camera_p->camera_x;
		ray_r->raydir_y = self->dir_y + camera_p->_y * camera_p->camera_x;
		ray_r->raydist_x = (ray_r->raydir_x == 0) ? 1e30 : fabs(1.0 / ray_r->raydir_x);
		ray_r->raydist_y = (ray_r->raydir_y == 0) ? 1e30 : fabs(1.0 / ray_r->raydir_y);

		if (ray_r->raydir_x < 0) {
			wall->step_x = -1;
			ray_r->initial_raydist_x = (self->pos_x - tile_map->map_x) * ray_r->raydist_x;
		}
		else {
			wall->step_y = 1;
			ray_r->initial_raydist_x = (tile_map->map_x + 1.0 - self->pos_x) * ray_r->raydist_x;
		}
		if (ray_r->raydir_y < 0) {
			wall->step_x = -1;
			ray_r->initial_raydist_y = (self->pos_y - tile_map->map_y) * ray_r->raydist_y;
		}
		else {
			wall->step_y = 1;
			ray_r->initial_raydist_y = 
				(tile_map->map_x + 1.0 - self->pos_y) * ray_r->raydist_y;
		}
		while (!wall->hit) {
			/* jump to the next square either in x-dir or y-dir */
			if (ray_r->initial_raydist_x < ray_r->initial_raydist_y) {
				ray_r->initial_raydist_x += ray_r->raydist_x;
				tile_map->map_x += wall->step_x;
				wall->side = 0;
			}
			else {
				ray_r->initial_raydist_y += ray_r->raydist_y;
				tile_map->map_y += wall->step_y;
				wall->side = 1;
			}
			/* check if ray is inside a wall */
			if (map[tile_map->map_x][tile_map->map_y] > 0)
				wall->hit = 1;
		}
		/* finds shortest distance to the wall */
		if (wall->side == 0)
			camera_p->pw_dist = ray_r->initial_raydist_x - ray_r->raydist_x;
		else
			camera_p->pw_dist = ray_r->initial_raydist_y - ray_r->raydist_y;
		/* calculate line height to draw on screen */
		int line_h = (int)(SCREEN_HEIGHT / camera_p->pw_dist);
		/* finds highest and lowest pixel to fill in current stripe */
		int draw_start = -line_h / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_h / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		/* choose wall color */
		SDL_Color color;

		switch(map[tile_map->map_x][tile_map->map_y]) {
			case 1: color = (SDL_Color){ .r = 255, .g = 0, .b = 0 };
			break;

			case 2: color = (SDL_Color){ .r = 0, .g = 128, .b = 0 };
			break;

			case 3: color = (SDL_Color){ .r = 0, .g = 0, .b = 255 };
			break;

			case 4: color = (SDL_Color){ .r = 255, .g = 255, .b = 255 };
			break;

			default: color = (SDL_Color){ .r = 255, .g = 255, .b = 0 };
		}
		if (wall->side == 1)
			//not-implemented yet.
		SDL_SetRenderDrawColor(ctx->renderer,
								color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(ctx->renderer, x, draw_start, x, draw_end);
	}
}
