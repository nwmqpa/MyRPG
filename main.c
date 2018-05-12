
/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "my_rpg.h"

const int sizeroom = 21;

sfVector2f convert_i_t_v(int y, int x)
{
        sfVector2f pos;

        pos.x = x;
        pos.y = y;
        return (pos);
}

struct Hitbox	*add_hitbox(Hitbox_t *hitbox, sfVector2f newpoint)
{
	hitbox->point = malloc(sizeof(sfVector2f *) * 5);

	hitbox->point[0] = newpoint;
	hitbox->point[1].x = newpoint.x + 16;
	hitbox->point[1].y = newpoint.y;
	hitbox->point[2].x = newpoint.x;
	hitbox->point[2].y = newpoint.y + 16;
	hitbox->point[3].x = newpoint.x + 16;
	hitbox->point[3].y = newpoint.y + 16;
	return (hitbox);
}

int	**new_int_room()
{
	int i;
	int j;
	int **tmp = malloc(sizeof(int *) * (sizeroom + 1));
	float frequence;

        
	for (i = 0; i < sizeroom; i++) {
		tmp[i] = malloc(sizeof(int) * (sizeroom + 1));
		frequence = rand()%sizeroom;
		for (j = 0; j < sizeroom; j++){
			if (frequence + j % 5 == 3 && (i == 0 || i == sizeroom - 1) && (j != 0 && j != sizeroom - 1)) {
				tmp[i][j] = 7;
				frequence = rand()%sizeroom;
			} else if (frequence + j % 5 == 4 && (i == 0 || i == sizeroom - 1) && (j != 0 && j != sizeroom - 1)) {
				tmp[i][j] = 10;
				frequence = rand()%sizeroom;
			} else if (frequence + j % 5 <= 4 && (i != sizeroom - 1 && i != 0) && (j == 0 || j == sizeroom - 1)) {
				tmp[i][j] = 8;
				frequence = rand()%sizeroom;
			} else if (frequence + j % 5 == 3 && (i != sizeroom - 1 && i != 0) && (j == 0 || j == sizeroom - 1)) {
				tmp[i][j] = 11;
				frequence = rand()%sizeroom;
			} else if ((j == 0 || j == sizeroom - 1) && (i != 0 && i != sizeroom - 1)){
				tmp[i][j] = 4;
				frequence = rand()%sizeroom;
			} else if ((j != 0 && j != sizeroom - 1) && (i == 0 || i == sizeroom - 1)){
				tmp[i][j] = 4;
				frequence = rand()%sizeroom;
			} else
			{
				tmp[i][j] = 0;
				frequence = rand()%sizeroom;
			}
		}
		tmp[i][j] = -42;
	}
	tmp[i] = NULL;
	tmp[0][sizeroom - 1] = 5;
	tmp[sizeroom - 1][sizeroom - 1] = 5;
	tmp[sizeroom - 1][0] = 5;
	tmp[0][0] = 5;
	tmp[0][sizeroom / 2] = 6;
	tmp[sizeroom - 1][sizeroom / 2] = 6;
	tmp[sizeroom / 2][0] = 6;
	tmp[sizeroom / 2][sizeroom - 1] = 6;
	return (tmp);
}

sfSprite	**copy_all_sprite(int **room, int nbr)
{
	sfSprite **tmp = malloc(sizeof(sfSprite*)*(sizeroom*sizeroom + 10));
	int i;
	int j;
	int l = 0;
	
	for (i = 0; room[i]; i++) {
		for (j = 0; room[i][j] != -42; j++) { 
			if (room[i][j] == 1) {
				tmp[l] = sfSprite_copy(asset->sprites[0]);
				sfSprite_setPosition(tmp[l], convert_i_t_v(i * 16 + ((nbr/10) * 500), j* 16 + (nbr * 500)));
			} else if (room[i][j] == 0){
				tmp[l] = sfSprite_copy(asset->sprites[1]);
				sfSprite_setPosition(tmp[l], convert_i_t_v(i * 16 + ((nbr/10) * 500), j* 16 + (nbr * 500)));
			} else if (room[i][j] == 2){
				tmp[l] = sfSprite_copy(asset->sprites[4]);
				sfSprite_setPosition(tmp[l], convert_i_t_v(i * 16 + ((nbr/10) * 500), j* 16 + (nbr * 500)));
			}
			l++;
		}
	}
	tmp[l] = NULL;
	return(tmp);
}

