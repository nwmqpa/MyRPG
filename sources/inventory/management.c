/*
** EPITECH PROJECT, 2017
** sources/inventory/management.c
** File description:
** Inventory management.
*/

#include "cybend2200.h"

int inv_is_full(struct inventory *inv)
{
	unsigned int size = inv->size;
	union to_data to_data;

	for (unsigned int i = 0; i < size; i++) {
		to_data.object = inv->objects[i];
		if (!to_data.data)
			return (0);
	}
	return (1);
}

unsigned int inv_nb_of(struct inventory *inv, struct object object)
{
	unsigned int size = inv->size;
	int nb = 0;
	union to_data searched;
	union to_data tested;

	searched.object = object;
	for (unsigned int i = 0; i < size; i++) {
		tested.object = inv->objects[i];
		if (INSTANCEOF(tested.data) == INSTANCEOF(searched.data))
			nb += tested.object.qty;
	}
	return (nb);
}

int inv_insert(struct inventory *inv, struct object object)
{
	unsigned int size = inv->size;
	unsigned int temp = object.qty;
	union to_data to_insert;
	union to_data tested;

	to_insert.object = object;
	for (unsigned int i = 0; i < size; i++) {
		tested.object = inv->objects[i];
		if (INSTANCEOF(tested.data) == INSTANCEOF(to_insert.data)) {
			inv->objects[i].qty += object.qty -
			((tested.object.qty + temp) % 63);
			object.qty = ((tested.object.qty + temp) % 63);
			temp = object.qty;
		} else if (!tested.data) {
			inv->objects[i] = object;
			temp = 0;
		}
	}
	return (!temp ? 1 : 0);
}

int inv_purge(struct inventory *inv)
{
	unsigned int size = inv->size;
	union to_data null;

	null.data = 0;
	for (unsigned int i = 0; i < size; i++) {
		if (!(inv->objects[i].qty))
			inv->objects[i] = null.object;
	}
	return (1);
}

int inv_remove(struct inventory *inv, struct object object)
{
	unsigned int size = inv->size;
	union to_data to_remove;
	union to_data tested;

	inv_purge(inv);
	to_remove.object = object;
	if (object.qty == 0)
		return (0);
	for (unsigned int i = 0; i < size; i++) {
		tested.object = inv->objects[i];
		if (INSTANCEOF(tested.data) == INSTANCEOF(to_remove.data)) {
			inv->objects[i].qty -= object.qty;
			object.qty = -(inv->objects[i].qty);
			return (inv_remove(inv, object));
		}
	}
	return (object.qty);
}