#include "linked-l.h"

void pop_node_e(node_e *head){ // double pouint8_ter to modify the head pouint8_ter

	Enemy retval;
	node_e * next_node = NULL;

	if (head == NULL) {
		return;
	}

	next_node = (head)->next;
	retval = (head)->enemy;
	free(head);
	head = next_node;

	return;
}


void remove_node_e_idx(node_e * head, uint8_t n) {
    uint8_t i = 0;
    Enemy retval; 
    node_e * current = head;
    node_e * temp_node = NULL;

    if (n == 0) {
	    
        pop_node_e(head);
	return;
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
		printf("Not at the end\n");
		return;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->enemy;
    current->next = temp_node->next;
    free(temp_node);

    return;

}
