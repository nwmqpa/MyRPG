
SRC_DIR	=	./src

INC	=	./inc

CC	=	gcc

SRC	=	$(SRC_DIR)/main.c	\
		$(SRC_DIR)/particles.c	\
		$(SRC_DIR)/utils.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-I $(INC) -Wall -Wextra

LD_FLAGS=	-l c_graph_prog -l m

NAME 	?=	particle

debug:		CFLAGS += -g

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $@ $(OBJS) $(LD_FLAGS)

debug:		fclean $(call deb_print) $(NAME)

%.o:		%.c
		@printf "$< => $@\n"
		@$(CC) -o $@ -c $< $(CFLAGS) $(LD_FLAGS)

clean:
		@rm -rf $(OBJS)

fclean:		clean
		@rm -rf $(NAME)
	
re:		fclean all

.PHONY: clean all fclean re

define deb_print
	@printf "DEBUG MODE"
endef
