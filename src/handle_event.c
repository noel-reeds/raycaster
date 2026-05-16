#include "../include/main.h"
#include "../include/player.h"

void handle_keyboard_event(Player *self, SDL_Event event_e)
{
	if (event_e.type == SDL_KEYDOWN && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_y -= self->pveloc;
			break;

			case SDLK_s:
			self->vel_y += self->pveloc;
			break;

			case SDLK_d:
			self->vel_x += self->pveloc;
			break;

			case SDLK_a:
			self->vel_x -= self->pveloc;
			break;
		}
	}
	else if (event_e.type == SDL_KEYUP && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_y += self->pveloc;
			break;

			case SDLK_s:
			self->vel_y -= self->pveloc;
			break;

			case SDLK_d:
			self->vel_x -= self->pveloc;
			break;

			case SDLK_a:
			self->vel_x += self->pveloc;
			break;
		}
	}
}
