#include "main.h"

char *add_strings(char *N1, char *N2, char *R, int r_index);
char *infinite_add(char *N1, char *N2, char *R, int size_r);

/**
 * add_strings - Adds the numbers stored in two strings.
 * @N1: The string containing the first number to be added.
 * @N2: The string containing the second number to be added.
 * @R: The buffer to store the result.
 * @r_index: The current index of the buffer.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */

char *add_strings(char *N1, char *N2, char *R, int r_index)
{
	int num, tens = 0;

	for (; *N1 && *N2; N1--, N2--, r_index--)
	{
		num = (*N1 - '0') + (*N2 - '0');
		num += tens;
		*(R + R_index) = (num % 10) + '0';
		tens = num / 10;
	}

	for (; *N1; N1--, r_index--)
	{
		num = (*N1 - '0') + tens;
		*(r + r_index) = (num % 10) + '0';
		tens = num / 10;
	}

	for (; *N2; N2--, r_index--)
	{
		num = (*N2 - '0') + tens;
		*(R + r_index) = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens && r_index >= 0)
	{
		*(R + r_index) = (tens % 10) + '0';
		return (R + r_index);
	}

	else if (tens && r_index < 0)
		return (0);

	return (R + r_index + 1);
}
/**
 * infinite_add - Adds two numbers.
 * @N1: The first number to be added.
 * @N2: The second number to be added.
 * @R: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */

char *infinite_add(char *N1, char *N2, char *R, int size_r)
{
	int index, N1_len = 0, N2_len = 0;

	for (index = 0; *(N1 + index); index++)
		N1_len++;

	for (index = 0; *(N2 + index); index++)
		N2_len++;

	if (size_r <= N1_len + 1 || size_r <= N2_len + 1)
		return (0);

	N1 += N1_len - 1;
	N2 += N2_len - 1;
	*(R + size_r) = '\0';

	return (add_strings(N1, N2, R, --size_r));
}
