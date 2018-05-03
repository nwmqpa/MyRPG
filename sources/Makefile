##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=	..

SRC_DIR	=	.

CC		=	gcc

NAME	=	my_rpg

REAL	=	$(ROOT)/release

SRC	=	$(SRC_DIR)/cybend2200.c						\
		$(SRC_DIR)/animation/animation.c			\
		$(SRC_DIR)/animation/animation_extern.c		\
		$(SRC_DIR)/managers/assets_mng.c			\
		$(SRC_DIR)/managers/ress_mng.c				\
		$(SRC_DIR)/utils/get_struct.c				\
		$(SRC_DIR)/utils/vector2f.c					\
		$(SRC_DIR)/utils/utils.c					\
		$(SRC_DIR)/managers/cinematique_mng.c 		\
		$(SRC_DIR)/particle/particles.c 			\
		$(SRC_DIR)/particle/particles_2.c	 		\
		$(SRC_DIR)/particle/utils.c					\
		$(SRC_DIR)/map/map.c						\
		$(SRC_DIR)/inventory/management.c			\
		$(SRC_DIR)/inventory/mem_management.c 		\
		$(SRC_DIR)/inventory/sort.c					\
		$(SRC_DIR)/projectiles/management.c 		\
		$(SRC_DIR)/projectiles/mem_management.c		\
		$(SRC_DIR)/entity/management.c				\
		$(SRC_DIR)/update.c

WARN	=	-W -Wall -Wextra

CFLAGS	=	-I $(ROOT)/include $(WARN)

LDFLAGS	=	-L $(ROOT)/library -l c_graph_prog -l m

LIB	?=	1

TEST	?=	0

DEB	?=      0

G	=	-g

V	?=	@

OBJS	=	$(patsubst %.c, $(REAL)/%.o, $(SRC))

ifeq ($(DEB), 1)
	CFLAGS += $(G)
endif

ifeq ($(TEST), 1)
	CFLAGS	+= $(MACRO)
endif

#COLOR

GREEN	=	\e[1;32m

WHITE	=	\e[0m

ORANGE	=	\e[1;33m

RED		=	\e[1;35m

BLUE	=	\e[1;34m

all:			$(NAME)

$(NAME):	echo_build $(REAL)/$(NAME)
			$(V)cp $(REAL)/$(NAME) $(ROOT)
			$(V)printf "$(GREEN)Dup $(NAME) into root directory.$(WHITE)\n"


$(REAL)/$(NAME):	buildrepo $(OBJS)
			$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
			$(V)$(CC) -o $(REAL)/$(NAME) $(OBJS) $(LDFLAGS)
			$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(REAL)/%.o:		$(SRC_DIR)/%.c
			$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
			$(V)$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			$(V)rm -rf $(OBJS)
			$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean:			clean
			$(V)rm -f $(REAL)/$(NAME)
			$(V)rm -f $(ROOT)/$(NAME)
			$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

buildrepo:
			$(call make-repo)

re:			fclean
			$(V)make --no-print-directory all

echo_build:		echo_debug
			$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_debug:
			$(V)if [ $(DEB) == 1 ]; then\
				printf "$(RED)Debug mode initialized.$(WHITE)\n";\
			fi

.PHONY: clean fclean debug all re echo_build echo_debug buildrepo

define make-repo
	$(V)for dir in $(dir $(OBJS)); \
	do 			  \
		mkdir -p $$dir;	  \
	done
endef
