/*
** EPITECH PROJECT, 2017
** map.h
** File description:
** map structure and api
*/

#ifndef MAP_H_
#define MAP_H_

#define NB_SPRITE 5
#define NB_TEXTURE 5

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


enum MAP {
    BACK,
    MID,
    FRONT,
    LIGHT,
    DETECTOR
};

struct map_s {
    sfSprite *parrallax[5];
    sfTexture *texture[5];
    char *name;
    int id;
    int size[2];
};

typedef struct map_s map_t;

map_t *map_load(char *path, char *name, int id);
int map_draw(map_t *map, float d_time);
int map_update(map_t *map, float d_time);

#endif /* MAP_H_ */