/**
 * search_path - searches for a path variable in the PATH
 * @string: name to look for
 *
 * Return: String containing the whole path variable
 */
char *search_path(char *string)
{
	int count;

	for (count = 0; environ[count] != NULL; count++)
	{
		if (_strcmp(environ[count], string) == 0)
		{
			break;
		}
		else if (environ[x + 1] == NULL)
		{
			perror("find path");
		}
	}
	return (environ[x]);
}
