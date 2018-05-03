/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** map structure and api
*/

#include "map.h"
#include "utils.h"

static void load_texture(map_t *map, char *path)
{
    int path_size = my_strlen(path);
    char *path_to_text = malloc(sizeof(char) * path_size + 256);

    for (int i = 0; i < NB_TEXTURE; ++i) {
        my_strcat(path_to_text, path);
        my_strcat(path_to_text, "layer");
        my_strcat(path_to_text, my_atoi(i + 1));
        my_strcat(path_to_text, ".png");
        map->texture[i] = sfTexture_createFromFile(path_to_text, NULL);
        if (i < NB_SPRITE) {
            map->sprite[i] = sfSprite();
            map->sprite[i] = sfSprite_setTexture(map->texture[i]);
        }
        memset(path_to_text, 0, path_size + 256);
    }
}

map_t *map_load(char *path, char *name, int id)
{
    map_t *map = malloc(sizeof(map_t));

    load_texture(map, path);
}
