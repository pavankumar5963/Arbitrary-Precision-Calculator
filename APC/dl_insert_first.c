#include "double_list.h"

/* Function defination*/

Status insert_first(Dlist **head, data_t data, Dlist **tail)
{
	Dlist *new;
	new = (Dlist *) malloc(sizeof(Dlist));
	if (new)		// Check new is NULL or not
	{
		new->data = data;
		new->prev = NULL;
		new->next = NULL;
		if (*head == NULL)
		{
			*head = new;
			*tail = new;		
		}
		else
		{
			new->next = *head;
			(*head)->prev = new;
			*head = new;
		}
	}
	else
	{
		printf("Error: Memory not available\n");
		return failure;
	}
	return success;
}
