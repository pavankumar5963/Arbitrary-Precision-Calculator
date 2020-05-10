#include "double_list.h"

Status subs_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail)
{
	int borrow = 0, sign = 0;
	int value = compare (op1_head, op2_head);
	if (value == equal)
	{
		insert_first(result_head, 0,result_tail);
		return success;
	}
	if (value == less)
	{
		Dlist *temp;
		temp = op1_tail;
		op1_tail = op2_tail;
		op2_tail = temp;
		sign = 1;
	}
	
	while (op1_tail || op2_tail)
	{
//		printf("sub function op1 %d op2 %d\n", op1_tail->data, op2_tail->data);
		if (op1_tail && op2_tail)
		{
			borrow = borrow_list(op1_tail->data, op2_tail->data, borrow, op1_tail->prev, result_head, result_tail);
			op1_tail = op1_tail->prev;
			op2_tail = op2_tail->prev;
		}
		else 
		{
			borrow = borrow_list(op1_tail->data, 0, borrow, NULL, result_head, result_tail);
			op1_tail = op1_tail->prev;
		}
		/*if(op1_tail)
		{
			borrow = borrow_list(op1_tail->data, 0, borrow, NULL, result_head, result_tail);
			op1_tail = op1_tail->prev;
		}
		else
		{
			borrow = borrow_list(0, op2_tail->data, borrow, NULL, result_head, result_tail);
			op2_tail = op2_tail->prev;
		}*/
	}
	if (sign)
	{
		(*result_head)->data =(*result_head)->data * -1; 
	}
	return success;	
}
