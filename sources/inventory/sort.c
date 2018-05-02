/*
** EPITECH PROJECT, 2017
** sources/inventory/sort.c
** File description:
** Sorting inventory
*/

#include "objects.h"
#include "utils.h"

int inv_sort(struct inventory **inv)
{
	struct inventory *inv_new = my_calloc(sizeof(struct inventory));
	union to_data data;
	int size = (*inv)->size;

	inv_new->objects = my_calloc(sizeof(struct object) * size);
	for (int i = 0; i < size; i++) {
		data.object = (*inv)->objects[i];
		if (data.data != 0) {
			inv_insert(inv_new, data.object);
		}
	}
	inv_free(inv);
	*inv = inv_new;
	return (1);
}
