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

static void set_ui(struct assets *assets)
{
	assets->textures[POPUP] = sfTexture_createFromFile(
	"assets/UI/Popup.png", NULL);
	assets->textures[DIALOG_BOX] = sfTexture_createFromFile(
	"assets/UI/Popup.png", NULL);
	assets->textures[INVENTORY] = sfTexture_createFromFile(
	"assets/UI/Inventory.png", NULL);
	for (int i = 0; i < 3; ++i) {
		assets->sprites[i] = sfSprite_create();
		sfSprite_setTexture(
		assets->sprites[i], assets->textures[i], sfTrue);
	}
	assets->anims[LIFES] = create_anim_path_rect(
	"assets/UI/LifesAnimation.png", 2, 0.1, (sfIntRect){0, 0, 100, 100});
}

// Set all assets from ./assets
struct assets *create_assets(void)
{
	struct assets *assets = my_calloc(sizeof(struct assets));

	assets->fonts[FLIGHTER] =
	sfFont_createFromFile("assets/fonts/Flighter.ttf");
	assets->fonts[THORN] =
	 sfFont_createFromFile("assets/fonts/Thorne-n.ttf");
	assets->musics[CAVE] = sfMusic_createFromFile("assets/music/cave.ogg");
	assets->musics[CITY] = sfMusic_createFromFile("assets/music/city.ogg");
	sfMusic_setVolume(assets->musics[CAVE], 5);
	sfMusic_setVolume(assets->musics[CITY], 5);
	set_sound(assets);
	set_shader(assets);
	set_ui(assets);
	return (assets);
}

sfShader *get_shader(struct assets *ass, int id)
{
	return (ass->shaders[id]);
}
