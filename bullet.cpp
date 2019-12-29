#include "bullet.h"
#include "game.h"
#include "player.h"


void add_bullet(bool player_bullet){ // at the moment only a player can fire
	Bullet bullet;

	bullet.pos.y = player.pos.y;
	bullet.pos.x = player.pos.x + 1;
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
#define RIGHT_BORDER 4
void move_bullet(Bullet *bullet){
	static uint8_t i = 0;

	if(i < 20){
		i +=1;


	} else {
		if(bullet->pos.x != RIGHT_BORDER){
			bullet->pos.x += 1;
		} else {

		}
		i = 0;
	}
}


void remove_bullet(){
	//pop_node_e

}
