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
	CAVE,
	CITY
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

enum SPRITE {
	POPUP,
	DIALOG_BOX,
	INVENTORY,
	CHEST
};

enum ANIM {
	LIFES
};

enum SHADER {
	LIGHT,
	BLUR
};

/*
** Assets Manager:
**	Represent one instance of all the assets
**	of the game currently load.
*/
struct assets {
	sfShader	*shaders[2];
	sfSprite	*sprites[4];
	sfTexture	*textures[4];
	sfSound		*sounds[3];
	sfSoundBuffer	*sound_buffer[3];
	sfMusic		*musics[2];
	sfFont		*fonts[2];
	anim_t		*anims[1];
};

typedef struct assets assets_t;

// Getter of the struct
struct assets *get_assets(struct assets *assets);

// Getter
sfShader *get_shader(struct assets *ass, int id);
sfSprite *get_sprite(struct assets *ass, int id);
sfSound	 *get_sound(struct assets *ass, int id);
sfMusic	 *get_music(struct assets *ass, int id);
sfFont	 *get_font(struct assets *ass, int id);

// Constructor
struct assets *create_assets(void);

#endif /* RESSOURCES_MANAGER_H */