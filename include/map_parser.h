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
#include "cybend2200.h"
#include "objects.h"

#define TOP_L	0x01
#define TOP_R	0x02
#define DOWN_L	0x04
#define DOWN_R	0x08

static __attribute__ ((unused)) const char *MAPS[3] = {"tutorial", "main_city", 0};

struct map_manager {
	hashmap_t *maps;
	FILE *map_descriptor;
	char *maps_folder;
};

struct map {
	char *name;
	sfShader *light_shader;
	sfImage *collide;
	hashmap_t *doors;
	hashmap_t *containers;
	hashmap_t *layers;
	hashmap_t *npcs;
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

struct map *parse_map(FILE *file, char *map_name);
void map_all_graph_init(struct map_manager *m_mgr);
struct map_manager *map_create_manager(char *map_path);
void parse_maps(struct map_manager *map_mgr);
struct map_manager *get_map_mgr(struct map_manager *map_mgr);
int draw_map(game_t *game);

#endif /* MAP_PARSER_H_ */