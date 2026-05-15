#include "main.h"
#include "player.h"
SDL_Context *ctx;

bool create_game_window(void)
{
	bool window = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to initialize SDL!: %s", SDL_GetError());
		window = false;
	}
	else {
		ctx->screen = SDL_CreateWindow("raycaster",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	}
	if (!ctx->screen) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Failed to create screen: %s", SDL_GetError());
		window = false;
	}
	else {
		ctx->renderer = SDL_CreateRenderer(ctx->screen, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!ctx->renderer) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR,
				"Failed to create a renderer: %s", SDL_GetError());
		}
		else {
			SDL_SetRenderDrawColor(ctx->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(ctx->renderer);
		}
	}
	return (window);
}