struct Hitbox	**copy_all_hitbox(int *connection)
{
	struct Hitbox **tmp = malloc(sizeof(struct Hitbox*) * (sizeroom * sizeroom + 1));
	int i;
	int j;
	int l = 0;
	int origin = 500;
	
	for (i = 0; i < sizeroom; i++) {
		for (j = 0; j < sizeroom; j++) {
			tmp[l] = malloc(sizeof(struct Hitbox));
		        tmp[l] = add_hitbox(tmp[l], convert_i_t_v(origin + (connection[0] * 400) + (connection[2] * -400) + ((j % sizeroom - 1)* 16),
								  origin + (connection[1] * 400) + (connection[3] * -400) + ((i % sizeroom - 1)* 16)));
			l++;
		}
	}
	tmp[l] = NULL;
	return (tmp);
}

int	*FirstLevelConnection()
{
	int *tmp = malloc(sizeof(int) * 5);
	
	for (int i = 0; i < 4; i++)
		tmp[i] = 1;
	tmp[4] = -42;
	return (tmp);
}

sfSprite	*SelectSpriteDungeon(int id)
{
	switch (id) {
	case 4:
		return (asset->sprites[1]);
		break;
	case 5:
		return (asset->sprites[2]);
		break;
	case 6:
		return (asset->sprites[3]);
		break;
	case 7:
		return (asset->sprites[4]);
		break;
	case 8:
		return (asset->sprites[5]);
		break;
	case 10:
		return (asset->sprites[6]);
		break;
	}

	return (asset->sprites[7]);
}

sfVector2f	SelectVector2D(int origin, int *connection, int i)
{
	sfVector2f tmp;

	tmp.x = origin + (connection[0] * 400) + (connection[2] * -400) + ((i % sizeroom - 1)* 16);
	tmp.y = origin + (connection[3] * 400) + (connection[1] * -400) + ((i / sizeroom - 1)* 16);
	return (tmp);
}

float	SelectRotation(int **idRoom, int i)
{
	if ((i / sizeroom == 0 || i / sizeroom == sizeroom - 1) && idRoom[i / sizeroom][i % sizeroom] == 4)
		return (90);
	else if (i / sizeroom == 0 && i % sizeroom > 1 && idRoom[i / sizeroom][i % sizeroom] == 5)
		return (90);
	else if (i / sizeroom == sizeroom - 1 && i % sizeroom > 1 && idRoom[i / sizeroom][i % sizeroom] == 5)
		return (180);
	else if (i / sizeroom == sizeroom - 1 && i % sizeroom < 1 && idRoom[i / sizeroom][i % sizeroom] == 5)
		return (270);
	return (0);
}

sfSprite	**SetSpriteDungeonPosition(sfSprite **tmp, int **idRoom, int *connection)
{
	sfVector2f vectorOrigin = {.x = 8, .y = 8};
	int origin = 500;
	
	for (int i = 0; tmp[i]; i++) {
		sfSprite_setPosition(tmp[i], SelectVector2D(origin, connection, i));
		sfSprite_setOrigin(tmp[i], vectorOrigin);
		sfSprite_setRotation(tmp[i], SelectRotation(idRoom, i));
	}
	return (tmp);
}

sfSprite	**LoadSpritesRoom(int **idRoom, int *connection)
{
	sfSprite **tmp = malloc(sizeof(sfSprite *) * (sizeroom * sizeroom + 1));
	int l = 0;
	
	for (int i = 0; idRoom[i]; i++) {
		for (int j = 0; idRoom[i][j] != -42; j++)
			tmp[l++] = sfSprite_copy(SelectSpriteDungeon(idRoom[i][j]));
	}
	tmp[l] = NULL;
	return (SetSpriteDungeonPosition(tmp, idRoom, connection));
}


struct Room	*InitFirstLevel(struct Room *tmp)
{
	tmp = malloc(sizeof(*tmp));
	tmp->nbr = 0;
	tmp->room = new_int_room();
	tmp->connection = FirstLevelConnection();
	tmp->sprites = LoadSpritesRoom(tmp->room, tmp->connection);
	tmp->hitbox = copy_all_hitbox(tmp->connection);
	return (tmp);
}

