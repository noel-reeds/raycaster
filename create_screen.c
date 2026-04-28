#include "main.h"
SDL_Context *context;

bool create_game_window(void)
{
	bool window = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to initialize SDL!: %s", SDL_GetError());
		window = false;
	}
	else {
		context->screen = SDL_CreateWindow("raycaster",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	}
	if (!context->screen) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to create screen: %s", SDL_GetError());
		window = false;
	}
	else {
		context->renderer = SDL_CreateRenderer(context->screen, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!context->renderer) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR,
				"Failed to create a renderer: %s", SDL_GetError());
		}
		else {
			SDL_SetRenderDrawColor(context->renderer, 0x4A, 0x0F, 0x0B, 0x0F);
		}
	}
	return (window);
}
