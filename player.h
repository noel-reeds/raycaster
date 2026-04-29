#ifndef _PLAYER_H_
#define _PLAYER_H_

/* Player structs and coordinates */
typedef struct {
	double pos_x, pos_y;
	double dir_x, dir_y;
	double pos_a;
} Player;

/* Camera plane  coordinates */
typedef struct {
	double _x, _y;
} Plane;

/* Defines a Player p8 */
extern Player *p8;
extern Plane *camera_p;

/* det. the grid/square the ray is in the map */
extern int map_x;
extern int map_y;
/* if x-side is hit, side = 0, if y-side is hit, side = 1 */
extern int side;
/* perpendicular dist from camera plane to the wall */
extern double pw_dist;
/* maps camera plane to determine ray directions */
extern double camera_x;
/* ray directions */
extern double raydir_x, raydir_y;
/* length of the ray from player pos to next x or y-side */
extern double initial_raydist_x, initial_raydist_y;
/*length of ray from one x or y-side to next x or y-side */
extern double raydist_x, raydist_y;
/* what dir to step in x or y-dir (either +1 or -1) */
extern int step_x, step_y, hit;

/* Player function defs */
void start_cast_rays(void);
void init_var(void);
void draw_player(void);

#endif
