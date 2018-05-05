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
#include "objects.h"
#include "utils.h"
#include "stats.h"

struct entity *ent_create(vec_t pos, uint32_t max_hp, uint32_t level)
{
	struct entity *ent = my_calloc(sizeof(struct entity));

	ent->weapon = my_calloc(sizeof(struct object));
	*(ent->weapon) = obj_create(level);
	ent->max_hp = max_hp;
	ent->hp = max_hp;
	ent->loots = create_random_loots(level);
	ent->pos = pos;
	ent->ammos = -1;
	return (ent);
}

struct player *create_player(vec_t pos, uint32_t max_hp, uint32_t level)
{
	struct player *player = my_calloc(sizeof(struct player));

	player->entity = ent_create(pos, max_hp, level);
	skills_init(player);
	stats_init(player);
	player->inv = inv_create(18);
	player->level = 1;
	player->xp = (struct vector) {0, 0};
	return (player);
}

void ent_free(struct entity **ent)
{
	free((*ent)->weapon);
	inv_free(&((*ent)->loots));
	free(*ent);
}