int	checkConnection(int *it)
{
	if (it[0] > it[1] && it[0] > it[2] && it[0] > it[3])
		return (0);
	else if (it[1] > it[2] && it[1] > it[0] && it[1] > it[3])
		return (1);
	else if (it[2] > it[1] && it[2] > it[3] && it[2] > it[0])
		return (2);
	if (it[3] > it[1] && it[3] > it[2] && it[3] > it[0])
		return (3);
	else if (it[0] == it[1] && it[0] == it[2] && it[0] == it[3])
		return (-1);
	return (-84);
}


int	*OtherLevelConnection(int *lastConnection)
{
	int rnd = 0;
	int *tmp = malloc(sizeof(int) * 5);
	int byPassDir = checkConnection(lastConnection);

	if (byPassDir == -1) {
		rnd = rand()%4;
		for (int i = 0; i < 4; i++)
			if (i == rnd)
				tmp[i] = lastConnection[i] + 1;
			else
				tmp[i] = lastConnection[i];
	} else
		for (int i = 0; i < 4; i++)
			tmp[i] = byPassDir == i || rnd == 1 ? lastConnection[i] : lastConnection[i] + (rnd = rand()%2);
	tmp[4] = -42;
	return (tmp);
}



struct Room	*OtherLevel(struct Room *tmp, struct Room *last)
{
	tmp = malloc(sizeof(*tmp));
	tmp->nbr = last->nbr + 1;
	tmp->room = new_int_room();
	tmp->connection = OtherLevelConnection(last->connection);
	tmp->sprites = LoadSpritesRoom(tmp->room, tmp->connection);
	tmp->hitbox = copy_all_hitbox(tmp->connection);
	return (tmp);
}

struct Room	**ProceduralGeneration(int nbrRoom)
{
	struct Room **tmp = malloc(sizeof(struct Room *) * (nbrRoom + 1));
	int i;
	
	for (i = 0; i < nbrRoom; i++) {
		if (i == 0)
			tmp[i] = InitFirstLevel(tmp[i]);
		else
			tmp[i] = OtherLevel(tmp[i], tmp[i - 1]);
	}
	tmp[i] = NULL;
	return (tmp);
}


struct Dungeon	*generate_dungeon(int nbrRoom)
{
	struct Dungeon *tmp = malloc(sizeof(*tmp));

	tmp->nbrRoom = nbrRoom;
	tmp->connection = ProceduralGeneration(tmp->nbrRoom);
	return (tmp);
}

int *init_pos(int x,int y, int width, int height)
{
        int *pos = malloc(sizeof(int) * 4);

        pos[0] = x;
        pos[1] = y;
        pos[2] = height;
        pos[3] = width;
        return (pos);
}


sfIntRect Dest_Rect(int left, int top, int width, int height)
{
        sfIntRect rd;
	
        rd.left = left;
        rd.top = top;
        rd.width = width;
        rd.height = height;
        return (rd);
}

sfSprite *load_texture(char *name, int *pos)
{
        sfSprite *sprite = sfSprite_create();
        sfTexture *texture = sfTexture_createFromFile(name, NULL);
        sfVector2f ps;

        ps.x = pos[0];
        ps.y = pos[1];
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, Dest_Rect(0, 0, pos[3], pos[2]));
        sfSprite_setPosition(sprite, ps);
        return (sprite);
}

int	display_help()
{
	my_putstr("for use my_rpg ./mw MAPY MAPX SCALINGX SCALINGY ");
	my_putstr("SCALINGZ\n");
	return (84);
}

sfTexture	**load_all_textures()
{
	sfTexture **tmp = malloc(sizeof(sfTexture *) * 4);

	tmp[0] = sfTexture_createFromFile("src/sprite/grass_f.png", NULL);
	tmp[1] = sfTexture_createFromFile("src/sprite/sand_t.png", NULL);
	tmp[2] = sfTexture_createFromFile("src/sprite/water.png", NULL);
	tmp[3] = NULL;
	return (tmp);
}

