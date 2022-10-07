#ifdef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


/*extern variable, stack or queue*/

extern char *flag;

#define LINE_LENGTH 32

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void push(stack_t **stack, char *line_num, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int num_line);
void free_stack(stack_t *head);
void pchar(stack_t **stack, unsigned int num_line);
void pstr(stack_t **stack, unsigned int num_line);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void _nop(stack_t **head, unsigned int line_number);
void rotl(stack_t **stack, unsigned int num_line);
void rotlop(stack_t **stack, unsigned int num_line);
void rotrop(stack_t **stack, unsigned int num_line);
void qpush(stack_t **stack, unsigned int num_line);
void addst(stack_t **stack, unsigned int num_line);
void addqu(stack_t **stack, unsigned int num_line);
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int);
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int nline);
void _div(stack_t **stack, unsigned int nline);
void _multi(stack_t **stack, unsigned int nline);
void _modo(stack_t **stack, unsigned int nline);
bool comment_check(line_t line);
void push_check(line_t line, meta_t *meta, char *opcode);
void parseline(line_t *line, char *buf);
void parsefile(FILE *file);

int main(int ac, char **av);

#endif
