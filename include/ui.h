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
#include "cybend2200.h"

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
struct popup *popup_create(char *string, int pause);

//pause is time between fading
int popup_animate(sfRenderWindow *win, struct popup *pop);

//If string == NULL keep old string
//If pause == NULL keep old pause
void popup_reset(struct popup *pop);
void popup_set_text(struct popup *pop, char *str);
int draw_ui(game_t *game);
void draw_popup(game_t *game);
int draw_dialog(game_t *game);

#endif
