/**
 * find - searches for commands
 * @args: strings to search for
 *
 * Return: -1 or 0
 */
int find(char **args)
{
	int num;

	char *s;

	char **instruction = NULL;
	
	s = _strdup(search_path("PATH"));
	if (s == NULL)
	{
		return (-1);
	}
	num = countchars(s);
	if (num == -1)
	{
		free_space(1, s);
		return (-1);
	}
	remove_equal_sign(&s);
	instruction = tokenize(s, num);
	if (instruction  == NULL)
	{
		free_space(1, s);
		return (-1);
	}
	if (find_dirs(instruction, args) == -1)
	{
		free_space(1, s);
		return (-1);
	}
	free_space(1, s);
	return (0);
}
/**
 * find_builtins - finds a builtin and their function
 * @args: command to search for
 *
 * Return: 0 on success
 */
int find_builtins(char **args)
{
	builtin builtins[] = {
		{"env", print_environment},
		{NULL, NULL}
	};

	int x, y;

	y = 0;
	for (x = 0; builtins[x].name != NULL; x++)
	{
		if (_strcmp(builtins[x].name, args[0]) == 0 &&
		_strlen(builtins[x].name) == _strlen(args[0]))
		{
			y = builtins[x].func();
		}
	}
	if (builtins[x].name == NULL)
	{
		return (-1);
	}
	return (y);
}
/**
 * find_dirs - searches for a command in directories
 * @instruction: pointers to directories
 * @args: list of commands
 *
 * Return: -1 or 0
 */
int find_dirs(char **instruction, char **args)
{
	char *working_d;

	int count;

	struct stat st;

	working_d = getcwd(NULL, 0);
	for (count = 0; instruction[count] != NULL; count++)
	{
		if (args[0][0] = '/')
		{
			break;
		}
		if (_strcmp(args[0], "./") == 0)
		{
			break;
		}
		chdir(instruction[count]);
		if (stat(args[0], &st) == 0)
		{
			args[0] = _strcat(instruction[count], args[0]);
			if (args[0] == NULL)
			{
				free_space(1, working_d);
				free_space(2, instruction);
				return (-1);
			}
			break;
		}
	}
	chdir(working_d);
	free_space(1, working_d);
	if (instruction[count] == NULL)
	{
		free_space(2, instruction);
		return (-1);
	}
	free_space(2, instruction);
	return (0);
}
