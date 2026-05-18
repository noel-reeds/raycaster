#ifndef _RAY_H_
#define _RAY_H_
#include "player.h"

typedef struct light_r {
	double raydir_x, raydir_y;
	double initial_raydist_x, initial_raydist_y;
	double raydist_x, raydist_y;
} Ray;

typedef struct wall {
	int side;
	int step_x, step_y, hit;
} Wall;

typedef struct {
	double _x, _y;
	double camera_x;
	double pw_dist;
} Plane;

extern Plane *camera_p;
extern Ray *ray_r;
extern Wall *wall;

void start_cast_rays(Player *self);

#endif
