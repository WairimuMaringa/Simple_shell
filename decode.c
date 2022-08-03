#include "headershell.h"


/**
 * decoder - checks to see which function an argument should be sent to
 * @args: string of arguments
 *
 * Return: 0
 */
int decoder(char **args)
{
	struct stat st;

	if (find_builtins(args) == 0)
	{
		return (0);
	}
	find(args);
	if (stat(args[0], &st) == 0 && S_ISREG(&st.st_mode) == 0)
	{
		return (-1);
	}
	if (exec(args) == -1)
	{
		return (-1);
	}
	return (0);
}
/**
 * free_space - frees malloced space
 * @x: signifies whether to free a single or double pointer
 *
 * Return: Void
 */
void free_space(int x, ...)
{
	char **double_pointer;

	char *single_pointer;

	va_list list;

	int count;

	va_start(list, x);
	if (n == 1)
	{
		single_pointer = va_arg(list, char *);
		if (single_pointer == NULL)
		{
			return;
		}
		free(single_pointer);
	}
	if (n == 2)
	{
		double_pointer = va_arg(list, char **);
		if (double_pointer == NULL)
		{
			return;
		}
		for (count = 0; double_pointer[count] != NULL; count++)
		{
			free(double_pointer[count]);
		}
		free(double_pointer);
	}
	va_end(list);
}
/**
 * error_message - prints error messages
 * @argv: string array of string pointers
 * @args: arguments collected by getline
 * @x: numner of times the infinite loop ran
 */
void error_message(char **argv, char **args, int x)
{
	char *delim = ": ";

	char *error = "not found";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, delim, _strlen(delim));
	error_number(x);
	write(STDERR_FILENO, delim, _strlen(delim));
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, delim, _strlen(delim));
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * error_number - Finds the error number
 * @x: number of times the infinite loop has run
 *
 * Return: void
 */
void error_number(int x)
{
	int num;

	unsigned int j;

	char c;

	j = x;
	num = 1;
	while ((j / num) > 9)
	{
		num *= 10;
	}
	while (num >= 1)
	{
		c = ((j / num) % 10) + '0';
		write(STD_ERR, &c, 1);
		num /= 10;
	}
}
