#ifndef PALINDROME_H
#define PALINDROME_H

#include <math.h>

/**
 * power- power function
 * @base: base number.
 * @power: power.
 *
 * Return: power
 */

int po(int base,int power);

/**
 * is_palindrome - function that checks whether or not a
 * given unsigned integer is a palindrome.
 * @n: number to be checked.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n);

#endif /* PALINDROME_H */
