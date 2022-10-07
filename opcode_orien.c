#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int num_line)
{
	stack_t *node;
	int hold_this, hold_this_again;
	(void)num_line;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, num_line);
	}

	hold_this = (*stack)->n;
	node = *stack;

	while (node)
	{
		if (node->next == NULL)
			break;
		node = node->next;
	}

	hold_this_again = node->n;
	(*stack)->n = hold_this_again;
	node->n = hold_this;
}

/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void rotlop(stack_t **stack, unsigned int num_line)
{
	stack_t *last, *temp;

	(void)num_line;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}

/**
 * rotrop - rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void rotrop(stack_t **stack, unsigned int num_line)
{
	stack_t *last, *temp;

	(void)num_line;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	last = temp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}

/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void qpush(stack_t **stack, unsigned int num_line)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", num_line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
