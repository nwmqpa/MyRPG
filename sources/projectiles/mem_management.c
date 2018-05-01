/*
** EPITECH PROJECT, 2017
** sources/projectiles/mem_management.c
** File description:
** Memory management of projectiles.
*/

#include "entities.h"
#include "projectiles.h"
#include "objects.h"
#include "structs.h"
#include "utils.h"

struct projectile *proj_create(struct entity *entity, struct vector cur_pos)
{
	struct vector entity_pos = entity->pos;
	struct projectile *proj = my_calloc(sizeof(struct projectile));

	proj->base_pos = entity_pos;
	proj->fire_pos = cur_pos;
	proj->speed = GET_SPEED_FROM_LVL(entity->weapon->spd_lvl);
	return (proj);
}

void proj_free(struct projectile **proj)
{
	free(*proj);
}