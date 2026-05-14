#include "main.h"
#include "player.h"

void move_player(Player *self) {
	self->pos_x += self->vel_x;
	if (self->pos_x < 0 || self->pos_x + self->p_size > SCREEN_WIDTH) {
		self->pos_x -= self->vel_x;
	}

	self->pos_y += self->vel_y;
	if (self->pos_y < 0 || self->pos_y + self->p_size > SCREEN_HEIGHT) {
		self->pos_y -= self->vel_y;
	}
}
