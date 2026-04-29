#include "main.h"
#include "player.h"
Player *p8;
Plane *camera_p;

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	/* set up player variables */
	init_var();
	/* create game window */
	ctx = malloc(sizeof(SDL_Context));
	p8 = malloc(sizeof(Player));
	camera_p = malloc(sizeof(Plane));

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
			SDL_SetRenderDrawColor(ctx->renderer, 0x4A, 0x0F, 0x0B, 0x0F);
			SDL_RenderClear(ctx->renderer);
			SDL_RenderPresent(ctx->renderer);
			//draw_player_map();
			//SDL_RenderClear(ctx->renderer);
			//SDL_RenderPresent(ctx->renderer);

		}
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
			"Event queue is empty!");
		free_allocated_mem();
	}
}

void start_cast_rays(void) {
	/* game loop starts here.. */
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		raydir_x = p8->dir_x + camera_p->_x * camera_x;
		raydir_y = p8->dir_y + camera_p->_y * camera_x;
		raydist_x = (raydir_x == 0) ? 1e30 : fabs(1.0 / raydir_x);
		raydist_y = (raydir_y == 0) ? 1e30 : fabs(1.0 / raydir_y);

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
				map_y += step_y;
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
		/* calculate line height to draw on screen */
		int line_h = (int)(SCREEN_HEIGHT / pw_dist);
		/* finds highest and lowest pixel to fill in current stripe */
		int draw_start = -line_h / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_h / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		/* choose wall color */
		SDL_Color color;

		switch(map[map_x][map_y]) {
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
		if (side == 1)
			//not-implemented yet.
		SDL_SetRenderDrawColor(ctx->renderer,
								color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(ctx->renderer, x, draw_start, x, draw_end);
	}
}
