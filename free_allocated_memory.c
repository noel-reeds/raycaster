#include "main.h"
#include "player.h"

void free_allocated_mem(void) {
	if (ctx) {
		free(ctx);
		ctx = NULL;
	}
}
