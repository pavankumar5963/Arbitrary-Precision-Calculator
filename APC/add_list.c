#include "double_list.h"

Status add_list(Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail)
{
	int carry = 0;
	while (op1_tail || op2_tail)
	{
//		printf("carry %d\n", carry);
		if (op1_tail && op2_tail)
		{
			carry = carry_sum(op1_tail->data, op2_tail->data, carry, result_head, result_tail);
			op1_tail = op1_tail->prev;
			op2_tail = op2_tail->prev;
		}
		else if(op1_tail)
		{
			carry = carry_sum(op1_tail->data, 0, carry, result_head, result_tail);
			
			op1_tail = op1_tail->prev;
		}
		else
		{
			carry = carry_sum(0, op2_tail->data, carry, result_head, result_tail);
		
			op2_tail = op2_tail->prev;
		}
	}
	if (carry)
	{
		insert_first(result_head, carry, result_tail);
	}
	return success;
}
