/*
** EPITECH PROJECT, 2017
** assets_manager.h
** File description:
** ressource manager file
*/

#ifndef ASSETS_MANAGER_H_
#define ASSETS_MANAGER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "anim.h"

enum sprite {
	NAME_1,
	NAME_2
};

enum sound {
	NAME_1,
	NAME_2
};

enum music {
	NAME_1,
	NAME_2
};

enum animation {
	NAME_1,
	NAME_2
};

/*
** Assets Manager:
**	Represent one instance of all the assets
**	of the game currently load.
*/
typedef struct {
	sfSprite **sprites;
	sfSound **sounds;
	sfMusic **musics;
	animation_t **animations;
} assets_mng_t;

//Getter of the struct
assets_mng_t *get_assets_mng(assets_mng_t *assets);
//Constructor
assets_mng_t *create_assets_mng(char *path_to_assets);
//Getter
sfSprite     **get_sprites(void);
sfsprite     *get_sprite(int which);
sfSound      **get_sounds(void);
sfSound      *get_sound(int which);
sfMusic      **get_music(void);
sfMusic      *get_music(int which);

#endif /* RESSOURCES_MANAGER_H */
