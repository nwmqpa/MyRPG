/*
** EPITECH PROJECT, 2017
** assets_mng.c
** File description:
** assets functions
*/

#include "assets_manager.h"
#include "utils.h"

static void set_sound(struct assets *assets)
{
	assets->sound_buffer[0] =
	sfSoundBuffer_createFromFile("assets/sound/light.ogg");
	assets->sound_buffer[1] =
	sfSoundBuffer_createFromFile("assets/sound/heavy.ogg");
	assets->sound_buffer[2] =
	sfSoundBuffer_createFromFile("assets/sound/footstep.ogg");
	assets->sounds[0] = sfSound_create();
	assets->sounds[1] = sfSound_create();
	assets->sounds[2] = sfSound_create();
	sfSound_setBuffer(assets->sounds[0], assets->sound_buffer[0]);
	sfSound_setBuffer(assets->sounds[1], assets->sound_buffer[1]);
	sfSound_setBuffer(assets->sounds[2], assets->sound_buffer[2]);
}

//Set all assets that are not sprites
struct assets *create_assets(void)
{
	struct assets *assets = my_calloc(sizeof(struct assets));

	assets->fonts[0] = sfFont_createFromFile("assets/fonts/Flighter.ttf");
	assets->fonts[1] = sfFont_createFromFile("assets/fonts/Thorne-n.ttf");
	assets->musics[0] = sfMusic_createFromFile("assets/music/cave.ogg");
	assets->musics[1] = sfMusic_createFromFile("assets/music/city.ogg");
	set_sound(assets);
	return (assets);
}