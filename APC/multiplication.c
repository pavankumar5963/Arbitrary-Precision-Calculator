#include "double_list.h"

Status multi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail)
{
	int count = 0;
	Dlist *temp = NULL;
	Dlist *temp_op1 = op1_tail;
	int value = compare (op1_head, op2_head);
	if(value == less)
	{
		op1_tail = op2_tail;
		op2_tail = temp_op1;
		temp_op1 = op1_tail;
	}
	temp = *result_tail;
	while(op2_tail)
	{
		int carry_out = 0, carry_in = 0;
		int data;
		Dlist *temp_result = temp;					// To propagate result_tail by one node every time
		while (op1_tail)
		{
			int sum = 0;
			/* Long int to store multiplication of two integers */
			long unsigned int prod = 0;
		
			prod = (long unsigned int) op1_tail->data * op2_tail->data;	// Type cast op1 so does op2 to long int
			prod = prod + carry_in;
			
			if (temp_result)
			{
				data = temp_result->data;			// Get the data from result node
//				printf("data prev: %d\n", data);
				carry_out = (data + prod) / TEN_POWER_NINE;
				data = (data + prod) % TEN_POWER_NINE;
				temp_result->data = data;			// Modify the data in result node
				temp_result = temp_result->prev;	// Traverse to previous result node
//			printf("pro : %ld data : %d carry_out %d\n", prod, data, carry_out);
			}
			else
			{
				sum = prod % TEN_POWER_NINE;
				carry_out = prod / TEN_POWER_NINE;
				data = sum;
				insert_first(result_head, data, result_tail);	
//			printf("pro : %ld sum : %d carry_out %d\n", prod, sum, carry_out);
			}
			op1_tail = op1_tail->prev;
			carry_in = carry_out;
		}
		if (carry_out)
		{
			insert_first(result_head, carry_out, result_tail);		
		}
		op2_tail = op2_tail->prev;					// Traverse op2_tail to op2_head
		if (count)
		{
			temp = temp->prev;
		}
		else
		{
			temp = *result_tail;
			temp = temp->prev;
		}
//		printf("%d :", count);
//		print_list(*result_head);
		count++;							
		op1_tail = temp_op1;						// Start again from from op1_tail
	}	
}
