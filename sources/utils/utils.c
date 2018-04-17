/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils function
*/

#include <stdlib.h>

void *my_malloc(size_t size)
{
	void *ret = malloc(size);

	if (ret == NULL)
		exit(84);
	return (ret);
}

void *my_calloc(size_t size)
{
	void *temp = malloc(size);
	unsigned int counter = 0;

	while (counter < size) {
		((char *)temp)[counter] = 0;
		counter++;
	}
	return (temp);
}

int my_nblen(int nb)
{
	int ret = 0;

	ret++;
	while (nb >= 10) {
		ret++;
		nb /= 10;
	}
	return (ret);
}
