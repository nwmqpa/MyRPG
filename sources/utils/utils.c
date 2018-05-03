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
		return (ret);
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

float get_dtime(float time)
{
	static float d_time = 0.016;

	if (time != -1)
		d_time = time;
	return (d_time);
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
