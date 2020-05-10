#include "double_list.h"


int borrow_list(int op1, int op2, int borrow_in, Dlist *next, Dlist **result_head, Dlist **result_tail)
{
	int borrow_out = 0, diff , temp = 100000000;
//	printf("diff %d op1 %d op2 %d borrow_out %d borrow_in %d\n", diff, op1, op2, borrow_out, borrow_in);	
	if (next)
	{
		if (op1 < op2)
		{
			borrow_out = 1;
			op1 = op1 + (borrow_out * 10 * temp);
		}
	}
	diff = op1 - op2 - borrow_in;
	insert_first(result_head, diff, result_tail);
	
	return borrow_out;
}
