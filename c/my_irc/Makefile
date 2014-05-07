CC		=	gcc

NAME1		=	client
NAME2		=	serveur

DIR1		=	src_client/
DIR2		=	src_serveur/

SRC1		=	$(DIR1)com_serv.c		\
			$(DIR1)connect_to_serv.c	\
			$(DIR1)disconnect.c		\
			$(DIR1)gere_cmd.c		\
			$(DIR1)gtk.c			\
			$(DIR1)init_client.c		\
			$(DIR1)main.c			\
			$(DIR1)str_to_wordtab.c		\
			$(DIR1)utils.c			\
			$(DIR1)x.c

SRC2		=	$(DIR2)channel.c		\
			$(DIR2)client_read.c		\
			$(DIR2)cmd_serv.c		\
			$(DIR2)cmd_serv2.c		\
			$(DIR2)free.c			\
			$(DIR2)init.c			\
			$(DIR2)lib.c			\
			$(DIR2)list.c			\
			$(DIR2)main.c			\
			$(DIR2)send.c			\
			$(DIR2)x.c

INCLUDE		=	./includes/ `pkg-config --cflags gtk+-2.0`
CFLAGS 		+=	-W -Wall -ansi -pedantic -O2 -o $@ -I$(INCLUDE)

OBJ1		=	$(SRC1:.c=.o)
OBJ2		=	$(SRC2:.c=.o)

RM		=	rm -rf
CLEAN		=	rm -rf `find . \( -name '*~' -or -name '.*~' -or -name '.\#*\#' -or -name '\#*\#' \)`

LDFLAGS_GTK	=	`pkg-config --libs gtk+-2.0`


$(NAME1):	$(OBJ1)
		@echo ""
		@echo -n "Compilating objects files ("
		@echo -n $(NAME1)
		@echo ")..."
		$(CC) -o $(NAME1) -I$(INCLUDE) $(OBJ1) $(LDFLAGS_GTK)
		@echo ""

$(NAME2):	$(OBJ2)
		@echo ""
		@echo -n "Compilating objects files ("
		@echo -n $(NAME2)
		@echo ")..."
		$(CC) -o $(NAME2) -I$(INCLUDE) $(OBJ2)
		@echo ""

all:		$(NAME1) $(NAME2)

clean:
		@echo "Removing temporary files..."
		$(CLEAN)
		$(RM) $(OBJ1) $(OBJ2)
		@echo ""

fclean:		clean
		@echo "Removing old binary..."
		$(RM) $(NAME1) $(NAME2)
		@echo ""

save:
		@echo "Saving sources..."
		mkdir -p bkp
		tar cfj bkp/save_$(NAME1).bz2 $(DIR1) includes Makefile
		tar cfj bkp/save_$(NAME2).bz2 $(DIR2) includes Makefile
		@echo ""

re:		fclean all save

.PHONY:		all clean fclean save re $(NAME1) $(NAME2)
