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
};

struct map {
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
	char *texture;
};

typedef struct map_manager map_mgr_t;

#endif /* MAP_PARSER_H_ */