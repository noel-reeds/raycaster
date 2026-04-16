#include "main.h"

int main(void)
{
	/* player start pos
	double posx = 22, posy = 12;
	double dirx = -1, diry = 0;
	double time = 0;
	double old_time = 0;
	*/

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
			SDL_SetRenderDrawColor(renderer, 0x4A, 0x0F, 0x0B, 0x0F);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}
		SDL_Log("Event queue is empty.");
	}
}
