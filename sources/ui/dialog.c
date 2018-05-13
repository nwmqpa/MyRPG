/*
** EPITECH PROJECT, 2017
** popup.c
** File description:
** popup ui part
*/

#include <stdlib.h>
#include "assets_manager.h"
#include "cybend2200.h"
#include "ui.h"
#include "utils.h"

void draw_dialog(sfRenderWindow *win, struct dialog *dialog)
{
	sfRenderWindow_drawSprite(win, dialog->sprite, NULL);
	sfRenderWindow_drawText(win, dialog->text, NULL);
}

static char **alloc_string(char *string)
{
	int i = -1;
	int x = 0;
	int y = 0;
	int nb_chaine = 1;
	char **char_etoile_etoile = NULL;

	while (string[++i])
		if (string[i] == ':')
			nb_chaine++;
	char_etoile_etoile = my_calloc(sizeof(char *) * (nb_chaine + 1));
	i = -1;
	while (string[++i]) {
		if (string[i] == ':') {
			char_etoile_etoile[y++] = my_calloc(x + 1);
			x = 0;
		}
		x++;
	}
	char_etoile_etoile[y] = my_calloc(sizeof(char) * x + 1);
	return (char_etoile_etoile);
}

static char **create_string(char *string)
{
	int i = -1;
	int y = 0;
	int x = 0;
	char **char_etoile_etoile = NULL;

	char_etoile_etoile = alloc_string(string);
	while (string[++i]) {
		if (string[i] == ':') {
			++y;
			x = 0;
			i++;
		}
		char_etoile_etoile[y][x++] = string[i];
	}
	return (char_etoile_etoile);
}

struct dialog *dialog_create(char *string)
{
	struct dialog *this = malloc(sizeof(struct dialog));

	this->texture = sfTexture_createFromFile(
	"assets/UI/Dialog.png", NULL);
	this->sprite = sfSprite_create();
	this->text = sfText_create();
	sfText_setFont(this->text, get_assets(NULL)->fonts[THORN]);
	sfSprite_setTexture(this->sprite, this->texture, sfTrue);
	sfSprite_setPosition(this->sprite, (sfVector2f){530, HEIGHT - 220});
	sfText_setPosition(this->text, (sfVector2f){555, HEIGHT - 195});
	this->string = create_string(string);
	sfText_setString(this->text, this->string[0]);
	return (this);
}

void dialog_launch(game_t *game, struct dialog *dialog, char *str)
{
	game->ui[DIALOG_UI] = 1;
	dialog->count = 0;
	for (int i = 0; dialog->string[i]; ++i)
		free(dialog->string[i]);
	free(dialog->string);
	dialog->string = create_string(str);
	sfText_setString(dialog->text, dialog->string[0]);
}
