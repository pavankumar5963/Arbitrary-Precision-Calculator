#include "double_list.h"

/* Function defination */
Status delete_first(Dlist **head, Dlist **tail)
{
	if (*head)
	{
		Dlist *ptr;
		ptr = (*head)->next;
		if (*head == *tail)
		{
			tail = NULL;	
		}
		free(*head);
		*head = ptr;
	}
	else
	{
		printf("Error: List is empty\n");
		return failure;	
	}
	return success;
}