sfSprite	**load_all_sprites()
{
	sfSprite **tmp = malloc(sizeof(sfSprite *) * 9);

	tmp[0] = load_texture("src/sprite/player_t.png", init_pos(600, 600, 16, 16));
	tmp[1] = load_texture("src/sprite/wall.png", init_pos(0, 0, 16, 16));
	tmp[2] = load_texture("src/sprite/wall_a.png", init_pos(0, 0, 16, 16));
	tmp[3] = load_texture("src/sprite/door.png", init_pos(0, 0, 16, 32));
	tmp[4] = load_texture("src/sprite/wall.png", init_pos(0, 0, 16, 16));
	tmp[5] = load_texture("src/sprite/wall.png", init_pos(0, 0, 16, 16));
	tmp[6] = load_texture("src/sprite/wall.png", init_pos(0, 0, 16, 16));
	tmp[7] = load_texture("src/sprite/floor_1.png", init_pos(0, 0, 16, 16));
	tmp[8] = NULL;
	return (tmp);
}

sfSound	**load_all_sounds()
{
	sfSound **tmp = malloc(sizeof(sfSound *) * 4);

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = NULL;
	return (tmp);
}

sfMusic	**load_all_musics()
{
	sfMusic **tmp = malloc(sizeof(sfMusic *) * 4);

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	tmp[3] = NULL;
	return (tmp);
}

Asset_mg_t	*load_all_asset() {
	Asset_mg_t *tmp = malloc(sizeof(*tmp));

	tmp->textures = load_all_textures();
	tmp->sprites = load_all_sprites();
	tmp->sounds = load_all_sounds();
	tmp->musics = load_all_musics();
	return (tmp);
}
Plogic_t	*SetupCursorLogic()
{
	Plogic_t *tmp = malloc(sizeof(*tmp));
	tmp->name = malloc(sizeof(char *) * 3);
	tmp->id = malloc(sizeof(int) * 4);

	tmp->name[0] = my_strdup("Main Menu");
	tmp->name[1] = my_strdup("Game");
	tmp->name[2] = NULL;
	
	tmp->id[0] = 0;
	tmp->id[1] = 1;
	tmp->id[2] = 1;
	tmp->id[3] = -42;
	return (tmp);
}

Logic_t	**ManagerAddLogics()
{
	int i;
	Logic_t **tmp = malloc(sizeof(Logic_t *) * 4);
	Plogic_t *ptmp = SetupCursorLogic();

	for (i = 0; i < 3; i++) {
		tmp[i] = malloc(sizeof(Logic_t));
		tmp[i]->plogic_cursor = ptmp;
		tmp[i]->init = 0;
		tmp[i]->scene_view = NULL;
		tmp[i]->entity_manager = NULL;
	}
	tmp[i] = NULL;
	return (tmp);
}

Player_t	*init_player_game()
{
	Player_t *tmp = malloc(sizeof(Player_t));
	tmp->sprite = sfSprite_copy(asset->sprites[0]);
	tmp->room = 0;
	tmp->s_player.name = "Stolym";
	tmp->s_player.heatlh = 20;
	tmp->s_player.stamina = 20;
	tmp->s_player.power = 0;
	tmp->i_sprite.x = 600;
	tmp->i_sprite.y = 600;
	tmp->i_sprite.width = 16;
	tmp->i_sprite.height = 16;
	tmp->i_sprite.left = 0;
	tmp->i_sprite.top = 0;
	//tmp->hitbox = add_hitbox(tmp->hitbox, convert_i_t_v(tmp->i_sprite.y, tmp->i_sprite.x));
	return (tmp);
}

Logic_t	*init_game_logic(Logic_t *current_logic)
{
	current_logic->entity_manager = malloc(sizeof(AllEntity_t));
	current_logic->entity_manager->entity = NULL;
	current_logic->entity_manager->player = init_player_game();
	current_logic->dungeon = generate_dungeon(10);
	current_logic->init = 1;
	return (current_logic);
}

Logic_t	*init_logic(Logic_t *current_logic)
{
	switch (current_logic->plogic_cursor->id[2]) {
	case 0:
		break;
	case 1:
		current_logic = init_game_logic(current_logic);
		break;
	default:
		break;
	}
	return (current_logic);
}


sfVector2f get_pos_mouse(sfRenderWindow *window, int sub)
{
        sfVector2i pos = sfMouse_getPosition(window);
        sfVector2f move;

        move.x = pos.x - sub;
        move.y = pos.y - sub;
        return (move);
}

const float PI = 3.14159265;

