#include "monty.h"

/**
 * pint - prints the value at the head of stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 */

void pint(stack_t **stack, unsigned int num_line)
{

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
        free_stack(*stack);
		exit(EXIT_FAILURE);
	}

    printf("%d\n", (*stack)->n);
}

/**
 * free_stack -free list.
 *Description: Function that frees a dlist_t list
 * @head: head of the stack. (head)
 * Return: void
 **/
void free_stack(stack_t *head)
{
	stack_t *node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
	free(head);
}

/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int num_line)
{
	char c;
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	while (node)
	{
		if (node->prev == NULL)
			break;
		node = node->prev;
	}

	c = node->n;
	if (_isalpha(node->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - prints a str from ascii starting from the top
 * @stack: pointer to the head node pointer of stack
 * @num_line: the line number
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int num_line)
{
	int idx = 0;
	char res[] = "";
	char c;
	stack_t *node;

	node = *stack;
	(void)num_line;
	/* starts at the top */
	while (node)
	{
		if (node->n == 0)
			break;
		if (_isalpha(node->n) == 0)
			break;
		c = node->n;
		printf("%c", c);
		res[idx] += c;
		node = node->next;
		idx++;
	}
	printf("\n");
}
