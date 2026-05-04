#include "main.h"
#include "player.h"

Player *p8;
Plane *camera_p;

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	ctx = malloc(sizeof(SDL_Context));
	p8 = malloc(sizeof(Player));
	camera_p = malloc(sizeof(Plane));

	/* sets player positions */
	init_var();
	/* sets up an SDL2 window */
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
			while (SDL_PollEvent(&event_e) != 0) {
				if (event_e.type == SDL_QUIT)
					gameover = true;
			}
			/* draw the player map */
			draw_player_map(ctx->renderer);
			/* draw the player */
			draw_player(ctx->renderer);
			SDL_RenderPresent(ctx->renderer);
			SDL_SetRenderDrawColor(ctx->renderer, 0x4A, 0x0F, 0x0B, 0x0F);
			SDL_RenderClear(ctx->renderer);
			// move_player(key_state, p8->pos_x, p8->pos_y);
			if (key_state[SDL_SCANCODE_D] && p8->pos_x < SCREEN_WIDTH - p8->pw)
				p8->pos_x += 2;
			else if (p8->pos_x > SCREEN_WIDTH - p8->pw)
				p8->pos_x = SCREEN_WIDTH - p8->pw;
			if (key_state[SDL_SCANCODE_S] && p8->pos_y < SCREEN_HEIGHT - p8->pw)
				p8->pos_y += 2;
			else if (p8->pos_y > SCREEN_HEIGHT - p8->pw)
				p8->pos_y = SCREEN_HEIGHT - p8->pw;
			if (key_state[SDL_SCANCODE_W] && p8->pos_y > 0)
				p8->pos_y -= 2;
			else if (p8->pos_y < 0)
				p8->pos_y = 0;
			if (key_state[SDL_SCANCODE_A] && p8->pos_x > 0)
				p8->pos_x -= 2;
			else if (p8->pos_x < 0)
				p8->pos_x = 0;
		}
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, 
								"Event queue is empty!");
		free_allocated_mem();
	}
}
