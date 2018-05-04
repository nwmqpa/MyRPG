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

/*
** Assets Manager:
**	Represent one instance of all the assets
**	of the game currently load.
*/
struct assets {
	sfSound		*sounds[2];
	sfSoundBuffer	*sound_buffer[2];
	sfMusic		*musics[2];
	sfFont		*fonts[2];
};

typedef struct assets assets_t;

//Getter of the struct
struct assets *get_assets(struct assets *assets);

//Constructor
struct assets *create_assets_mng(void);

#endif /* RESSOURCES_MANAGER_H */
