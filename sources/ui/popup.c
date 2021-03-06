/*
** EPITECH PROJECT, 2017
** popup.c
** File description:
** popup ui part
*/

#include <stdlib.h>
#include "ui.h"
#include "cybend2200.h"
#include "assets_manager.h"
#include "str_utils.h"
#include "utils.h"

void draw_popup(game_t *game)
{
	if (popup_animate(game->win, game->popup) == -1)
		game->ui[POPUP_UI] = 0;
}


struct popup *popup_create(char *string, int pause)
{
	struct popup *my_popup = my_calloc(sizeof(struct popup));

	if (my_popup == NULL)
		return (NULL);
	my_popup->text = sfText_create();
	my_popup->sprite = sfSprite_create();
	my_popup->texture =
	sfTexture_createFromFile("assets/ui/popup.png", NULL);
	my_popup->string = my_strdup(string);
	my_popup->time = 0;
	my_popup->value = -249;
	my_popup->pause = pause;
	sfSprite_setTexture(my_popup->sprite, my_popup->texture, sfTrue);
	sfText_setColor(my_popup->text, sfWhite);
	sfText_setString(my_popup->text, string);
	sfText_setFont(my_popup->text, get_assets(NULL)->fonts[THORN]);
	sfText_setCharacterSize(my_popup->text, FONT_SIZE);
	sfSprite_setPosition(my_popup->sprite, (sfVector2f){WIDTH - 600, -250});
	sfText_setPosition(my_popup->text, (sfVector2f){WIDTH - 590, -240});
	return (my_popup);
}

int popup_animate(sfRenderWindow *win, struct popup *pop)
{
	double dtime = get_dtime(-1);

	if (sfSprite_getPosition(pop->sprite).y < 50 &&
	pop->time < pop->pause) {
		sfSprite_move(pop->sprite, (sfVector2f){0, 400 * dtime});
		sfText_move(pop->text, (sfVector2f){0, 400 * dtime});
	} else if (sfSprite_getPosition(pop->sprite).y >= 50 &&
	pop->time < pop->pause) {
		sfSprite_setPosition(pop->sprite, (sfVector2f){
			WIDTH - 600, 50});
		pop->time += dtime;
	} else if (sfSprite_getPosition(pop->sprite).y > -250 &&
	pop->time >= pop->pause){
		sfSprite_move(pop->sprite, (sfVector2f){0, -400 * dtime});
		sfText_move(pop->text, (sfVector2f){0, -400 * dtime});
	} else
		return popup_reset(pop);
	sfRenderWindow_drawSprite(win, pop->sprite, NULL);
	sfRenderWindow_drawText(win, pop->text, NULL);
	return 0;
}

int popup_reset(struct popup *pop)
{
	pop->time = 0;
	pop->value = -249;
	return -1;
}

void popup_launch(game_t *game, char *string)
{
	game->ui[POPUP_UI] = 1;
	free(game->popup->string);
	game->popup->string = my_strdup(string);
	sfText_setString(game->popup->text, game->popup->string);
	popup_reset(game->popup);
}
