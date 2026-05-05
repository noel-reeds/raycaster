#include "main.h"
#include "player.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	ctx = malloc(sizeof(SDL_Context));
	p8 = malloc(sizeof(Player));
	camera_p = malloc(sizeof(Plane));
	init_var();

	if (!create_game_window()) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "FAILED: %s",
			SDL_GetError());
	}
	else {
		bool gameover = false;
		SDL_Event event_e;
		const Uint8 *key_state = SDL_GetKeyboardState(NULL);

		if (!key_state) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Something went wrong!");
			exit(1);
		}
		
		while (!gameover)
		{
			while (SDL_PollEvent(&event_e) != 0)
			{
				if (event_e.type == SDL_QUIT)
					gameover = true;
				move_player(event_e);
			}
			draw_player_map(ctx->renderer);
			draw_player(ctx->renderer);
			SDL_RenderPresent(ctx->renderer);
			SDL_SetRenderDrawColor(ctx->renderer, 0x4A, 0x0F, 0x0B, 0x0F);
			SDL_RenderClear(ctx->renderer);
		}
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, 
								"Event queue is empty!");
		free_allocated_mem();
	}
}
