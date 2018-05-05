/*
** EPITECH PROJECT, 2017
** sources/managers/map_manager/graph_management.c
** File description:
** graphical management of the map_parser.
*/

#include <stdlib.h>
#include "map_parser.h"
#include "str_utils.h"

static void map_graph_init(struct map *map, char const *base_path)
{
	char *file = my_strdup(base_path);
	struct layer *layer_tmp = 0x0;

	for (struct hash_elem *tmp = map->layers; tmp; tmp = tmp->next) {
		layer_tmp = (struct layer *) tmp->data;
		file = my_strcat(file, my_strdup(map->name));
		file = my_strcat(file, "/assets/");
		file = my_strcat(file, layer_tmp->image);
		printf("%s\n", file);
		layer_tmp->texture = sfTexture_createFromFile(file, NULL);
		layer_tmp->sprite = sfSprite_create();
		sfSprite_setTexture(layer_tmp->sprite, layer_tmp->texture, 1);
		free(file);
		file = my_strdup(base_path);
	}
}

void map_all_graph_init(struct map_manager *m_mgr)
{
	for (struct hash_elem *tmp = m_mgr->maps; tmp; tmp = tmp->next) {
		map_graph_init((struct map *) tmp->data, m_mgr->maps_folder);
	}
}