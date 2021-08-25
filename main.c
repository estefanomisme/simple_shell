#define _GNU_SOURCE
#include "new_shell.h"
int main()
{
	vars_t vars = {NULL, NULL};
	size_t buffer_len = 0;
	char *delimiter =  " \n";
	char *buffercur;

	printf("$ ");
	while (getline(&(vars.buffer), &buffer_len, stdin) != -1)
	{
		buffercur = cure_buffer(vars.buffer);
		if (buffercur != NULL)
			vars.arguments = _strtok_all(buffercur, delimiter);
		free(buffercur);
		if (vars.arguments != NULL)
		{
			if (strcmp(vars.arguments[0], "exit") == 0)
				file_exit(&vars);
			if (match_sys(&vars) == 0)
				err_invarg(&vars);
			free_vars(&vars);
		}
		printf("$ ");
	}
	return (0);
}
