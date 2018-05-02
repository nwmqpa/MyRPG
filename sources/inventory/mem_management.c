/*
** EPITECH PROJECT, 2017
** sources/inventory/mem_management.c
** File description:
** Memory management of inventory.
*/

#include <stdlib.h>
#include "objects.h"
#include "utils.h"

struct inventory *inv_create(int nb_slots)
{
	struct inventory *inv = 0x0;

	for (int i = 2; i < nb_slots; i++) {
		if (!(nb_slots % i)) {
			inv = my_calloc(sizeof(struct inventory));
			inv->objects = my_calloc(sizeof(struct object) * nb_slots);
		}
	}
	return (inv);
}

void inv_free(struct inventory **inv)
{
	free((*inv)->objects);
	free(*inv);
}