/*
** EPITECH PROJECT, 2017
** include/map_parser.h
** File description:
** Map parsing header.
*/

#ifndef MAP_PARSER_H_
#define MAP_PARSER_H_

#include <stdio.h>
#include <SFML/Graphics.h>
#include "structs.h"
#include "objects.h"

struct map_manager {
	hashmap_t *maps;
	FILE *map_descriptor;
	char *maps_folder;
};

struct map {
	char *name;
	hashmap_t *doors;
	hashmap_t *containers;
	hashmap_t *layers;
};

struct door {
	sfIntRect bounds;
	char *scene_ref;
	char *door_ref;
};

struct container {
	sfIntRect bounds;
	struct inventory *inv;
};

struct layer {
    	sfSprite *sprite;
    	sfTexture *texture;
	char *image;
};

typedef struct map_manager map_mgr_t;

struct map *parse_map(FILE *file);
void map_all_graph_init(struct map_manager *m_mgr);
struct map_manager *map_create_manager(char *map_path);
void parse_maps(struct map_manager *map_mgr);

#endif /* MAP_PARSER_H_ */