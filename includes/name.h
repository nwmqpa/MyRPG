/*
** EPITECH PROJECT, 2017
** name.c
** File description:
** Name
*/

#ifndef NAME_H_
#define NAME_H_

#ifndef GAME_NAME
#define NAME "Unammed"
#endif /* GAME_NAME */

#define Y 1
#define X 0

/*
** Game: 
** 	Main game structure that represent game state and
** 	game datas inside all the game.
*/
typedef struct game_s {
	int gamemode;
	float delta_time;
	int size[2];
} game_t;

#endif /* NAME_H_ */
