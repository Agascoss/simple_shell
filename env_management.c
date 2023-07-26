#include "shell.h"

/**
 * env_get_key - Gets the value of the environment variable.
 *
 * @key: The environment variable of importance.
 *
 * @data: Structure of the programs data.
 *
 * Return: Pointer to the value of the variable or NULL if it doesn't exist.
 */
char *env_get_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	
	if (key == NULL || data->env == NULL)
		return (NULL);


	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	
	return (NULL);
}

/**
 * env_set_key - Overwrite the value of environment variable.
 *
 * @key: Name of the variable to set.
 *
 * @value: New value.
 *
 * @data: Structure of the program data.
 *
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);


	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
	{
			is_new_key = 0;
		
			free(data->env[i]);
			break;
		}
	}
	
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (is_new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * env_remove_key - Remove a key from the environment variable.
 *
 * @key: The key to be removed.
 *
 * @data: The struct of the programs data.
 *
 * Return: returns 1 if the key was removed, 0 if the key does not exist.
 */
int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	
	if (key == NULL || data->env == NULL)
		return (0);

	
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			free(data->env[i]);

			
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
		}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * print_environ - Prints the current environment variable.
 *
 * @data: Structure for the programs data.
 *
 * Return: returns nothing.
 */
void print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
