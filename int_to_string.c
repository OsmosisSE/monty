#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - Converts an integer to its string representation.
 * @num: The number to convert.
 *
 * Return: A dynamically allocated string containning the number. NULL if fails
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_1 < 0)
		length++;

	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Gets the absolute value of an integer.
 * @i: The integer to get the absolute value of.
 *
 * Return: Unsigned integer absolute value of i.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Gets length of buffer needed for an unsigned int.
 * @num: The number to get length needed for.
 * @base: The base of number representation used by byffer.
 *
 * Return: Integer containing length of buffer needed (doesn't contain null).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills buffer with correct numbers up to base 36.
 * @num: The number to convert to string given base.
 * @base: The base of number used in conversion, only works up to base 36.
 * @buff: The buffer to fill with result of conversion.
 * @buff_size: the size of buffer in bytes.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
