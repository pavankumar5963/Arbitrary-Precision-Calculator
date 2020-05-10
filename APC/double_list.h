#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_DIGIT 9
#define TEN_POWER_NINE 1000000000
#define TEN_POWER_EIGHT 100000000


typedef int data_t;
typedef unsigned int uint;

/* Structure declaration */
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

/* Return type of functions */
typedef enum 
{
	success,
	failure,
	less,
	more,
	equal
} Status;

/* 1. Prototype for linked list */
Status insert_last(Dlist **head, data_t data, Dlist **tail);

/* 2. Prototype for printing list data */
Status print_list(Dlist *head);

/* 3. Prototype for add element */
Status insert_first(Dlist **head, data_t data, Dlist **tail);

/* 4. Prototype for delete first*/
Status delete_first(Dlist **head, Dlist **tail);

/* 5. Prototype to delete last */
Status delete_last(Dlist **head, Dlist **tail);

/* 7. Prototype to delete list */
Status delete_list(Dlist **head, Dlist **tail);

/* 8. Prototype to calculate nodes */
uint total_node(Dlist *head);

/* */
Status add_list(Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail);

/*                */
int carry_sum(int op1_data, int op2_data, int carry, Dlist **result_head, Dlist **result_tail);

/* */
Status subs_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail);

/* */
int borrow_list(int op1, int op2, int borrow_in, Dlist *next, Dlist **result_head, Dlist **result_tail);

/* */
Status multi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail);

/* */
Status compare (Dlist *op1_head, Dlist *op2_head);

/* */
int quo_rem(Dlist **rem_head, Dlist **rem_tail, Dlist *den_head, Dlist *den_tail, Dlist **quo_head, Dlist **quo_tail);

/* */
Status div_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail,Dlist *op2_tail, Dlist **int_result_head, Dlist **int_result_tail, Dlist **frac_result_head, Dlist **frac_result_tail);


#endif
