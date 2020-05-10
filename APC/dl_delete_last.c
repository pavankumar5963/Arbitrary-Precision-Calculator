#include<stdio.h>
#include "double_list.h"
#include<stdlib.h>

/* Function definition */

Status delete_last(Dlist **head, Dlist **tail)
{
	if (*head == NULL)
	{
		printf("Error: List is empty\n");
		return failure;
	}

	if ((*head)->next)
	{
		Dlist *temp;
		temp = (*tail)->prev;
		temp->next = NULL;
		free(*tail);
		*tail = temp;
	}
	else
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	return success;
}
