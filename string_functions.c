#include "headershell.h"

/**
 * _strdup - duplicates a string;
 * @s: string to be duplicated
 *
 * Return: The pointer to the copied string
 */
char *_strdup(char *s)
{
	int len, count;

	char *target;

	count = 0;
	for (len = 0; s[len] != '\0'; len++)
	{
		count++;
	}
	target = malloc(sizeof(char) * (count + 1));
	if (target == NULL)
	{
		return (NULL);
	}
	for (len = 0; len < count; len++)
	{
		target[len] = s[len];
	}
	target[len] = '\0';
	return (target);
}
/**
 * _strcmp - compares 2 strings
 * @string1: First string
 * @string2: Second string
 *
 * Return: Difference of ACSII values between the strings
 */
char _strcmp(char *string1, char *string2)
{
	int count;

	int x;

	x = 0;
	count = 0;
	if (string1 == NULL || string2 == NULL)
	{
		return (-1);
	}
	while (string1[x] != '\0' && string2[x] != '\0')
	{
		count = string1[x] - string2[x];
		if (count != 0)
		{
			break;
		}
		x++;
	}
	printf("%d\n", count);
	return (count);
}
/**
 * _strlen - Finds length of a string
 * @string: a pointer to a string
 *
 * Return: String length
 */
int _strlen(char *string)
{
	int len, count;

	count = 0;
	for (len = 0; string[len] != '\0'; len++)
	{
		count++;
	}
	return (count);
}
/**
 * _atoi - converts a string to an integer
 * @string: string to be converted
 *
 * Return: An integer
 */
int _atoi(char *string)
{
	int num;

	unsigned int x;

	x = 0;

	for (num = 0; string[num] != '\0'; num++)
	{
		if (string[num] < '0' || string[num] > '9')
		{
			return (-1);
		}
	}
	for (num = 0; string[num] != '\0'; num++)
	{
		x = x * 10 + (string[num] - '0');
	}
	return (x);
}
/**
 * _strcat - joining 2 strings
 * @string1: First string
 * @string2: second string
 *
 * Return: A new joined string
 */
char *_strcat(char *string1, char *string2)
{
	int count, x, y;

	char new_str;

	y = 0;
	count = _strlen(string1) + _strlen(string2) + 2;
	new_str = malloc(sizeof(char) * count);
	if (new_str == NULL)
	{
		return (NULL);
	}
	for (x = 0; string1 && string1[x] != '\0'; x++)
	{
		new_str[y] = string1[x];
		y++;
	}
	if (j != 0)
	{
		new_str[y] = '/';
		y++;
	}
	for (x = 0; string2 && string2[x] != '\0'; x++)
	{
		new_str[y] = string2[x];
		y++;
	}
	new_str[y] = '\0';
	free_space(string2);
	return (new_str);
}
