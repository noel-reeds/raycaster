#include "../include/main.h"
#include "../include/player.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	ctx = malloc(sizeof(SDL_Context));
	custom_texture = malloc(sizeof(_Texture));
	camera_p = malloc(sizeof(Plane));

	init_player_vars(&p8);

	if (!create_game_window()) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "FAILED: %s",
			SDL_GetError());
	}
	if(!loads_player_texture(&p8, ctx->renderer)) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Couldn't load player!");
	}
	else {
		bool gameover = false;
		SDL_Event event_e;

		while (!gameover)
		{
			while (SDL_PollEvent(&event_e) != 0)
			{
				if (event_e.type == SDL_QUIT)
					gameover = true;
				handle_keyboard_event(&p8, event_e);
			}
			draw_player_map(&p8, ctx->renderer);
			SDL_SetRenderDrawColor(ctx->renderer, 0x00, 0x00, 0x00, 0xFF);
			SDL_RenderFillRect(ctx->renderer, &p8.collider);
			render_player(ctx->renderer, custom_texture,
					p8.pos_x, p8.pos_y, NULL, 0.0, NULL, SDL_FLIP_NONE);
			move_player(&p8, );
			SDL_RenderPresent(ctx->renderer);
		}
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, 
								"Event queue is empty!");
		free_allocated_mem();
	}
}
