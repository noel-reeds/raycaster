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

/* Player function defs */
void start_cast_rays(void);

#endif
