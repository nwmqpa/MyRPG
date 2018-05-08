/*
** EPITECH PROJECT, 2017
** assets_mng.c
** File description:
** assets functions
*/

#include "assets_manager.h"
#include "utils.h"

// Set sounds
static void set_sound(struct assets *assets)
{
	assets->sound_buffer[PISTOL] =
	sfSoundBuffer_createFromFile("assets/sound/light.ogg");
	assets->sound_buffer[RIFLE] =
	sfSoundBuffer_createFromFile("assets/sound/heavy.ogg");
	assets->sound_buffer[FOOTSTEP] =
	sfSoundBuffer_createFromFile("assets/sound/footstep.ogg");
	for (int i = 0; i < 3; ++i) {
		assets->sounds[i] = sfSound_create();
		sfSound_setBuffer(
		assets->sounds[i], assets->sound_buffer[i]);
	}
}

static void set_shader(struct assets *assets)
{
	assets->shaders[LIGHT] = sfShader_createFromFile
	(NULL, "./assets/shaders/glow.frag");
	assets->shaders[BLUR] = sfShader_createFromFile
	(NULL, "./assets/shaders/blur.frag");
}

// Set all assets from ./assets
struct assets *create_assets(void)
{
	struct assets *assets = my_calloc(sizeof(struct assets));

	assets->fonts[0] = sfFont_createFromFile("assets/fonts/Flighter.ttf");
	assets->fonts[1] = sfFont_createFromFile("assets/fonts/Thorne-n.ttf");
	assets->musics[CAVE] = sfMusic_createFromFile("assets/music/cave.ogg");
	assets->musics[CITY] = sfMusic_createFromFile("assets/music/city.ogg");
	sfMusic_setVolume(assets->musics[CAVE], 3);
	sfMusic_setVolume(assets->musics[CITY], 3);
	set_sound(assets);
	set_shader(assets);
	return (assets);
}

sfShader *get_shader(struct assets *ass, int id)
{
	return (ass->shaders[id]);
}
