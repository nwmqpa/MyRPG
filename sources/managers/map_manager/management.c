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

static int parse_phase(int *prev_phase, char *line)
{
	if (my_memcmp(line, "layers") || my_memcmp(line, "doors"))
		*prev_phase = my_memcmp(line, "doors");
	else if (my_memcmp(line, "chests") || my_memcmp(line, "npcs"))
		*prev_phase = my_memcmp(line, "chests") ? 2 : 3;
	else {
		if (my_memcmp(line, "bounds"))
			*prev_phase = 4;
		else
			return -1;
	}
	return (0);
}

void do_parse(char *line, struct map *map, int phase)
{
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
	case 3:
		parse_npcs(line, map);
		break;
	case 4:
		parse_bound(line, map);
	}
}

struct map *parse_map(FILE *file, char *map_name)
{
	struct map *map = my_calloc(sizeof(struct map));
	char *shader_folder = my_strcat(my_strdup("assets/maps/"), map_name);
	char *line = 0x0;
	long unsigned int bytes = 0;
	int phase = 0;

	while (getline_w_n(&line, &bytes, file) != -1) {
		if (parse_phase(&phase, line) != -1) {
			free(line);
			bytes = 0;
			continue;
		}
		do_parse(line, map, phase);
		free(line);
		bytes = 0;
	}
	map->name = my_strdup(map_name);
	map->light_shader = sfShader_createFromFile
	(NULL, my_strcat(shader_folder, "/shader.frag"));
	return (map);
}
