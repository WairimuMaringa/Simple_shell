#include "headershell.h"
/**
 * main - create an infinite loop
 * @argc: number of args
 * @argv: string array of args
 * 
 * Return: 0 or multiple errors
 */
int main(__attribute__unused((unused)) int argc, char *argv[])
{
	int infinite_loop, num_chars;

	char *read_line;

	char **arguments;

	size_t x;

	signal(SIGINT, sig_transmission);
	for (infinite_loop = 1; infinite_loop <= 1; infinite_loop++)
	{
		read_line = NULL;
		x = 0;
		arguments = NULL;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "# ", 2);
		}
		if (getline(&read_line, &x, stdin))
		{
			if (isatty(STDIN_FILENO))
			{
				write(STOUT_FILENO, "\n", 1);
			}
			exit(EXIT_FAILURE);
		}
		num_chars = countchars(read_line);
		arguments = tokenize(read_line, num_chars);
		if (_strcmp(arguments[0], "exit") == 0
		&& (_strlen(arguments[0]) == _strlen("exit")))
		{
			if (exit_shell(arguments, readline) == -1)
			{
				error_message(argv, arguments, infinite_loop);
			}
		}
		else if (arguments != NULL && arguments[0] != NULL)
		{
			if (decoder(args) == -1)
			{
				error_message(argv, arguments, num_chars);
			}
		}
		free_space(1, read_line);
		free_space(2, arguments);
	}
	return (0);
}
