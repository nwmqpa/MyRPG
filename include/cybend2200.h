/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>

#define NAME "Cybend2200"

#define Y 1
#define X 0
#define WIDTH   1920
#define HEIGHT  1080
#define MAX_FPS 30
#define FLAGS (sfClose)

enum gamemode {
	MENU,
	GAME,
	FIGHT,
	DIALOG,
	CINEMATIQUE
};

enum ui {
	DIALOG_UI,
	POPUP_UI
};

enum menus {
	NOTHING,
	INVENTORY_PLAYER,
	CONTAINER,
	ESCAPE
};

typedef struct game game_t;

#include "objects.h"

/*
** Game:
** 	Main game structure that represent game state and
** 	game datas inside all the game.
*/
struct game {
	int ui[2];
	int size[2];
	int gamemode;
	int menu_type;
	item_t handed;
	float delta_time;
	struct popup *popup;
	struct dialog *dialog;
	struct map *actual_map;
	struct inventory *container;
	sfRenderWindow *win;
	sfEvent event;
	sfVector2f delta_pos;
	sfVector2f handed_pos;
};


int my_rpg(game_t *game);
int update_game(game_t *game);
int game_loop(game_t *game);
int draw_menu(game_t *game);
int draw_game(game_t *game);
int draw_combat(game_t *game);

#endif /* MY_RPG_H_ */
