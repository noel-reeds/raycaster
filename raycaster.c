#include "main.h"
#include "player.h"
Player *p8;
Plane *camera_p;

int main(int argc, char *argv[])
{
	/* create game window */
	if (!create_game_window()) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "FAILED: %s",
			SDL_GetError());
	}
	else {
		bool quit = false;
		SDL_Event event_e;

		while (!quit)
		{
			while (SDL_PollEvent(&event_e) != 0) {
				if (event_e.type == SDL_QUIT)
					quit = true;
			}
			SDL_SetRenderDrawColor(context->renderer, 0x4A, 0x0F, 0x0B, 0x0F);
			SDL_RenderClear(context->renderer);
			SDL_RenderPresent(context->renderer);
		}
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
			"Event queue is empty!");
	}
}

void start_cast_rays(void) {
	/* player start positions coordinates */
	p8->pos_x = 22;
	p8->pos_y = 12;
	/* player direction coordinates */
	p8->dir_x = -1;
	p8->dir_y = 0;
	/* camera plane coordinates */
	camera_p->_x = 0;
	camera_p->_y = 0.66;
	/* det. the grid/square the ray is in the map */
	int map_x = (int)p8->pos_x;
	int map_y = (int)p8->pos_y;
	/* if x-side is hit, side = 0, if y-side is hit, side = 1 */
	int side;

	/* game loop starts here.. */
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		/* maps camera plane to determine ray directions */
		double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		/* ray directions */
		double raydir_x = p8->dir_x + camera_p->_x * camera_x;
		double raydir_y = p8->dir_y + camera_p->_y * camera_x;
		/* length of the ray from player pos to next x or y-side */
		double initial_raydist_x;
		double initial_raydist_y;
		/*length of ray from one x or y-side to next x or y-side */
		double raydist_x = (raydir_x == 0) ? 1e30 : fabs(1.0 / raydir_x);
		double raydist_y = (raydir_y == 0) ? 1e30 : fabs(1.0 / raydir_y);
		/* what dir to step in x or y-dir (either +1 or -1) */
		int step_x, step_y;
		/* was a wall hit?*/
		int hit = 0;
		/* perpendicular dist from camera plane to the wall */
		double pw_dist;
		/* initial dist. from player and step dir */
		if (raydir_x < 0) {
			step_x = -1;
			initial_raydist_x = (p8->pos_x - map_x) * raydist_x;
		}
		else {
			step_y = 1;
			initial_raydist_x = (map_x + 1.0 - p8->pos_x) * raydist_x;
		}
		if (raydir_y < 0) {
			step_x = -1;
			initial_raydist_y = (p8->pos_y - map_y) * raydist_y;
		}
		else {
			step_y = 1;
			initial_raydist_y = (map_x + 1.0 - p8->pos_y) * raydist_y;
		}
		while (!hit) {
			/* jump to the next square either in x-dir or y-dir */
			if (initial_raydist_x < initial_raydist_y) {
				initial_raydist_x += raydist_x;
				map_x += step_x;
				side = 0;
			}
			else {
				initial_raydist_y += raydist_y;
				map_y += raydist_y;
				side = 1;
			}
			/* check if ray is inside a wall */
			if (map[map_x][map_y] > 0)
				hit = 1;
		}
		/* finds shortest distance to the wall */
		if (side == 0)
			pw_dist = initial_raydist_x - raydist_x;
		else
			pw_dist = initial_raydist_y - raydist_y;
	}
	/* calculate line of height to draw on screen */
	int line_h = (int)(SCREEN_HEIGHT / pw_dist);
	/* finds highest and lowest pixel to fill in current stripe */
	int draw_start = -line_h / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	int draw_end = line_h / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	/* choose wall color */
	SDL_Color clr;

	switch(map[map_x][map_y]) {
		case 1: clr{255, 0, 0};
		break;

		case 2: clr{0, 128, 0};
		break;

		case 3: clr{0, 0, 255};
		break;

		case 4: clr{255, 255, 255};
		break;

		default: clr{255, 255, 0};
	}
	if (side == 1)
		clr = clr / 2;
	SDL_SetRenderDrawColor(context->renderer, clr.r, clr.g, clr.b, clr.a);
	SDL_RenderDrawLine(context->renderer, x, draw_start, x, draw_end, clr);

}
