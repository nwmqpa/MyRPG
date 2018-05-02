/*
** EPITECH PROJECT, 2017
** popup.c
** File description:
** popup ui part
*/

#include "ui.h"

struct popup *popup_create(char *string, int pause)
{
	struct popup *my_popup = malloc(sizeof(struct popup));

	if (my_popup == NULL)
		return (NULL);
	my_popup->text = sfText_create();
	my_popup->back = sfSprite_create();
	my_popup->texture = sfTexture_createFromFile("assets/UI/Popup.png");
	my_popup->string = string;
	my_popup->time = 0;
	my_popup->value = -249;
	my_popup->pause = pause;
	sfSprite_setTexture(my_popup->back, my_popup->texture);
	sfText_setColor(my_popup->text, sfWhite);
	sfText_setString(my_popup->text, string);
	sfText_setFont(my_popup->text, font);
	sfText_setCharacterSize(my_popup->text, FONT_SIZE);
	sfText_setPosition(my_popup->text, (sfVector2f){WIDTH - 600, -250});
	return (my_popup);
}

void popup_animate(sfRenderWindow *win, struct popup *pop)
{
	if (v < 0 && time < pop->pause) {
		v++;
	} else if (v == 0 && time < pop->pause) {
		time += 0.016;
	} else if (v > 250){
		v--;
	} else {
		return;
	}
	sfRenderWindow_drawSprite(win, pop->sprite, NULL);
	sfRenderWindow_drawText(win, pop->text, NULL);
	sfSprite_move(pop->sprite);
}

void popup_reset(struct popup *pop, char *string, int pause)
{
	if (string)
		pop->string = string;
	if (pause > 0)
		pop->pause = pause;
	pop->time = 0;
	pop->value = -249;
}

/*
int main(void) 
{
	
}
*/
