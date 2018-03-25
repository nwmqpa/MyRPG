/*
** EPITECH PROJECT, 2017
** sources/main.c
** File description:
** Main file
*/

#include "name.h"

static int inventory(game_t *game_struct)
{
	int code = 0;

	code = code ? code : print_background_inventory(game_struct);
	code = code ? code : print_inventory_slots(game_struct);
	code = code ? code : print_inventory_items(game_struct);
	code = code ? code : print_inventory_stats(game_struct);
	return (code);
}

static int dialogue(game_t *game_struct)
{
	int code = 0;

	code = code ? code : print_selfs_dialogue_mode(game_struct);
	code = code ? code : print_others_dialogue_mode(game_struct);
	code = code ? code : print_actual_dialogue(game_struct);
	return (code);
}

static int overworld_mode(game_t *game_struct)
{
	int code = 0;

	code = code ? code : print_overworld_background(game_struct);
	code = code ? code : print_overworld_entities(game_struct);
	if (!(game_struct->gamemode & (INVENTORY | DIALOGUE))) {
		code = code ? code : print_overworld_ui(game_struct);
		code = code ? code : does_player_turn(game_struct);
		code = code ? code : does_ai_turn(game_struct);
	}
	return (code);
}

static int combat_mode(game_t *game_struct)
{
	int code = 0;

	code = code ? code : print_combat_background(game_struct);
	code = code ? code : print_combat_entities(game_struct);
	if (!(game_struct->gamemode & (INVENTORY | DIALOGUE))) {
		code = code ? code : print_combat_ui(game_struct);
		code = code ? code : does_player_turn(game_struct);
		code = code ? code : does_ai_turn(game_struct);
	}
	return (code);
}

static int game_loop(game_t *game_struct)
{
	int code = 0;

	while (game_struct->is_in_world && !code) {
		if ((game_struct->gamemode & 0b11) == COMBAT)
			code = code ? code : combat_mode(game_struct);
		else if (game_struct->gamemode & 0b11 == OVERWORLD)
			code = code ? code : overworld_mode(game_struct);
		if (game_struct->gamemode & 0b100 == DIALOGUE)
			code = code ? code : dialogue(game_struct);
		if (game_struct->gamemode & 0b1000 == INVENTORY)
			code = code ? code : inventory(game_struct);
		get_events(game_struct);
	}
	return (code);
}

int main()
{
	game_t *game_struct = 0x0;
	int code = 0;

	code = code ? code : init_game_struct(&game_struct);
	code = code ? code : parse_instances(&(game_struct->instances), instances_paths);
	code = code ? code : create_overworld(game_struct->instances, game_instance->seed);
	code = code ? code : create_key_npcs(&(game_struct->npcs), npc_script_paths);
	code = code ? code : create_random_npcs(&(game_struct->npcs));
	while (game_struct->in_menu)
		code = code ? code : game_loop(game_struct);
	code = code ? code : free_instances(game_struct->instances);
	code = code ? code : free_npcs(game_struct->npcs);
	code = code ? code : free_game_struct(game_struct);
	return (error_handling(code, game_struct));
}
