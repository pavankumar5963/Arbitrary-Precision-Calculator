#include "double_list.h"

/* Function defination */ 
Status insert_last(Dlist **head, data_t data, Dlist **tail)
{
		Dlist *new;
		new = malloc(sizeof(Dlist));
		if (new) 			// Memory validation
		{

				new->data = data;
				new->prev = NULL;
				new->next = NULL;

				/* If list is not empty */
				if (*head)
				{
					(*tail)->next = new;
					new->prev = *tail;
					*tail = new;
					return success;
				}
				/* If list is empty */
				else
				{
						*head = new;
						*tail = new;
						return success;
				}
		}
		else
		{
				printf("Error: Memory not available\n");
				return failure;
		}
}
