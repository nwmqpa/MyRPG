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

struct dialog {
	char **string;
	sfText *text;
	sfTexture *texture;
	sfSprite *sprite;
	int count;
};

// string is to
struct dialog *dialog_create(char *string);

void dialog_reset(struct dialog *dialog);
void dialog_launch(game_t *game, struct dialog *dialog, char *str);
void draw_dialog(sfRenderWindow *win, struct dialog *dialog);
void next_dialog(game_t *game, struct dialog *dialog);
int dialog_event(game_t *game);

// string is the text that will be print in the popup
struct popup *popup_create(char *string, int pause);

int popup_animate(sfRenderWindow *win, struct popup *pop);
void popup_reset(struct popup *pop);
void popup_set_text(struct popup *pop, char *str);
void popup_launch(game_t *game, char *str);
int draw_ui(game_t *game);
void draw_popup(game_t *game);

#endif