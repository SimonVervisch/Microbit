#include "bullet.h"


void add_bullet(bool player_bullet){ // at the moment only a player can fire
	Bullet bullet;

	bullet.pos.y = player.pos.y;
	bullet.pos.x = player.pos.x;

	node_b * head = NULL;
	head = malloc(sizeof(node_t));

	if (head == NULL) { // at the moment, only one bullet for the player
		return 1;
	}
	head->bullet = bullet;
	head->next = NULL;

	game.bullet_list;



}

void remove_bullet() //gebruik chasing pointers
