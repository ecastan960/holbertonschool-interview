#include "regex.h"

/**
 * strcmp - compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: 1 if they are "equal", 0 otherwise.
 */
int strcmp(char const *str1, char const *str2)
{

	if (*str2 == '*')
		return (starcheck(str1, str2 + 1));
	if (*str1 == '\0' || *str2 == '\0')
	{
		if (*str2 == '\0' && *str1 == '\0')
			return (1);
		return (0);
	}
	if (*str1 == *str2)
		return (strcmp(str1 + 1, str2 + 1));
	return (0);
}

/**
 * starcheck - branch horizontally if a '*' has been encountered
 * @s1: ptr to string
 * @star: string with '*'
 *
 * Return: 1 if the string matches, else 0
 */
int starcheck(char const *s1, char const *star)
{
	if (*s1 == '\0')
		return (strcmp(s1, star));
	return (strcmp(s1, star) || starcheck(s1 + 1, star));
}


/**
 * regex_match - checks if a pattern match a given string
 * @str: ptr to string to check
 * @check: string to compare with
 *
 * Return: 1 if match, otherwise 0
 */
int regex_match(char const *str, char const *check)
{
	return (strcmp(str, check));
}
