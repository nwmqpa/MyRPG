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

static void parse_door(char *door_line, struct map *map)
{
	char **door = split_string(door_line, ':');
	struct door *door_sct = my_calloc(sizeof(struct door));

	if (!map->doors)
		map->doors = my_calloc(sizeof(hashmap_t));
	door_sct->scene_ref = door[1];
	door_sct->door_ref = door[2];
	door_sct->bounds = (sfIntRect) {door[1], door[2], door[3], door[4]};
	insert_hash_elem(map->doors, door[0], door_sct);
}

static void parse_container(char *container_line, struct map *map)
{
	char **cont = split_string(container_line, ':');
	struct container *con_struct = my_calloc(sizeof(struct container));

	if (!map->containers)
		map->containers = my_calloc(sizeof(hashmap_t));
	con_struct->bounds = (sfIntRect) {cont[1], cont[2], cont[3], cont[4]};
	insert_hash_elem(map->containers, cont[0], con_struct);
}

static void *parse_layer(char *layer_line, struct map *map)
{
	char **layer = split_string(layer_line, ':');
	struct layer *layer_struct = my_calloc(sizeof(struct layer));

	if (!map->layers)
		map->layers = my_calloc(sizeof(hashmap_t));
	layer_struct->image = layer[1];
	insert_hash_elem(map->layers, layer[0], layer_struct);
}

int parse_phase(int *prev_phase, char *line)
{
	if (my_memcmp(line, "layers") || my_memcmp(line, "doors"))
		*prev_phase = my_memcmp(line, "doors");
	else if (my_memcmp(line, "chests"))
		*prev_phase = 2;
	else
		return (-1);
	return (0);
}

struct map *parse_map(FILE *file)
{
	struct map *map = my_calloc(sizeof(struct map));
	char *line = 0x0;
	int bytes = 0;
	int phase = 0;

	while (getline(&line, &bytes, file) != -1) {
		if (parse_phase(phase, line) != -1)
			continue;
		switch (phase) {
		case 0:
			parse_layer(line, map);
			break;
		case 1:
			parse_door(line, map);
			break;
		case 2:
			parse_container(line, map);
			break;
		}
		free(line);
		bytes = 0;
	}
	return (map);
}