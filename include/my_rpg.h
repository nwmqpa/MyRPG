/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
** my_rpg.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#define NAME "Unammed"

#define Y 1
#define X 0
#define WIDTH   1920
#define HEIGHT  1080
#define MAX_FPS 30

#include <SFML/Graphics.h>

enum gamemode {
	OVERWORLD,
	INSTANCE,
	DONJON
};

/*
** Game: 
** 	Main game structure that represent game state and
** 	game datas inside all the game.
*/
typedef struct game_s {
	sfRenderWindow *win;
	int gamemode;
	float delta_time;
	int size[2];
} game_t;

int my_rpg(game_t *game);

#endif /* MY_RPG_H_ */