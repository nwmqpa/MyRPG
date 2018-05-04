/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** map structure and api
*/

#include "map.h"
#include "utils.h"
#include "str_utils.h"
#include "entities.h"

int map_update(map_t *map, struct player *player,float d_time)
{
    return (0);
}

//TODO: Do it with asset manager
int map_draw(sfRenderWindow *win, map_t *map, float d_time)
{
    sfShader *shader = 
    sfShader_createFromFile("shaders/simple.vert", "shaders/glow.frag");
    sfRenderStates state = {
                            sfBlendAlpha,
                            sfTransform_Identity,
                            sfSprite_getTexture(map->sprites[LIGHT]),
                            shader
                            };

    for (int i = 0; i < 3; ++i)
        sfRenderWindow_drawSprite(win, map->sprites[i], NULL);
    sfRenderWindow_drawSprite(win, map->sprites[LIGHT], &state);
    return (0);
}

static void load_texture(map_t *map, char *path)
{
    int path_size = my_strlen(path);
    char *path_to_text = malloc(sizeof(char) * path_size + 256);

    for (int i = 0; i < NB_TEXTURE; ++i) {
        my_strcat(path_to_text, path);
        my_strcat(path_to_text, "layer");
        my_strcat(path_to_text, my_itoa(i + 1));
        my_strcat(path_to_text, ".png");
        map->texture[i] = sfTexture_createFromFile(path_to_text, NULL);
        if (i < NB_SPRITE) {
            map->sprites[i] = sfSprite_create();
            sfSprite_setTexture(map->sprites[i], map->texture[i], sfTrue);
        }
        memset(path_to_text, 0, path_size + 256);
    }
}

map_t *map_load(char *path, char *name)
{
    static int current_id = 1;
    map_t *map = malloc(sizeof(map_t));
    int sizes[2] = {1920 * 2, 1080};

    load_texture(map, path);
    map->id = current_id++;
    map->size[0] = sizes[0];
    map->size[1] = sizes[1];
    map->name = my_strdup(name);
    return (map);
}
