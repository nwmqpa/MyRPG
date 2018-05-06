/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#define NAME "Cybend2200"

#define Y 1
#define X 0
#define WIDTH   1920
#define HEIGHT  1080
#define MAX_FPS 30

#include <SFML/Graphics.h>

enum gamemode {
	MENU,
	GAME,
	FIGHT,
	DIALOG
};

/*
** Game: 
** 	Main game structure that represent game state and
** 	game datas inside all the game.
*/
typedef struct game_s {
	sfRenderWindow *win;
	int gamemode;
	struct map *actual_map;
	sfEvent event;
	float delta_time;
	int size[2];
} game_t;

void draw_dialog(game_t *game);
int my_rpg(game_t *game);
int update_game(game_t *game);
int game_loop(game_t *game);
int draw_menu(game_t *game);
int draw_game(game_t *game);
int draw_combat(game_t *game);

#endif /* MY_RPG_H_ */