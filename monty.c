#include "monty.h"

glob_t glob;

/**
 * stack_init - initialize the stack
 * @head: top of the stack
 */
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}

/**
 * free_all - free all malloc'ed memory
 * This is available "atexit", starting at getline loop
 */
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(glob.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}

/**
 * main - Entry point
 * @argc: number of command line arguments
 * @argv: array of strings containing the command line arguments
 *
 * Return: EXIT_SUSSESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	process_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}
