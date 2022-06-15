#include "monty.h"

/**
 * delegate_op - based on tokens from a single line,
 * it decides what functions to call
 * @stack: double pointer to head of the stack
 * @line_number: line in bytecode file being processed, zero indexed
 * Return:  nothing
 */
void delegate_op(stack_t **stack, char *op, unsigned int line_number)
{
	int i;
	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", instruction_pint},
		{"pop", instruction_pop},
		{"swap", instruction_swap},
		{"add", instruction_add},
		{"nop", instruction_nop},
		{"sub", instruction_sub},
		{"div", instruction_div},
		{"mul", instruction_mul},
		{"mod", instruction_mod},
		{"pchar", instruction_pchar},
		{"pstr", instruction_pstr},
		{"rotl", instruction_rotl},
		{"rotr", instruction_rotr},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		dprintf(2, "L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
