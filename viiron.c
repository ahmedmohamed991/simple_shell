#include "shell.h"

/**
*_myenv - prints the current environment
*@info: structure containing potential arguments.
*Return: always 0
*/
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
*_getenv - gets the value of an environ variable
*@info: structure containing potential arguments.
*@name: env var name
*
*Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pointer;

	while (node)
	{
		pointer = starts_with(node->str, name);

		if (pointer && *pointer)
			return (pointer);
		node = node->next;
	}
	return (NULL);
}

/**
*_mysetenv - initialize aa new environment variable
*@info: structure containing potential arguments
*Return: always 0
*/
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
return (1);
}

/**
*_myunsetenv - remove an environment variable
*@info: structer containing potential arguments.
*Return: alwayes 0
*/
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
	return (0);
}

/**
*populate_env_list - populates env linked list
*@info: structure containing potential arguments.
*Return: always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t x;

for (x = 0; environ[x]; x++)
add_node_end(&node, environ[x], 0);
info->env = node;
return (0);
}
