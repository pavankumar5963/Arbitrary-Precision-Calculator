#include "double_list.h"

int carry_sum(int op1_data, int op2_data, int carry, Dlist **result_head, Dlist **result_tail)
{
	int carry_out = 0, sum;
	int temp = 1000000000;

	sum  = op1_data + op2_data + carry;
	carry_out = sum / temp;
	if (carry_out)
	{
		sum = sum - (carry_out * temp);
	}
	insert_first(result_head, sum, result_tail);
	//printf("carrrry out %d\n", carry_out);
	return carry_out;
}
