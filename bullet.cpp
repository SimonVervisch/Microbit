#include "bullet.h"
#include "game.h"
#include "player.h"


void add_bullet(bool player_bullet){ // at the moment only a player can fire
	Bullet bullet;

	bullet.pos.y = player.pos.y;
	bullet.pos.x = player.pos.x;
	bullet.player_bullet = player_bullet;

	node_b * head = NULL;
	head = (node_b *) malloc(sizeof(node_b));
	/*

	if (head == NULL) { // at the moment, only one bullet for the player
		return 1;
	}
	*/
	head->bullet = bullet;
	head->next = NULL;

	game.bullet_list = head;



}

void remove_bullet(){
	//pop_node_e

}
