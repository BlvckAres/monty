#include "monty.h"

/**
 * push - pushes an element to the stack/queue
 * @stack: a pointer to the head node
 * @line_num: a pointer to line
 * @nline: the line postion/number
 */
void push(stack_t **stack, char *line_num, unsigned int nline)
{
	stack_t *node, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", nline);
		free(line_num);
		free(*stack);
		*stack = NULL;
		exit(EXIT_FAILURE);
	};

	node = add_node(stack, atoi(new));
	free(line_num);
	if (node == NULL)
	{
		puts("Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints the data of all nodes in stack/queue
 * @stack: a pointer to the head node pointer of stack/queue
 * @nline: the line number
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

