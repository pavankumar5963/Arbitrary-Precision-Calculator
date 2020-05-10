#include<stdio.h>
#include "double_list.h"

Status delete_list(Dlist **head, Dlist **tail)
{
	if (*head == NULL)
	{
		printf("Error: List is empty\n");
		return failure;
	}
	
	while (*head != NULL)
	{
		delete_last(head, tail);
	}
	return success;
}
