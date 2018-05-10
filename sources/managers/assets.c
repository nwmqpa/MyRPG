/*
** EPITECH PROJECT, 2017
** assets_mng.c
** File description:
** assets functions
*/

#include <stdlib.h>
#include "assets_manager.h"
#include "utils.h"
#include "str_utils.h"
#include <stdlib.h>

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
	assets->textures[CHEST] = sfTexture_createFromFile(
	"assets/UI/Chest.png", NULL);
	for (int i = 0; i < 4; ++i) {
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
	char *temp = 0x0;
	char *temp_char = my_strdup("0\0");

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
	for (int i = GUN_1; i <= GUN_4; i++) {
		temp_char[0] = i + 45;
		temp = my_strcat(my_strdup("assets/textures/Stuff/Gun"), temp_char);
		temp = my_strcat(temp, ".png");
		assets->textures[i] = sfTexture_createFromFile(temp, NULL);
		assets->sprites[i] = sfSprite_create();
		sfSprite_setTexture(assets->sprites[i], assets->textures[i], sfTrue);
		free(temp);
	}
	free(temp_char);
	return (assets);
}

sfShader *get_shader(struct assets *ass, int id)
{
	return (ass->shaders[id]);
}
