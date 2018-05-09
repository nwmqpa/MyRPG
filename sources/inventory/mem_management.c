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
			inv->size = nb_slots;
			return (inv);
		}
	}
	return (inv);
}

// TODO: Create random object using level
struct object obj_create(UNUSED unsigned int level)
{
	union to_data returned_object;

	returned_object.data = 0;
	returned_object.object.qty = rand() % 64;
	printf("\t%d\n", returned_object.object.qty);
	return (returned_object.object);
}

// TODO: Create random loots using level
struct inventory *create_random_loots(unsigned int level)
{
	unsigned int size = rand() % 9;
	struct inventory *inv = my_calloc(sizeof(struct inventory));

	printf("%d =>\n", size);
	inv->objects = my_calloc(sizeof(struct object) * 9);
	inv->size = 9;
	for (unsigned int i = 0; i < size; i++) {
		inv->objects[i] = obj_create(level);
	}
	return (inv);
}

void inv_free(struct inventory **inv)
{
	free((*inv)->objects);
	free(*inv);
}