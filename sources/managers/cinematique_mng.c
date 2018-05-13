/*
** EPITECH PROJECT, 2017
** cinematique_mng.c
** File description:
** cin_manager
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "cin_mng.h"
#include "str_utils.h"

cin_t *cin_create(float time, char *string, sfFont *font, sfColor color)
{
	cin_t *cin = malloc(sizeof(cin_t));

	if (cin == NULL || string == NULL)
		return (NULL);
	cin->text = sfText_create();
	cin->time = my_strlen(string) * 0.0050;
	cin->string = my_strdup(string);
	cin->font = font;
	cin->pos = (sfVector2f){200, 500};
	cin->char_size = 24;
	sfText_setColor(cin->text, color);
	sfText_setString(cin->text, string);
	sfText_setFont(cin->text, font);
	sfText_setCharacterSize(cin->text, 24);
	sfText_setPosition(cin->text, cin->pos);
	return (cin);
}

void cin_update(sfRenderWindow *win, cin_t *cin)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		cin->time = 0;
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawText(win, cin->text, NULL);
	sfRenderWindow_display(win);
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		sfText_move
		(cin->text, (sfVector2f){0, -cin->time * 240 * 0.0016});
		return;
	}
	sfText_move(cin->text, (sfVector2f){0, -cin->time * 10 * 0.0016});
}

void cin_reset(cin_t *cin)
{
	sfText_setPosition(cin->text, (sfVector2f){0, 0});
}

int cin_play(sfRenderWindow *win, cin_t *cin)
{
	float a = 0;

	while (a < cin->time) {
		cin_update(win, cin);
		if (sfKeyboard_isKeyPressed(sfKeyDown))
			a += 0.024;
		else
			a += 0.001;
	}
	cin_reset(cin);
	return (0);
}

void cin_free(cin_t *cin)
{
	sfText_destroy(cin->text);
	free(cin->string);
	free(cin);
}
