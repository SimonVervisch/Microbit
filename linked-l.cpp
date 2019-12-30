#include "linked-l.h"

void remove_first(list *list){ // double pouint8_ter to modify the head pouint8_ter
	
	Node *head = list->head;

	void* retval;
	Node * next_node = NULL;

	if (head == NULL) {
		return;
	}

	next_node = head->next;
	retval = head->data;
	free(head);
	head = next_node;

	return;
}


void remove_node_idx(node_t *head, uint8_t n) {
    uint8_t i = 0;
    Enemy retval; 
    node_t * current = head; //current, next, temp_node 
    node_t * temp_node = NULL;

    if (n == 0) {
        pop_node_t(head);
	return;
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
		printf("Not at the end\n");
		return;
        }
        current = current->next;
    }

    temp_node = current->next; //connect current with double next
    retval = temp_node->enemy; 
    current->next = temp_node->next;
    free(temp_node);

    return;

}
