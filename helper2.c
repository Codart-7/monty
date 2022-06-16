#include "monty.h"

/**
 * delegate_op - based on tokens from single line, decide what function to call
 * @stack: double pointer to head of stack data structure
 * @op: operator, aka token[0] from getline
 * @line_number: line in byte-code file being processed, zero indexed
 * Return: int for mysterious purposes
 **/
void delegate_op(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
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
		printf("L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
