#include "shell.h"

/**
 * builtins_list -lookout for match then execute Associate builtinS.
 *
 * @data: Programs Data STRUCT.
 * Return: If there's match return executed function.
 *
 * Else return-1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
