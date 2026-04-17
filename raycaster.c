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

	/* game loop starts here.. */
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		/* maps camera plane to determine ray directions */
		double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		double raydir_x = p8->dir_x + camera_p->_x * camera_x;
		double raydir_y = p8->dir_y + camera_p->_y * camera_x;
		/* det. the box the ray is in the map */
		int map_x = (int)p8->pos_x;
		int map_y = (int)p8->pos_y;
		/* length of the ray from player pos to next x or y-side */
		double side_x;
		double side_y;
		/*length of ray from one x or y-side to next x or y-side */
	}
}
