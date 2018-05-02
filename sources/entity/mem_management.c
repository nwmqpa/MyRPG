/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include <stdlib.h>
#include "objects.h"
#include "entities.h"
#include "structs.h"
#include "utils.h"

struct entity *ent_create(vec_t pos, uint32_t max_hp, uint32_t level)
{
	struct entity *ent = my_calloc(sizeof(struct entity));

	ent->weapon = obj_create(level);
	ent->max_hp = max_hp;
	ent->hp = max_hp;
	ent->loots = create_random_loots(level);
	ent->pos = pos;
	ent->ammos = -1;
	return (ent);
}

void ent_free(struct entity **ent)
{
	free((*ent)->weapon);
	inv_free((*ent)->loots);
	free(*ent);
}