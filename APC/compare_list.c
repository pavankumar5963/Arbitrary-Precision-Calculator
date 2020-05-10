#include "double_list.h"

Status compare (Dlist *op1_head, Dlist *op2_head)
{
	uint node1 = total_node(op1_head);	
	uint node2 = total_node(op2_head);
//	printf("node1: %d, node2: %d\n", node1, node2);
	if (node1 > node2)
	{
		return more;
	}
	else if (node1 < node2)
	{
		return less;
	}
	else
	{
		while (op1_head->data == op2_head->data)
		{
			op1_head = op1_head->next;
			op2_head = op2_head->next;
			if (op1_head == NULL)
			{
				break;
			}
		}
		if (op1_head)
		{
			if (op1_head->data > op2_head->data)
			{
				return more;
			}
			else
			{
				return less;
			}
		}
		else
		{
			return equal;
		}	
	}
}
