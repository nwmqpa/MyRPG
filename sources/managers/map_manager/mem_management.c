/*
** EPITECH PROJECT, 2017
** sources/managers/map_manager/mem_management.c
** File description:
** Memory management of the map manager.
*/

#include <stdio.h>
#include "map_parser.h"
#include "structs.h"
#include "utils.h"

struct map_manager *map_create_manager(char *map_path)
{
	struct map_manager *map_mgr = 0x0;
	char *map_txt = my_strcat(my_strdup(map_path), "/maps.txt");
	FILE *file = fopen(map_txt, "r");

	if (!file) {
		write(2, "The map descriptor file was not found.\n", 39);
		return (map_mgr);
	}
	fclose(file);
	map_mgr = my_calloc(sizeof(struct map_manager));
	map_mgr->map_descriptor = file;
	map_mgr->maps = my_calloc(sizeof(hashmap_t));
	return (map_mgr);
}