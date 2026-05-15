#include "main.h"
#include "player.h"

void move_player(Player *self, SDL_Rect wall) {
	self->pos_x += self->vel_x;
	self->collider.x = self->pos_x;

	if (self->pos_x < 0 || self->pos_x + self->p_width > SCREEN_WIDTH ||
			check_collision(self, self->collider, wall)) {
		self->pos_x -= self->vel_x;
		self->collider.x = self->pos_x;
	}

	self->pos_y += self->vel_y;
	self->collider.y = self->pos_y;

	if (self->pos_y < 0 || self->pos_y + self->p_height > SCREEN_HEIGHT ||
			check_collision(self, self->collider, wall)) {
		self->pos_y -= self->vel_y;
		self->collider.y = self->pos_y;
	}
}

bool check_collision(Player *self, SDL_Rect player, SDL_Rect wall) {
	int left_p, right_p, top_p, bottom_p;
	int left_w, right_w, top_w, bottom_w;

	left_p = player.x;
	right_p = player.x + player.w;
	top_p = player.y;
	bottom_p = player.y + player.h;

	left_w = wall.x;
	right_w = wall.x + wall.w;
	top_w = wall.y;
	bottom_w = wall.y + wall.h;

	if (left_p >= right_w || right_p <= left_w)
		return false;
	if (top_p >= bottom_w || bottom_p <= top_w)
		return false;
	return true;
}
