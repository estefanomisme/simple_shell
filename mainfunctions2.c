#include "new_shell.h"

/**
 * free_vars - free memory used on buffers
 * @vars: Struct with buffer elements
 *
 * Return: Nothing
 */
void free_vars(vars_t *vars)
{
	int i = 0;

	while (vars->arguments[i] != NULL)
		i++;
	i--;
	for (; i >= 0; i--)
		free(vars->arguments[i]);
	free(vars->arguments);
	free(vars->buffer);
	vars->arguments = NULL;
	vars->buffer = NULL;
}

/**
 * file_exit - Exit program
 * @vars: Struct with buffer elements
 *
 * Return: Nothing
 */
void file_exit(vars_t *vars)
{
	free_vars(vars);
	exit(0);
}

/**
 * err_invarg - print command not found
 * @vars: Struct with buffer elements
 *
 * Return: Nothing
 */
void err_invarg(vars_t *vars)
{
	write(STDOUT_FILENO, vars->arguments[0], strlen(vars->arguments[0]));
	write(STDOUT_FILENO, ": command not found\n", 20);
}
