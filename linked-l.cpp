#include "linked-l.h"

void remove_first(list *list, TypeList typelist){ // 

	Node *head = list->head;

	void* retval;
	Node * next_node = NULL;

	if (head == NULL) {
		return;
	}

	next_node = head->next;
	retval = (*head).data;
	retval = head->data; // TODO: Zorg dat de cast van void pointer naar correcte grootte gebeurt
	free(head);
	head = next_node;

	return;
}


void remove_node_idx(list *list, uint8_t n) {
	uint8_t i = 0;
	void* retval;

	Node * head = list->head;

	Node * current = head; //current, next, temp_node 
	Node * temp_node = NULL;

	if (n == 0) {
		remove_first(head);
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
