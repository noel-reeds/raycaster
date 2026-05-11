#include "main.h"
#include "player.h"

void handle_keyboard_event(Player *self, SDL_Event event_e)
{
	if (event_e.type == SDL_KEYDOWN && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->pos_y -= self->pveloc;
			break;

			case SDLK_s:
			self->pos_y += self->pveloc;
			break;

			case SDLK_d:
			self->pos_x += self->pveloc;
			break;

			case SDLK_a:
			self->pos_x -= self->pveloc;
			break;
		}
	}
	else if (event_e.type == SDL_KEYUP && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->pos_y -= self->pveloc;
			break;

			case SDLK_s:
			self->pos_y += self->pveloc;
			break;

			case SDLK_d:
			self->pos_x += self->pveloc;
			break;

			case SDLK_a:
			self->pos_x -= self->pveloc;
			break;
		}
	}
	if (self->pos_x > SCREEN_WIDTH - self->pw)
        self->pos_x = SCREEN_WIDTH - self->pw;
    if (self->pos_y > SCREEN_HEIGHT - self->pw)
        self->pos_y = SCREEN_HEIGHT - self->pw;
    if (self->pos_y < 0)
        self->pos_y = 0;
    if (self->pos_x < 0)
        self->pos_x = 0;
}
