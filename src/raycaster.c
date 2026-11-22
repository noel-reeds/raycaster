#include "../include/main.h"
#include "../include/player.h"
#include "../include/ray.h"
#include "../include/map.h"
#include "../include/events.h"

_Texture *custom_texture;
Player p8;
Plane *camera_p

void start_cast_rays(Player *self)
{
	for (int x = 0; x < SCREEN_WIDTH; x++) {
        // calc. ray direction and position
		camera_p->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;

		ray->dirx = self->dirx + camera_p->x * camera_p->camera_x;
		ray->diry = self->diry + camera_p->y * camera_p->camera_x;

		ray->rdx = (ray->dirx == 0) ? 1e30 : fabs(1.0 / ray->dirx);
		ray->rdy = (ray->diry == 0) ? 1e30 : fabs(1.0 / ray->diry);

		if (ray->rdx < 0) {
			wall->stepx = -1;
			ray->irdx = (self->pos_x - tile_map->mapx) * ray->rdx;
		}
		else {
			wall->step_y = 1;
			ray->irdx = (tile_map->map_x + 1.0 - self->posx) * ray->rdx;
		}
		if (ray->rdy < 0) {
			wall->stepx = -1;
			ray->irdy = (self->posy - tile_map->mapy) * ray->rdy;
		}
		else {
			wall->stepy = 1;
			ray->irdy = (tile_map->mapx + 1.0 - self->posy) * ray->rdy;
		}
		while (!wall->hit) {
			/* jump to the next square either in x-dir or y-dir */
			if (ray->irdx < ray->irdy) {
				ray->irdx += ray->rdx;
				tile_map->mapx += wall->stepx;
				wall->side = 0;
			}
			else {
				ray->irdy += ray->rdy;
				tile_map->mapy += wall->stepy;
				wall->side = 1;
			}
			/* check if ray is inside a wall */
			if (map[tile_map->mapx][tile_map->mapy] > 0)
				wall->hit = 1;
		}
		/* finds shortest distance to the wall */
		if (wall->side == 0)
			camera_p->pw_dist = ray->irdx - ray->rdx;
		else
			camera_p->pw_dist = ray->irdy - ray->rdy;
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
