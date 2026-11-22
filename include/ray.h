#ifndef _RAY_H_
#define _RAY_H_
#include "player.h"

typedef struct light_r {
	double dirx, diry;
	double irdx, irdy;
	double rdx, rdy;
} Ray;

typedef struct wall {
	int side;
	int stepx, stepy, hit;
} Wall;

typedef struct {
	double x, y;
	double camera_x;
	double pw_dist;
} Plane;

extern Plane *camera_p;
extern Ray *ray;
extern Wall *wall;

void start_cast_rays(Player *self);

#endif