Player_t	*logic_player_game(Player_t *current_player,
	sfRenderWindow *window)
{
	sfVector2f newOrigin = {.x = 8, .y = 8};
	sfVector2f MouseGet = get_pos_mouse(window, 0);
	sfVector2f PlayerGet = {.x=current_player->i_sprite.x,
				.y=current_player->i_sprite.y};

	float dx = PlayerGet.x - MouseGet.x;
	float dy = PlayerGet.y - MouseGet.y;
	float rotate = (atan2(dy, dx)) * 180 / PI;

	sfSprite_setOrigin(current_player->sprite, newOrigin);
	sfSprite_setRotation(current_player->sprite, rotate);
	
	return (current_player);
}


int	check_hitbox(Logic_t *current, int dir)
{
	int confirm = 1;
	int ypos = current->entity_manager->player->i_sprite.y;
	int xpos = current->entity_manager->player->i_sprite.x;


	for (int i = 0; current->dungeon->connection[i]; i++) {
		for (int j = 0; current->dungeon->connection[i]->hitbox[j]; j++) {
			if (xpos + 16 > current->dungeon->connection[i]->hitbox[j]->point[0].x &&
			    ypos > current->dungeon->connection[i]->hitbox[j]->point[0].y &&
			    xpos + 15 < current->dungeon->connection[i]->hitbox[j]->point[3].x &&
			    ypos + 1 < current->dungeon->connection[i]->hitbox[j]->point[3].y &&
			    current->dungeon->connection[i]->room[j / sizeroom][j % sizeroom] == 4)
				current->entity_manager->player->i_sprite.x--;
			else if (xpos + 2 > current->dungeon->connection[i]->hitbox[j]->point[1].x &&
				 ypos + 2 > current->dungeon->connection[i]->hitbox[j]->point[1].y &&
				 xpos < current->dungeon->connection[i]->hitbox[j]->point[3].x &&
				 ypos < current->dungeon->connection[i]->hitbox[j]->point[3].y &&
				 current->dungeon->connection[i]->room[j / sizeroom][j % sizeroom] == 4)
				current->entity_manager->player->i_sprite.x++;
			else if (xpos > current->dungeon->connection[i]->hitbox[j]->point[0].x &&
				 ypos > current->dungeon->connection[i]->hitbox[j]->point[0].y &&
				 xpos < current->dungeon->connection[i]->hitbox[j]->point[3].x &&
				 ypos < current->dungeon->connection[i]->hitbox[j]->point[3].y &&
				 current->dungeon->connection[i]->room[j / sizeroom][j % sizeroom] == 4)
				current->entity_manager->player->i_sprite.y++;
			else if (xpos> current->dungeon->connection[i]->hitbox[j]->point[0].x &&
				 ypos + 16 > current->dungeon->connection[i]->hitbox[j]->point[0].y &&
				 xpos < current->dungeon->connection[i]->hitbox[j]->point[3].x &&
				 ypos + 15 < current->dungeon->connection[i]->hitbox[j]->point[3].y &&
				 current->dungeon->connection[i]->room[j / sizeroom][j % sizeroom] == 4)
				current->entity_manager->player->i_sprite.y--;			
			if (xpos > current->dungeon->connection[i]->hitbox[j]->point[0].x &&
			    ypos > current->dungeon->connection[i]->hitbox[j]->point[0].y &&
			    xpos < current->dungeon->connection[i]->hitbox[j]->point[3].x &&
			    ypos < current->dungeon->connection[i]->hitbox[j]->point[3].y &&
			    current->dungeon->connection[i]->room[j / sizeroom][j % sizeroom] == 6) {
				if (j / sizeroom == sizeroom - 1 && j % sizeroom == sizeroom / 2)
					current->entity_manager->player->i_sprite.x += 100;
				else if (j / sizeroom == 0 && j % sizeroom == sizeroom / 2)
					 current->entity_manager->player->i_sprite.x -= 100;
				else if (j / sizeroom == 0 && j % sizeroom == sizeroom / 2)
					current->entity_manager->player->i_sprite.y -= 100;
				else if (j / sizeroom - 1 == sizeroom && j % sizeroom == sizeroom / 2)
					current->entity_manager->player->i_sprite.y += 100;
			}
		}
	}
	
	
	return (confirm);
}


