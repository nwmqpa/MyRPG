/*
** EPITECH PROJECT, 2017
** sources/utils/hashmap_utils.c
** File description:
** hashmap utilities
*/

#include <stdlib.h>
#include "structs.h"
#include "utils.h"

int insert_hash_elem(hashmap_t *hashmap, const char *key, void *data)
{
	hash_t h = hash(key);
	hash_elem_t *temp = hashmap;

	if (!temp->hash) {
		temp->hash = h;
		temp->data = data;	
	}
	for (; temp->next; temp = temp->next);
	temp->next = my_calloc(sizeof(hash_elem_t));
	temp->next->prev = temp->next;
	temp->next->next = 0x0;
	temp->next->hash = h;
	temp->next->data = data;
	return (0);
}

int pop_hash_elem(hashmap_t *hashmap, const char *key)
{
	hash_t h = hash(key);
	hash_elem_t *temp = 0x0;

	for (temp = hashmap; temp; temp = temp->next) {
		if (temp->hash == h)
			break;
	}
	if (!temp)
		return (0);
	free(temp->data);
	if (temp->next)
		temp->next->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = temp->next;
	return (1);
}

void *get_hash_elem(hashmap_t *hashmap, const char *key)
{
	hash_t h = hash(key);

	for (hash_elem_t *temp = hashmap; temp; temp = temp->next) {
		if (temp->hash == h)
			return (temp->data);
	}
	return (0x0);
}

int has_hash_elem(hashmap_t *hashmap, const char *key)
{
	hash_t h = hash(key);

	for (hash_elem_t *temp = hashmap; temp; temp = temp->next) {
		if (temp->hash == h)
			return (1);
	}
	return (0);
}