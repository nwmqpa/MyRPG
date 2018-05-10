/*
** EPITECH PROJECT, 2017
** sources/entity/interaction.c
** File description:
** Make interaction between world and entity. 
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"
#include "entities.h"
#include "ress_manager.h"
#include "structs.h"
#include "map_parser.h"

static int check_door_collisions(game_t *game, sfIntRect pl, hashmap_t *doors)
{
	hashmap_t *maps = get_map_mgr(0x0)->maps;
	struct map *next_map = 0x0;
	struct door *temp_door = 0x0;
	sfIntRect rect;
	char *door_ref = 0x0;

	for (hash_elem_t *temp = doors; temp; temp = temp->next) {
		temp_door = temp->data;
		if (sfIntRect_intersects(&(temp_door->bounds), &pl, 0x0)) {
			door_ref = temp_door->door_ref;
			next_map = get_hash_elem(maps, temp_door->scene_ref);
			temp_door = get_hash_elem(next_map->doors, door_ref);
			rect = temp_door->bounds;
			get_ressources(NULL)->player->entity->pos =
					(vec_t) {rect.left,rect.top};
			game->actual_map = next_map;
			return (1);
		}
	}
	return (0);
}

static int check_chest_collisions(game_t *game, sfIntRect pl, hashmap_t *cont)
{
	struct container *container = 0x0;

	for (hashmap_t *temp = cont; temp; temp = temp->next) {
		container = temp->data;
		if (sfIntRect_intersects(&(container->bounds), &pl, 0x0)) {
			game->gamemode = MENU;
			game->menu_type = CONTAINER;
			game->container = container->inv;
			return (1);
		}
	}
	return (0);
}

void check_interactions(game_t *game)
{
	sfSprite *spr = get_ressources(NULL)->player->actual->sprite[0];
	sfFloatRect rect = sfSprite_getGlobalBounds(spr);
	sfIntRect p_trans = {rect.left, rect.top, rect.width, rect.height};
	struct map *map = game->actual_map;

	if (check_door_collisions(game, p_trans, map->doors))
		return;
	if (check_chest_collisions(game, p_trans, map->containers))
		return;
}