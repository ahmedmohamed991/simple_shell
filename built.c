#include "shell.h"
/**
 * _myexit - exits the shell
 * @info: structure containing potential arguments
 * used to maintain constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int ec;

	if (info->argv[1])
	{
		ec = _erratoi(info->argv[1]);
		if (ec == -1)
		{
			info->status = 2;
			print_error(info, "lllegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the current directory of the process
 * @info: structure containing potential arguments,
 * used to maintain constant function prototype
 * Return: always 0
 */
int _mycd(info_t *info)
{
	char *s, *dr, buffer[1024];
	int chr;

	s = getcwd(buffer, 1024);
	if (!s)
		_eputs("TODO: >>getcwd gccfailure emsg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chr = chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chr = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chr = chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chr = chdir(info->argv[1]);
	if (chr == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: structure containing potential arguments.
 * used to maintain constant function prototype
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **array;

	array = info->argv;
	_puts("help call works. function not yet implemented \n");
	if (0)
		_puts(*array);
	return (0);
}
/**
* populate_env_list - populates env linked list
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
