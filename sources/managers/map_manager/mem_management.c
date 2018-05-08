/*
** EPITECH PROJECT, 2017
** sources/managers/map_manager/mem_management.c
** File description:
** Memory management of the map manager.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map_parser.h"
#include "structs.h"
#include "utils.h"
#include "str_utils.h"

struct map_manager *map_create_manager(char *map_path)
{
	struct map_manager *map_mgr = 0x0;
	char *map_txt = my_strcat(my_strdup(map_path), "/maps.txt");
	FILE *file = fopen(map_txt, "r");

	if (!file) {
		write(2, "The map descriptor file was not found.\n", 39);
		return (map_mgr);
	}
	map_mgr = my_calloc(sizeof(struct map_manager));
	map_mgr->maps_folder = my_strcat(my_strdup(map_path), "/");
	map_mgr->map_descriptor = file;
	map_mgr->maps = my_calloc(sizeof(hashmap_t));
	return (map_mgr);
}

void parse_maps(struct map_manager *map_mgr)
{
	FILE *file = 0x0;
	char *map_path = 0x0;
	char *line = 0x0;
	long unsigned int bytes = 0;

	while (getline_w_n(&line, &bytes, map_mgr->map_descriptor) != -1) {
		map_path = my_strcat(my_strdup(map_mgr->maps_folder), line);
		map_path = my_strcat(map_path, "/city.txt");
		file = fopen(map_path, "r");
		if (!file) {
			write(2, "Cannot open ", 12);
			write(2, map_path, my_strlen(map_path));
			write(2, "\n", 1);
			continue;
		}
		insert_hash_elem(map_mgr->maps, line, parse_map(file, line));
		free(map_path);
		bytes = 0;
	}
}

struct map_manager *get_map_mgr(struct map_manager *map_mgr)
{
	static struct map_manager *map_manager = NULL;

	if (map_mgr != NULL)
		map_manager = map_mgr;
	return (map_manager);
}