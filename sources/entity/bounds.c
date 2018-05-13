/*
** EPITECH PROJECT, 2017
** sources/entity/bounds.c
** File description:
** bounds.c
*/

#include "map_parser.h"
#include "entities.h"
#include "cybend2200.h"

int check_bounds(struct player *pl, float act_pos, int *bounds, game_t *game)
{
	if (act_pos >= bounds[0] && act_pos <= bounds[1])
		return (0);
	if (act_pos > bounds[1])
		pl->entity->pos.x = bounds[1] + game->delta_pos.x;
	if (act_pos < bounds[0])
		pl->entity->pos.x = bounds[0];
	return (1);
}