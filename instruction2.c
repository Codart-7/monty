#include "monty.h"

/**
 * _add - adds top 2 nodes of the stack
 * @stack: double pointer to top of the stack
 * @line_number: value of node
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * _nop - doesn't do anything
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * _sub - substracts top node from second top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n -= tmp;
}

/**
 * _div - divides second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next ==NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	if (tmp == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
	(*stack)->n /= tmp;
}

/**
 * _mul - multiplies second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next ==NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n *= tmp;
}
