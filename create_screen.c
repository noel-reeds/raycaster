#include "main.h"
SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;

bool create_game_window(void)
{
	bool window = true;

	if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to initialize SDL!: %s", SDL_GetError());
		window = false;
	}
	else {
		screen = SDL_CreateWindow("raycaster", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	}
	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to create screen: %s", SDL_GetError());
		window = false;
	}
	else {
		renderer = SDL_CreateRenderer(screen, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!renderer) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR,
				"Failed to create a renderer: %s", SDL_GetError());
		}
		else {
			SDL_SetRenderDrawColor(renderer, 0x4A, 0x0F, 0x0B, 0x0F);
		}
	}
	return (window);
}
