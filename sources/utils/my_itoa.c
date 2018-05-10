/*
** EPITECH PROJECT, 2017
** my_itoa.c
** File description:
** Main file for the my_itoa function
*/

#include <stdlib.h>
#include "utils.h"
#include "str_utils.h"

static const unsigned long long MAX_POWER = 10000000000000000000U;

static unsigned long long get_max_power(unsigned long long nb)
{
	unsigned long long power = 1;

	while (power <= nb && power != MAX_POWER)
		power = power * 10;
	return (power == MAX_POWER ? power : power / 10);
}

char *my_itoa(int nb)
{
	int digit;
	char *to_return = NULL;
	unsigned long long power;

	power = get_max_power(nb);
	while (power > 0) {
		digit = nb / power;
		nb = nb - (digit * power);
		to_return = str_append(to_return, digit + 48);
		power = power / 10;
	}
	if (to_return == NULL)
		to_return = "0";
	while (to_return[1] && to_return[0] == '0')
		to_return++;
	return (to_return);
}
