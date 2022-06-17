#include "palindrome.h"
#include <math.h>
#include <stdio.h>

/**
 * is_palindrome - function that checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: number to be checked.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	int count = 0, firstN, lastN, result;
	unsigned long temp = n;

	if (n / 10 == 0)
		return (1);

	while (temp >= 10)
	{
		temp /= 10;
		count += 1;
	}
	firstN = temp;
	lastN = n % 10;
	if (firstN != lastN)
		return (0);
	n = n - (firstN * (pow(10, count)));
	n = n / 10;
	result = is_palindrome(n);
	return (result);
}