Logic_t	*keyboard_manager(sfRenderWindow *window, Logic_t *current)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		if (check_hitbox(current, 1)) {
         current->entity_manager->player->i_sprite.y--;
	 sfSprite_setPosition(current->entity_manager->player->sprite,
	      convert_i_t_v(current->entity_manager->player->i_sprite.y,
			    current->entity_manager->player->i_sprite.x));
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyS)) {
		
		if (check_hitbox(current, 3)) {
         current->entity_manager->player->i_sprite.y++;
	 sfSprite_setPosition(current->entity_manager->player->sprite,
	      convert_i_t_v(current->entity_manager->player->i_sprite.y,
			    current->entity_manager->player->i_sprite.x));
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		
		if (check_hitbox(current, 2)) {
         current->entity_manager->player->i_sprite.x--;
	 sfSprite_setPosition(current->entity_manager->player->sprite,
	      convert_i_t_v(current->entity_manager->player->i_sprite.y,
			    current->entity_manager->player->i_sprite.x));
		}
	}
	if (sfKeyboard_isKeyPressed(sfKeyD)) {
		if (check_hitbox(current, 0)) {
         current->entity_manager->player->i_sprite.x++;
	 sfSprite_setPosition(current->entity_manager->player->sprite,
	      convert_i_t_v(current->entity_manager->player->i_sprite.y,
			    current->entity_manager->player->i_sprite.x));
		}
	}
	return (current);
}

sfVector2f	SelectNewMove(Entity_t *entity)
{
	sfVector2f tmp;
	float speed = 1;
	
	tmp.x=cos(sfSprite_getRotation(entity->sprite)*M_PI/180) * speed;
	tmp.y=-sin(sfSprite_getRotation(entity->sprite)*M_PI/180) * speed;
	return (tmp);
}

void	DrawEntity(Entity_t **entity, sfRenderWindow *window)
{
	if (entity != NULL) {
		for (int i = 0; entity[i] != NULL; i++) {
			sfSprite_move(entity[i]->sprite, SelectNewMove(entity[i]));
			sfRenderWindow_drawSprite(window, entity[i]->sprite,NULL);
		}
	}
}

Entity_t	**FirstEntity(int id_object)
{
	Entity_t **tmp = malloc(sizeof(Entity_t *) * 2);

	tmp[0] = malloc(sizeof(*tmp[0]));
	//tmp[0]->name = SetNameById(id_object);
	tmp[0]->layer = 1;
	tmp[0]->number = id_object;
	tmp[0]->sprite = sfSprite_copy(asset->sprites[id_object]);
	tmp[0]->i_sprite.x = 0;
	tmp[0]->i_sprite.y = 0;
	tmp[1] = NULL;
	return (tmp);
}

void	AddEntity(AllEntity_t *current_entity, int id_object, sfRenderWindow *window, Player_t *current_player)
{
	if (current_entity->entity == NULL) {
		current_entity->entity = FirstEntity(id_object);
        }
}

void	DungeonDraw(sfRenderWindow *window, struct Dungeon *dungeon)
{
	for (int j = 0; dungeon->connection[j]; j++)
		for (int i = 0; dungeon->connection[j]->sprites[i]; i++)
			sfRenderWindow_drawSprite(window, dungeon->connection[j]->sprites[i], NULL);
}

Logic_t	*game_loop(Logic_t *current_logic, Logic_t **logics,
	sfRenderWindow *window)
{
	if (sfRenderWindow_pollEvent(window, &current_logic->event)) {
		if (current_logic->event.type == sfEvtClosed)
			sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
	current_logic = keyboard_manager(window, current_logic);
	current_logic->entity_manager->player =
		logic_player_game(current_logic->entity_manager->player, window);
	DungeonDraw(window, current_logic->dungeon);
	sfRenderWindow_drawSprite(window, current_logic->entity_manager->player->sprite, NULL);
	sfRenderWindow_display(window);
	return (current_logic);
}

Logic_t	*LogicManager(Logic_t *current_logic, Logic_t **logics,
	sfRenderWindow *window)
{
	if (current_logic->init == 0)
		current_logic = init_logic(current_logic);
	else {
		current_logic = game_loop(current_logic, logics, window);
	}
	return (current_logic);
}

int	window_manager()
{
	Logic_t **logics = ManagerAddLogics();
	Logic_t *current_logic = logics[1];
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "MY_RPG",
			       sfResize | sfClose, NULL);	

	asset = load_all_asset();
	while (sfRenderWindow_isOpen(window)) {
		current_logic = LogicManager(current_logic, logics,
					     window);
	}
	sfRenderWindow_destroy(window);
	return (1);
}

int	main(int ac, char **av)
{
	srand(time(NULL));
	return (window_manager());
}
