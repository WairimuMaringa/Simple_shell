/**
 * exec - forks a child process and executes a new program in it
 * @args: double pointer to strings containing arguments
 *
 * Return: An int representing success or failure
 */
int exec(char **args)
{
	pid_t child_pid;
	
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
