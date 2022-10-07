#include "monty.h"
 
/**
 * pop - removes the top element of stack
 * @stack: pointer to the head node pointer of stack
 * @line_num: the line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

    node = *stack
    if ((node) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

    if (node->next == NULL)
	{
		(*stack) = NULL;
		free(node);
	}
	else
	{
        node = node->next;
		node->prev = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to the head node pointer of stack
 * @line_num: the line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int node;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	node = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = node;
}

/**
 * _nop -main entry.(the function does void)
 * @head: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
