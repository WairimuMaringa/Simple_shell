#include "headershell.h"

/**
 * remove_equal_sign - removes chars including the equal sign
 * @string: a string parameter
 *
 * Return: void
 */
void remove_equal_sign(char **string)
{
	int count;

	count = 0;
	while (string[0][count] != '=')
	{
		string[0][count] = ':';
		count++;
	}
	string[0][count] = ':';
}
/**
 * countchars - counts number of chars in a string from getline
 * @string: string parameter from getline
 *
 * Return: The length of the string
 */
int countchars(char *string)
{
	int x, y, num, flag;

	char *delim = " :";

	x = 0;
	flag = 0;
	num = 1;
	if (string == NULL)
	{
		return (num);
	}
	while (string[x] != '\0')
	{
		for (y = 0; delim[y] != '\0'; y++)
		{
			if (string[x] == delim[y] && flag == 0)
			{
				num++;
				flag = 1;
				break;
			}
		}
		if (delim[y] == '\0')
		{
			flag = 0;
		}
		x++;
	}
	return (num + 1);
}
/**
 * tokenize - parses args and places them in a buffer
 * @string: a pointer to a string
 * @num: number of args
 *
 * Return: a pointer to a string array
 */
char **tokenize(char *string, int num)
{
	int x;

	char *token;

	char **token_char = malloc(sizeof(char *) * num);

	char *delim = " :'\n''\t'";

	x = 0;
	if (string == NULL || token_char == NULL)
	{
		return (NULL);
	}
	token = strtok(string, delim);
	while (token != NULL)
	{
		token_char[x] = _strdup(token);
		if (token_char[x] == NULL)
		{
			free_space(2, token_char);
			return (NULL);
		}
		token = strtok(NULL, delim);
		x++;
	}
	token_char[x] = token;
	return (token_char);
}
