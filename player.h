#ifndef _PLAYER_H_
#define _PLAYER_H_

/* Player structs and coordinates */
typedef struct {
	double pos_x, pos_y;
	double pos_a;
} Player;

/* Defines a Player p8 */
extern Player *p8;

/* Player function defs */
void start_cast_rays(void);

#endif
