/*
** EPITECH PROJECT, 2017
** ui.h
** File description:
** ui header
*/

#ifndef UI_H_
#define UI_H_

#define FONT_SIZE 24

#include <SFML/Graphics.h>

struct popup {
	char *string;
	sfText *text;
	sfSprite *sprite;
	sfTexture *texture;
	int pause;
	int value;
	float time;
};

//string is the text that will be print in the popup
struct popup *popup_create(char *string);

//pause is time between fading
void popup_animate(sfRenderWindow *win, struct popup *pop, int pause);

//If string == NULL keep old string
//If pause == NULL keep old pause
void popup_reset(struct popup *pop, char *string, int pause);

#endif
