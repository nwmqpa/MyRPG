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

enum MUSIC {
	MUSIC1,
	MUSIC2
};

enum SOUND {
	FOOTSTEP,
	PISTOL,
	RIFLE
};

enum FONT {
	THORN,
	FLIGHTER
};

/*
** Assets Manager:
**	Represent one instance of all the assets
**	of the game currently load.
*/
struct assets {
	sfSound		*sounds[3];
	sfSoundBuffer	*sound_buffer[3];
	sfMusic		*musics[2];
	sfFont		*fonts[2];
};

typedef struct assets assets_t;

//Getter of the struct
struct assets *get_assets(struct assets *assets);

//Getter
sfFont	*get_font(struct assets *ass, int id);
sfSound	*get_sound(struct assets *ass, int id);
sfMusic	*get_music(struct assets *ass, int id);

//Constructor
struct assets *create_assets(void);

#endif /* RESSOURCES_MANAGER_H */
