/*
** EPITECH PROJECT, 2017
** player_api2.c
** File description:
** Player api file 2
*/

#include "map_parser.h"
#include "assets_manager.h"
#include "entities.h"

int player_colliding(struct player *player, game_t *game)
{
	sfImage *collide = game->actual_map->collide;
	sfFloatRect hit = player->hitbox;
	int ret = 0;

	if (sfImage_getPixel(collide, hit.left, hit.top).a != 0)
		ret |= TOP_L;
	if (sfImage_getPixel(collide, hit.left + hit.width, hit.top).a != 0)
		ret |= TOP_R;
	if (sfImage_getPixel(collide, hit.left, hit.top + hit.height).a != 0)
		ret |= DOWN_L;
	if (sfImage_getPixel(
	collide, hit.left + hit.width, hit.top + hit.height).a != 0)
		ret |= DOWN_R;
	return (ret);
}