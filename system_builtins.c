#include "headershell.h"

/**
 * sig_transmission - it confirms if the signal is SIGINT
 * @signal_no: the number of the signal
 *
 * Return: Returns void
 */
void sig_transmission(int signal_no)
{
	if (signal_no == SIGINT)
	{
		write(STDOUT_FILENO, "\n# ", 3);
	}
}

/**
 * print_environmt - prints the environment
 * Return: 0
 */

int print_environmt(void)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
 * exit_shell - specifies how we exit the shell
 * @args: string array of args
 * @string: a space set aside
 *
 * Return: 0 or it exits before
 */
int exit_shell(char **args, char *string)
{
	int digit;

	digit = 0;
	if (args[1] != NULL)
	{
		digit = _atoi(args[1]);
	}
	if (digit == -1)
	{
		return (-1);
	}
	else
	{
		free_space(1, string);
		free_space(2, args);
		exit(digit);
	}
}
