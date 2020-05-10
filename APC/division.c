#include "double_list.h"

/* Function defination */

/* op1 is numerator and op2 is denominator*/
Status div_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail,Dlist *op2_tail, Dlist **int_result_head, Dlist **int_result_tail, Dlist **frac_result_head, Dlist **frac_result_tail)
{
	int values = compare (op1_head, op2_head);
	insert_first(frac_result_head, 0, frac_result_tail);
	if (values == equal)
	{
		insert_first(int_result_head, 1, int_result_tail);
		insert_first(frac_result_head, 0, frac_result_tail);
		return success;
	}
	else if (values == less)
	{
		insert_first(int_result_head, 0, int_result_tail);
	}
	/* Integer part */
	else
	{	
		insert_first(int_result_head, 0, int_result_tail);
		//printf("Hello\n");
		Dlist *rem_head = NULL, *rem_tail = NULL;
		
		/* Free rem and quo double link list*/
//		insert_first(&rem_head, 0, &rem_tail);
		//int quo = 0;

		// To copy numerator node to reminder as many nodes as denominator
		int count = total_node(op2_head);
		for (int i = 0; i < count; i++)
		{
			insert_last(&rem_head, op1_head->data, &rem_tail);
			op1_head = op1_head->next;
		}
		count = 0;
		do
		{
			printf("rem:  ");
			print_list(rem_head);
			printf("quo:  ");
			print_list(*int_result_head);
			printf("denominator:  ");
			print_list(op2_head);
			printf("numerator:  ");
			print_list(op1_head);
			values = compare(rem_head, op2_head);		// operator one temp (divident) and second operator is divisor
			printf("value is %d\n", values);
			if (values == less)
			{
				if (rem_head->data == 0)
				{
					rem_head->data = op1_head->data;
				}
				else
				{
					insert_last(&rem_head, op1_head->data, &rem_tail);
				}
					Dlist *copy_quo_head = NULL,  *copy_quo_tail = NULL;
					Dlist *ten_power_nine_head = NULL, *ten_power_nine_tail = NULL;
					Dlist *temp = *int_result_head;
					while(temp)
					{
						insert_last(&copy_quo_head, temp->data, &copy_quo_tail);
						temp = temp->next;
					}
					if (count)
					{
						insert_last(&ten_power_nine_head, TEN_POWER_EIGHT, &ten_power_nine_tail);
						delete_list(int_result_head, int_result_tail);
					}
					else
					{
						insert_last(&ten_power_nine_head, TEN_POWER_NINE, &ten_power_nine_tail);
						delete_list(int_result_head, int_result_tail);
					}

					multi_list(copy_quo_head, ten_power_nine_head, copy_quo_tail, ten_power_nine_tail, int_result_head, int_result_tail);
					delete_list(&copy_quo_head, &copy_quo_tail);
					delete_list(&ten_power_nine_head, &ten_power_nine_tail);
					printf("rem loop:  ");
					print_list(rem_head);
					count++;	
				op1_head = op1_head->next;
			}
			else if (values == equal)
			{
				Dlist *copy_quo_head = NULL,  *copy_quo_tail = NULL;
				Dlist *ten_power_one_head = NULL, *ten_power_one_tail = NULL;
				Dlist *temp = *int_result_head;
				/* Copy */
				while(temp)
				{
					insert_last(&copy_quo_head, temp->data, &copy_quo_tail);
					temp = temp->next;
				}
				insert_last(&ten_power_one_head, 10, &ten_power_one_tail);
				delete_list(int_result_head, int_result_tail);

				multi_list(copy_quo_head, ten_power_one_head, copy_quo_tail, ten_power_one_tail, int_result_head, int_result_tail);
				delete_list(&copy_quo_head, &copy_quo_tail);
				temp = *int_result_head;
				while(temp)
				{
					insert_last(&copy_quo_head, temp->data, &copy_quo_tail);
					temp = temp->next;
				}
				ten_power_one_head->data = 1;
//				printf("copy:  ");
//				print_list(copy_quo_head);
		//		printf("ten power one:  ");
		//		print_list(ten_power_one_head);
				delete_list(int_result_head, int_result_tail);
				add_list(copy_quo_tail, ten_power_one_tail, int_result_head, int_result_tail);
				delete_list(&copy_quo_head, &copy_quo_tail);
				delete_list(&ten_power_one_head, &ten_power_one_tail);
				delete_list(&rem_head, &rem_tail);
				insert_last(&rem_head, 0, &rem_tail);
				count = 0;
			}
			else
			{
				quo_rem(&rem_head, &rem_tail, op2_head, op2_tail, int_result_head, int_result_tail);	
				printf("Out of quo_rem\n");
				if (op1_head)
				op1_head = op1_head->next;
				count = 0;
			}
		//	if (quo / TEN_POWER_EIGHT)
		//	{
		//		insert_last(int_result_head, quo, int_result_tail);
		//		quo = 0;
		//	}
			if (op1_head == NULL)
			{
				print_list(rem_head);
				values = compare(rem_head, op2_head);		// To check remainder is less than denominator when numerator reaches to null

				printf("value NULL is %d\n", values);
			}
		} while (op1_head || (values > less));
	}

	/* Fractional part */

	/* 
	if ()
	{
	
	}*/
	return success;	
}

