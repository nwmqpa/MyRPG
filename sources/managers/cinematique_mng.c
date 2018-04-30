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

cin_t *cin_create(float time, char *string, sfFont *font, sfColor color)
{
	cin_t *cin = malloc(sizeof(cin_t));

	if (cin == NULL || string == NULL)
		return (NULL);
	cin->text = sfText_create(); 
	cin->time = time;
	cin->string = string;
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
	sfRenderWindow_clear(win, sfBlack);
	sfRenderWindow_drawText(win, cin->text, NULL);
	sfRenderWindow_display(win);
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
		a += 0.001;
	}
	cin_reset(cin);
	return (0);
}

#ifdef TEST_CIN
int main(void)
{
	FILE *file = fopen("../../ressources/cinematique/intro.txt", "r");
	sfFont *font = sfFont_createFromFile("../../assets/fonts/Thorne-n.ttf");
	char *string = malloc(1000000);
	fread(string, 1, 1000000, file);
	cin_t *cin = cin_create(30, string, font, (sfColor){255, 255, 255, 255});
        sfVideoMode mode = {1920, 1080, 32};
        sfRenderWindow *win = sfRenderWindow_create(mode, "Name", sfResize , NULL);
	sfRenderWindow_setFramerateLimit(win, 60);

	if (file == NULL || font == NULL || cin == NULL)
		return (1);
	cin_play(win, cin);
	return (1);
}
#endif
