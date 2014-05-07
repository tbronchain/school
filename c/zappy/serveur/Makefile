CC		=	gcc

NAME		=	serveur

DIR		=	src/

SRC		=	$(DIR)actions_graph/actions_graph1.c		\
			$(DIR)actions_graph/actions_graph2.c		\
			$(DIR)actions_graph/actions_graph3.c		\
			$(DIR)actions_graph/actions_graph4.c		\
			$(DIR)actions_graph/check_action_graph.c	\
			$(DIR)actions_graph/event_actions.c		\
			$(DIR)actions_graph/event_actions2.c		\
			$(DIR)actions_graph/init_graphic.c		\
			$(DIR)actions_ia/actions_ia.c			\
			$(DIR)actions_ia/actions_ia_2.c			\
			$(DIR)actions_ia/broadcast.c			\
			$(DIR)actions_ia/utils_ia.c			\
			$(DIR)actions_ia/fork_ia.c			\
			$(DIR)actions_ia/view_ia.c			\
			$(DIR)actions_ia/incant_ia.c			\
			$(DIR)actions_ia/get-put_ia.c			\
			$(DIR)actions_ia/coord_ia.c			\
			$(DIR)actions_ia/check_action_ia.c		\
			$(DIR)actions_ia/init_ia.c			\
			$(DIR)transfer/funct_write.c			\
			$(DIR)transfer/recv.c				\
			$(DIR)transfer/send.c				\
			$(DIR)utils/ban.c				\
			$(DIR)utils/cbuf.c				\
			$(DIR)utils/check_team.c			\
			$(DIR)utils/free.c				\
			$(DIR)utils/kick.c				\
			$(DIR)utils/lib.c				\
			$(DIR)utils/list.c				\
			$(DIR)utils/list_buf.c				\
			$(DIR)utils/timeout.c				\
			$(DIR)utils/x.c					\
			$(DIR)accept_client.c				\
			$(DIR)init.c					\
			$(DIR)loop.c					\
			$(DIR)ressource.c				\
			$(DIR)main.c					\
			$(DIR)parse_opt.c

INCLUDE		=	./includes/
CFLAGS 		+=	-O2 -W -Wall -ansi -pedantic -I$(INCLUDE)
LDFLAGS		+=	-lm

OBJ		=	$(SRC:.c=.o)

RM		=	rm -rf
CLEAN		=	rm -rf `find . \( -name '*~' -or -name '.*~' -or -name '.\#*\#' -or -name '\#*\#' \)`


$(NAME):	$(OBJ)
		@echo ""
		@echo -n "Compilating objects files for "
		@echo -n $(NAME)
		@echo "..."
		$(CC) -o $(NAME) -I$(INCLUDE) $(OBJ) $(LDFLAGS)
		@echo ""

all:		$(NAME)

clean:
		@echo "Removing temporary files..."
		$(CLEAN)
		$(RM) $(OBJ)
		@echo ""

fclean:		clean
		@echo "Removing old binary..."
		$(RM) $(NAME)
		@echo ""

save:
		@echo "Saving sources..."
		mkdir -p bkp
		tar cfj bkp/save_$(NAME).bz2 $(DIR) $(INCLUDE) Makefile
		@echo ""

re:		fclean all save

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all clean fclean save re $(NAME)
