#include "monty.h"

/**
 * _mod - computed modulo of div of second by top element
 * @stack: double pointer to top of the stack
 * @line_number: value of node
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	if (tmp == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
	(*stack)->n %= tmp;
}

/**
 * _pchar - print char at top of stack
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
       	i = (*stack)->n;
	if (!(i >= 0 && i <= 127))
	{
		printf("L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(i);
	putchar('\n');
}

/**
 * _pstr - prints out string starting from top of stack
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (isascii(tmp->n) && tmp->n != 0)
			putchar(tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - all elements rotate left, top element becomes last
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *new_top;

	UNUSED(line_number);
	if (*stack == NULL || (*stack)->next ==NULL)
		return;
	new_top = (*stack)->next;
	new_top->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = new_top;
}

/**
 * _rotr - all elements rotate right, bottom element becomes forst
 * @stack: double pointer to top of stack
 * @line_number: what line in the monty bytecode file are we at
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
