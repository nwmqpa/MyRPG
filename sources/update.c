/*
** EPITECH PROJECT, 2017
** update.c
** File description:
** update file for game
*/

#include "cybend2200.h"
#include "utils.h"
#include "map_parser.h"
#include "ress_manager.h"
#include "entities.h"

int draw_menu(UNUSED game_t *game)
{
    //Draw game menu
    return (0);
}

int draw_game(UNUSED game_t *game)
{
    draw_map(game);
    draw_player(game->win, get_ressources(NULL)->player);
    //draw_player();
    return (0);
}

int draw_combat(UNUSED game_t *game)
{
    //Draw combat phase
    return (0);
}

