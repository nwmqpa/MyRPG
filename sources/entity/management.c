/*
** EPITECH PROJECT, 2017
** sources/entity/management.c
** File description:
** Management for the entity module.
*/

#include <math.h>
#include "structs.h"
#include "entities.h"
#include "utils.h"

uint32_t compute_player_power(UNUSED struct player *player)
{
	return (32);
}

uint32_t compute_entity_power(UNUSED struct entity *entity)
{
	return (32);
}

int compute_xp(uint32_t player_power, uint32_t entity_power)
{
	float ply_log = log2f(player_power);
	float ent_log = log2f(entity_power);
	float res_log = ent_log - ply_log;

	return ((int) exp(res_log));
}