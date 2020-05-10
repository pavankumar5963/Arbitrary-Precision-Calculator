#include "double_list.h"

/* Function defination */

Status print_list(Dlist *head)
{
	if (head)
	{
		while(head != NULL)
		{
			printf("%0*d ", MAX_DIGIT,head->data);
			head = head->next;
		}
		printf("\n");
		return success;
	}
	else
	{
		printf("Error: List is empty\n");
		return failure;
	}
}

uint total_node(Dlist *head)
{
	uint count = 0;
	if (head == NULL)
	{
		return count;
	}
	count = 1;
	while(head->next)
	{
		count++;
		head = head->next;
	}
	return count;
}
