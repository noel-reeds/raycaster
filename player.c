#include "main.h"
#include "player.h"

int map_x, map_y, step_x, step_y, side, hit;
double pw_dist, camera_x, raydir_x, raydir_y, raydist_x;
double initial_raydist_x, initial_raydist_y, raydist_y;

/* world map arr. */
int map[MAP_WIDTH][MAP_HEIGHT] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw_player_map(SDL_Renderer *rdr)
{
	int x=0, y=0, m_x=64;
	SDL_Rect sq = { x, y, m_x, m_x};

	for (x = 0; x < MAP_WIDTH; x++)
	{
		sq.x = x * m_x;
		for (y = 0; y < MAP_HEIGHT; y++)
		{
			sq.y = y * m_x;
			if (map[x][y] > 0) {
				SDL_SetRenderDrawColor(rdr, 128, 192, 255, 255);
			}
			else {
				SDL_SetRenderDrawColor(rdr, 0, 0, 0, 100);
			}
			SDL_RenderFillRect(rdr, &sq);
		}
	}
}

void draw_player(SDL_Renderer *rdr) {
	SDL_Rect player8 = { p8->pos_x, p8->pos_y, p8->pw, p8->pw };
	SDL_SetRenderDrawColor(rdr, 0xF5, 0xEB, 0x27, 0xFF);
	SDL_RenderFillRect(rdr, &player8);
}

void init_var(void) {
	p8->pos_x = 22;
	p8->pos_y = 12;
	p8->dir_x = -1;
	p8->dir_y = 0;
	p8->pw = 10;
	camera_p->_x = 0;
	camera_p->_y = 0.66;
	map_x = (int)p8->pos_x;
	map_y = (int)p8->pos_y;
	hit = 0;
}

void move_player(const Uint8 *keystates, double pos_x, double pos_y) {
	if (keystates[SDL_SCANCODE_J] && pos_x < SCREEN_WIDTH)
		pos_x += 2;
	else if (p8->pos_x > SCREEN_WIDTH)
		pos_x = SCREEN_WIDTH;
	if (keystates[SDL_SCANCODE_B])
		pos_y += 2;
	if (keystates[SDL_SCANCODE_Y] && pos_y > 0)
		pos_y -= 2;
	else if (p8->pos_y < 0)
		pos_y = 0;
	if (keystates[SDL_SCANCODE_F] && pos_x > 0)
		pos_x -= 2;
	else if (p8->pos_x < 0)
		pos_x = 0;
}
