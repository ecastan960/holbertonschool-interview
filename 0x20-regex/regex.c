#include "regex.h"
#include <stdio.h>


/**
 * regex_check - function to check patterns
 * @str: string
 * @pattern: pattern
 * @str2: pointer
 * @p2: pointer
 * Return: 1 or 0
 */
int regex_check(char const *str, char const *pattern,
		     const char **str2, const char **p2)
{
	const char *p_start;
	int match = 0;

	if (!str || !pattern)
		return (0);
	while (*str)
	{
		while (*str && *str != *pattern)
			str++;
		p_start = pattern;
		while (*str == *pattern && *pattern != '.' &&
		       *pattern != '*' && *pattern != '\0' &&
		       *(pattern + 1) != '*')
		{
			str++;
			pattern++;
		}
		if (*pattern == '.' || *pattern == '*' ||
		    *pattern == '\0' || *(pattern + 1) == '*')
		{
			*p2 = pattern;
			*str2 = str;
			match = 1;
		}
		pattern = p_start;
	}

	return (match);
}

/**
 * regex_match - checks if pattern matches a given string
 * @str: string
 * @pattern: pattern
 * Return: 1 if match else 0
 */
int regex_match(char const *str, char const *pattern)
{
	char repeat;
	const char *str2 = NULL, *p2 = NULL;

	if (!str || !pattern)
		return (0);
	while (*pattern)
	{
		if (*(pattern + 1) == '*')
		{
			if (*pattern == '.')
			{
				pattern += 2;
				if (regex_check(str, pattern, &str2, &p2))
				{
					str = str2;
					pattern = p2;
				}
			}
			else
			{
				repeat = *pattern;
				pattern += 2;
				while (*str == repeat)
					str++;
			}
		}
		else if (*pattern == '.' || *pattern == *str)
		{
			pattern++;
			str++;
		}
		else
			break;
	}
	return (!(*str) && !(*pattern));
}
