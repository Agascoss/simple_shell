#include "shell.h"

/**
 * long_to_string - Converting Numbers String.
 *
 * @number: NUM must be converted in a string.
 *
 * @string: Buffer And save number as a String.
 *
 * @base: Base to converts a Number.
 *
 * Return: None.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: Points to String Origin.
 *
 * Return: Integer for Strings or Zero.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	/*1- Analyse Signs*/
	/*2 - Extracts de Nums*/
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - Counting Coincidence char in A String.
 *
 * @string: Points to Origin of String.
 *
 * @character: Counts String with Character.
 *
 * Return: Integer of Str or Zero.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}

