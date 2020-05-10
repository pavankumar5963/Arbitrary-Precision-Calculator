#include "double_list.h"


int main(int argc, char **argv)
{
	char *operand1 = argv[1];
	char *operator = argv[2];
	char *operand2 = argv[3];
	printf("--------------strings------------\n");
	printf("%s\n%s\n%s\n", operand1, operator, operand2);
	int oprd1_len = strlen(operand1);
	int oprd2_len = strlen(operand2);
	int oprt_len = strlen(operator);

	printf("--------------string length---------\n");
	printf("op1_len : %d\nop2_len : %d\nopr : %d\n", oprd1_len, oprd2_len, oprt_len);
	int extra1 = oprd1_len % MAX_DIGIT;
	int extra2 = oprd2_len % MAX_DIGIT;
	int node1 = (oprd1_len / MAX_DIGIT) + !!extra1;
	int node2 = (oprd2_len / MAX_DIGIT) + !!extra2;

	printf("-------------nodes-----------------\n");
	printf("node1 : %d\nnode2 : %d\n", node1, node2);
	char fnode[10];
	
	printf("--------------Double link list create----------------------\n");	
	Dlist *op1_head = NULL, *op1_tail = NULL, *op2_head = NULL, *op2_tail = NULL;
	/* Copy extra digit of operand 1 */
	uint num;
	/* Create double link list */
	if (extra1)
	{
		strncpy(fnode, operand1, extra1);
		fnode[extra1] = '\0';
//		printf("fnode %s\n", fnode);
		num = atoi(fnode);
//		printf("%d\n", num);
		insert_last(&op1_head, num, &op1_tail);
		operand1 += extra1;
	}

	/* Copy extra digit of operand 2 */
	if(extra2)
	{
		strncpy(fnode, operand2, extra2);
		fnode[extra2] = '\0';
//		printf("fnode %s\n", fnode);
		num = atoi(fnode);
//		printf("%d\n", num);
		insert_last(&op2_head, num, &op2_tail);
		operand2 += extra2;
	}
	
	while (*operand1)
	{
		strncpy(fnode, operand1, MAX_DIGIT);
		fnode[MAX_DIGIT] = '\0';
		num = atoi(fnode);
//		printf("%d\n", num);
		insert_last(&op1_head, num, &op1_tail);
		operand1 += MAX_DIGIT;
	}
	while (*operand2)
	{
		strncpy(fnode, operand2, MAX_DIGIT);
		fnode[MAX_DIGIT] = '\0';
		num = atoi(fnode);
//		printf("%d\n", num);
		insert_last(&op2_head, num, &op2_tail);
		operand2 += MAX_DIGIT;
	}
	printf("First Operand list: ");
	print_list(op1_head);
	printf("Second Operand list: ");
	print_list(op2_head);

	/* Arthematic operstions */
	Dlist *result_head = NULL, *result_tail = NULL;
	switch (*operator)
	{
		case '+':
				{
					add_list(op1_tail, op2_tail, &result_head, &result_tail);
					printf("-------------------Result for addition------------------------\nSum is : ");
					print_list(result_head);
				}
				break;
		case '-':
				{
					subs_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail);
					printf("-------------------Result of substraction--------------------\nSubstration is : ");
					print_list(result_head);
				}
				break;
		case '*':
				{
					multi_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail);
					printf("-------------------Result of multiplication-------------------\nMultiplication is: ");	
					print_list(result_head);
				}
				break;
		case '/':
				{
					printf("-------------------Division result check-------------------\n");	
					Dlist *int_result_head = NULL, *int_result_tail = NULL;
					Dlist *frac_result_head = NULL, *frac_result_tail = NULL;
					div_list(op1_head, op2_head, op1_tail, op2_tail, &int_result_head, &int_result_tail, &frac_result_head, &frac_result_tail);
					printf("\n-------------------Result of division-------------------\n");	
					printf("Integer part is : ");
					print_list(int_result_head);
					printf("Decimal part is : ");
					print_list(frac_result_head);
				}
				break;
		default:
				printf("Invalid operator\n");
	}
	delete_list(&op1_head, &op1_tail);
	delete_list(&op2_head, &op2_tail);
	delete_list(&result_head, &result_tail);
	return 0;
}
