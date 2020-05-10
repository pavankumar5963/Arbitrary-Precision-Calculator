#include "double_list.h"

int power (int p);
int digits (int num);
void copy_data(Dlist **dest_head, Dlist **dest_tail, Dlist *src_head);
/*
Return : Remainder

   */

/* op1 is rememder and op2 is denominator */
int quo_rem(Dlist **rem_head, Dlist **rem_tail, Dlist *den_head, Dlist *den_tail, Dlist **quo_head, Dlist **quo_tail)
{
	//int value = compare (op1_head, op2_head);
	/*if (value == equal)
	{
		op1_head->data = 0;
		op1_head->next->data = 0;
		return 1;
	}*/
	int value = more;
	//printf("value quo_rem %d\n", value);
	int expo = 0;
	Dlist *multi_head = NULL, *multi_tail = NULL;
	Dlist *temp_head = NULL, *temp_tail = NULL;		// TO store 10and muitiply it with denominator
	insert_first(&temp_head, 10, &temp_tail); /* Multiply 10 to denomiantor */
	Dlist *temp_den_head = NULL, *temp_den_tail = NULL;
	printf("expo %d\n", expo);
	copy_data(&temp_den_head, &temp_den_tail, den_head);		// Destination list should be empty
	printf("expo %d\n", expo);
	while(value != less)					// 
	{
		multi_list(temp_den_head, temp_head, temp_den_tail, temp_tail, &multi_head, &multi_tail);
		print_list(multi_head);
		value = compare(*rem_head, multi_head);
		expo++;								// To count exponent
		delete_list(&temp_den_head, &temp_den_tail);
		copy_data(&temp_den_head, &temp_den_tail, multi_head);		// Destination list should be empty
		delete_list(&multi_head, &multi_tail);
	}
	
	int last = power(expo);
	int start = (last / 10);
	//printf("last - %d, start - %d",last, start);
	delete_list(&temp_den_head, &temp_den_tail);
	delete_list(&temp_head, &temp_tail);
	insert_first(&temp_head, start, &temp_tail);	// TO multiply from start to last incrementing by 1  
	
	while (start < last)
	{
		multi_list(den_head, temp_head, den_tail, temp_tail, &multi_head, &multi_tail);
		
		value = compare(multi_head, *rem_head);
		printf("last - %d, start - %d value - %d\n", last, start, value);
		if (value == more)
		{
			start--;
			break;
		}
		if (value == equal)
		{
			break;
		}
		start++;
		temp_head->data = start;
		delete_list(&multi_head, &multi_tail);
	}
	if (multi_head)
	{
		delete_list(&multi_head, &multi_tail);
		printf("value - %d\n", value);
		if (value == more)
		{
			/* To get quo */
			temp_head->data = start;			// 
			int digit_quo = digits(start);		//	To get number of digits of start
			int ten_power = power(digit_quo);
			Dlist *digit_head = NULL, *digit_tail = NULL; 
			Dlist *temp_quo_head = NULL, *temp_quo_tail = NULL;
			insert_first(&digit_head, ten_power, &digit_tail);	// TO multiply from start to last incrementing by 1  
			multi_list(*quo_head, digit_head, *quo_tail, digit_tail, &temp_quo_head, &temp_quo_tail);
			delete_list(&digit_head, &digit_tail);
			
			add_list(temp_quo_tail, temp_tail, &digit_head, &digit_tail);
			delete_list(quo_head, quo_tail);
			*quo_head = digit_head;
			*quo_tail = digit_tail;
			digit_head = NULL, digit_tail = NULL;
			delete_list(&temp_quo_head, &temp_quo_tail);

			/* To get remainder */
			multi_list(den_head, *quo_head, den_tail, *quo_tail, &temp_quo_head, &temp_quo_tail);

			subs_list(*rem_head, temp_quo_head, *rem_tail, temp_quo_tail, &digit_head, &digit_tail);
//			print_list(temp_quo_head);	
//			print_list(*rem_head);	
//			print_list(digit_head);	
			delete_list(rem_head, rem_tail);
			*rem_head = digit_head;
			*rem_tail = digit_tail;
		}
		if (value == equal)
		{
			temp_head->data = start;			// integer quo
			int digit_quo = digits(start);
			int ten_power = power(digit_quo);
			Dlist *digit_head = NULL, *digit_tail = NULL; 
			Dlist *temp_quo_head = NULL, *temp_quo_tail = NULL;
			insert_first(&digit_head, ten_power, &digit_tail);	// TO multiply from start to last incrementing by 1  
			multi_list(*quo_head, digit_head, *quo_tail, digit_tail, &temp_quo_head, &temp_quo_tail);
			delete_list(&digit_head, &digit_tail);
			
			add_list(temp_quo_tail, temp_tail, &digit_head, &digit_tail);
			delete_list(quo_head, quo_tail);
			*quo_head = digit_head;
			*quo_tail = digit_tail;
			digit_head = NULL, digit_tail = NULL;
			delete_list(&temp_quo_head, &temp_quo_tail);
			
			delete_list(rem_head, rem_tail);
			insert_first(rem_head, 0, rem_tail);	// To make remainder zero
		}
	}
	return 0;
}

int power (int p)
{

	int num = 1;
	for (int i = 0; i < p; i++)
	{
		num = 10 * num;
	}
	return num;
}

int digits (int num)
{
	int count = 0;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return count;
}

void copy_data(Dlist **dest_head, Dlist **dest_tail, Dlist *src_head)
{
	while (src_head)
	{
		insert_last(dest_head, src_head->data, dest_tail);	// To copy source data to destination
		src_head = src_head->next;
	}
}
