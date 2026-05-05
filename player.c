#include "main.h"
#include "player.h"

int map_x, map_y, step_x, step_y, side, hit;
double pw_dist, camera_x, raydir_x, raydir_y, raydist_x;
double initial_raydist_x, initial_raydist_y, raydist_y;

void draw_player(SDL_Renderer *rdr) {
	SDL_Rect player8 = { p8->pos_x, p8->pos_y, p8->pw, p8->pw };
	SDL_SetRenderDrawColor(rdr, 0xF5, 0xEB, 0x27, 0xFF);
	SDL_RenderFillRect(rdr, &player8);
}

void init_var(void) {
	p8->pos_x = 45;
	p8->pos_y = 40;
	p8->dir_x = -1;
	p8->dir_y = 0;
	p8->pw = 10;
	camera_p->_x = 0;
	camera_p->_y = 0.66;
	map_x = (int)p8->pos_x;
	map_y = (int)p8->pos_y;
	hit = 0;
}

void move_player(SDL_Event event_e)
{
	if (event_e.type == SDL_KEYDOWN)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			p8->pos_y -= 2;
			break;

			case SDLK_s:
			p8->pos_y += 2;
			break;

			case SDLK_d:
			p8->pos_x += 2;
			break;

			case SDLK_a:
			p8->pos_x -= 2;
			break;
		}
	}
	if (event_e.type == SDL_KEYUP)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			p8->pos_y -= 2;
			break;

			case SDLK_s:
			p8->pos_y += 2;
			break;

			case SDLK_d:
			p8->pos_x += 2;
			break;

			case SDLK_a:
			p8->pos_x -= 2;
			break;
		}
	}
	if (p8->pos_x > SCREEN_WIDTH - p8->pw)
        p8->pos_x = SCREEN_WIDTH - p8->pw;
    if (p8->pos_y > SCREEN_HEIGHT - p8->pw)
        p8->pos_y = SCREEN_HEIGHT - p8->pw;
    if (p8->pos_y < 0)
        p8->pos_y = 0;
    if (p8->pos_x < 0)
        p8->pos_x = 0;
}
