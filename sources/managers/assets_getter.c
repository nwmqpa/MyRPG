/*
** EPITECH PROJECT, 2017
** assets_getter.c
** File description:
** assets
*/

#include "assets_manager.h"

sfFont *get_font(struct assets *ass, int id)
{
	return (ass->fonts[id]);
}

sfMusic *get_music(struct assets *ass, int id)
{
	return (ass->musics[id]);
}

sfSound *get_sound(struct assets *ass, int id)
{
	return (ass->sounds[id]);
}

struct assets *get_assets(struct assets *ass)
{
	static struct assets *assets = NULL;

	if (ass != NULL)
		assets = ass;
	return (assets);
}