#include "holberton.h"

/**
 * stringCheck - compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: 1 if equal, 0 otherwise.
 */
int stringCheck(char *str1, char *str2)
{
	if (*str2 == '*')
		return (starCheck(str1, str2 + 1));
	if (*str1 == '\0' || *str2 == '\0')
	{
		if (*str2 == '\0' && *str1 == '\0')
			return (1);
		return (0);
	}
	if (*str1 == *str2)
		return (stringCheck(str1 + 1, str2 + 1));
	return (0);
}

/**
 * starCheck - check if string has *
 * @s3: pointer to string
 * @s4: string with '*'
 *
 * Return: 1 if equal, else 0
 */
int starCheck(char *s3, char *s4)
{
	if (*s3 == '\0')
		return (stringCheck(s3, s4));
	return (stringCheck(s3, s4) || starCheck(s3 + 1, s4));
}


/**
 * wildcmp - compares a string with one which may have *
 * @s: pointer to string 1
 * @s2: pointer to string 2
 *
 * Return: 1 if equal, otherwise 0
 */
int wildcmp(char *s, char *s2)
{
	return (stringCheck(s, s2));
}
