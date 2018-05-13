/*
** EPITECH PROJECT, 2017
** sources/managers/map_manager/management.c
** File description:
** Parse maps.
*/

#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "map_parser.h"
#include "utils.h"
#include "str_utils.h"
#include "npc.h"

void parse_bound(char *bounds, struct map *map)
{
	char **split = split_string(bounds, ':');

	map->bounds[0] = my_atoi(split[0]);
	map->bounds[1] = my_atoi(split[1]);
}

void parse_door(char *door_line, struct map *map)
{
	char **door = split_string(door_line, ':');
	struct door *door_sct = my_calloc(sizeof(struct door));

	if (!map->doors)
		map->doors = my_calloc(sizeof(hashmap_t));
	door_sct->scene_ref = door[1];
	door_sct->door_ref = door[2];
	door_sct->bounds = (sfIntRect) {my_atoi(door[3]),
					my_atoi(door[4]),
					my_atoi(door[5]) - my_atoi(door[3]),
					my_atoi(door[6]) - my_atoi(door[4])};
	insert_hash_elem(map->doors, door[0], door_sct);
}

void parse_container(char *container_line, struct map *map)
{
	char **cont = split_string(container_line, ':');
	struct container *cont_sct = my_calloc(sizeof(struct container));

	if (!map->containers)
		map->containers = my_calloc(sizeof(hashmap_t));
	cont_sct->bounds = (sfIntRect) {my_atoi(cont[2]),
					my_atoi(cont[3]),
					my_atoi(cont[4]) - my_atoi(cont[2]),
					my_atoi(cont[5]) - my_atoi(cont[3])};
	cont_sct->inv = create_random_loots((rand() % my_atoi(cont[1]))+ 1);
	insert_hash_elem(map->containers, cont[0], cont_sct);
}

void parse_layer(char *layer_line, struct map *map)
{
	char **layer = split_string(layer_line, ':');
	struct layer *layer_struct = my_calloc(sizeof(struct layer));

	if (!map->layers)
		map->layers = my_calloc(sizeof(hashmap_t));
	layer_struct->image = layer[1];
	insert_hash_elem(map->layers, layer[0], layer_struct);
}

void parse_npcs(char *npc_line, struct map *map)
{
	char **layer = split_string(npc_line, ':');
	char *path = my_strcat(my_strdup("assets/npc/"), layer[0]);
	struct npc *npc = 0x0;

	path = my_strcat(path, ".npc");
	npc = npc_load_from_file(path);
	npc->pos.x = my_atoi(layer[1]);
	npc->pos.y = my_atoi(layer[2]);
	if (!map->npcs)
		map->npcs = my_calloc(sizeof(hashmap_t));
	insert_hash_elem(map->npcs, layer[0], npc);
	free(path);
}
