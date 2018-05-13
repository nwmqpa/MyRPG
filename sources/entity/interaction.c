/*
** EPITECH PROJECT, 2017
** sources/entity/interaction.c
** File description:
** Make interaction between world and entity.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "cybend2200.h"
#include "entities.h"
#include "ress_manager.h"
#include "structs.h"
#include "assets_manager.h"
#include "map_parser.h"
#include "npc.h"
#include "ui.h"

void do_boundary(
struct map *next_map, struct door *temp_door, sfIntRect *rect, game_t *game)
{
	struct layer *map = game->actual_map->layers->data;
	sfIntRect map_rect = sfSprite_getTextureRect(map->sprite);
	sfVector2f pos;

	*rect = temp_door->bounds;
	if (rect->left > map_rect.width * 0.75) {
		game->delta_pos.x = -1920;
		rect->left = rect->left - (map_rect.width / 2);
	} else if (rect->left <= map_rect.width * 0.25) {
		game->delta_pos.x = 0;
	}
	pos.x = rect->left;
	pos.y = 780,
	player_set_position(get_ressources(NULL)->player, pos);
	game->actual_map = next_map;
	sfSound_play(get_assets(0x0)->sounds[DOOR]);
	draw_player(game, game->win, get_ressources(0x0)->player);
}

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
			do_boundary(next_map, temp_door, &rect, game);
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

static int check_npc_collisions(game_t *game, sfIntRect pl, hashmap_t *npcs)
{
	struct npc *npc = NULL;
	int x = 0;
	int y = 0;

	for (hashmap_t *temp = npcs; temp; temp = temp->next) {
		npc = (struct npc *) temp->data;
		x = sfSprite_getPosition(npc->sprite).x - game->delta_pos.x;
		y = sfSprite_getPosition(npc->sprite).y;
		if (sfIntRect_contains(&pl, x + 25, y + 50)) {
			do_npc_interact(game, npc);
			return 1;
		}
	}
	return 0;
}

void check_interactions(game_t *game)
{
	sfSprite *spr = get_ressources(NULL)->player->actual->sprite[0];
	sfFloatRect rect = sfSprite_getGlobalBounds(spr);
	sfIntRect p_trans = {rect.left, rect.top, rect.width, rect.height};
	struct map *map = game->actual_map;
	struct quest **q = &get_ressources(NULL)->quest;

	p_trans.left -= game->delta_pos.x;
	if (check_npc_collisions(game, p_trans, map->npcs))
		return;
	if (check_door_collisions(game, p_trans, map->doors)) {
		if ((*q)->id == 3 &&
		!strcmp(game->actual_map->name, "main_city"))
			valid_quest(game, q, get_ressources(NULL)->player, 3);
		return;
	} if (check_chest_collisions(game, p_trans, map->containers))
		return;
}