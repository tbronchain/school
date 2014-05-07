CC		=	gcc
NAME		=	wolf3d
SRC		=	./main.c			\
			./lib.c				\
			./lib2.c			\
			./x_fonctions.c			\
			./my_getnbr_base.c		\
			./free.c			\
			./init.c			\
			./gere_keys.c			\
			./my_put_nbr.c			\
			./calc.c			\
			./make_rotate.c			\
			./search_key_down.c		\
			./search_key_up.c		\
			./search_keys.c			\
			./make_move.c			\
			./first_img.c			\
			./my_pixel_put_to_image.c
OBJ		=	$(SRC:.c=.o)
INCLUDE		=	-I.
CFLAGS		=	-W -Wall -ansi -pedantic -Werror
RM		=	rm -f
BEGIN_COMPIL	=	@echo " Compilation launched."
END_COMPIL	=	@echo " Compilation ended."
BEGIN_CLEAN	=	@echo " Clean launched."
END_CLEAN	=	@echo " Clean ended."
BEGIN_SAVE	=	@echo " Save launched."
END_SAVE	=	@echo " Save ended."
SAVE_NAME	=	save_wolf3d.tar.gz
SAVE_INC_NAME	=	wolf3d.h
SAVE		=	tar cfz $(SAVE_NAME) Makefile $(SAVE_INC_NAME) $(SRC)
MINILIBX	=	-L./minilibx -lmlx -lX11 -lXext
LIBMATHS	=	-lm

$(NAME): 	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(MINILIBX) $(LIBMATHS)

all:		$(NAME)

end_compil:
		@echo -e "\033[1;35m"
		$(END_COMPIL)
		@echo -e "\033[00m"
		@echo ""

echo_name:
		@echo -e "\033[1;32m"
		@echo ""
		@echo "  __      __      .__   _____  ________ ________    "
		@echo " /  \    /  \____ |  |_/ ____\ \_____  \\\______ \   "
		@echo " \   \/\/   /  _ \|  |\   __\    _(__  < |    |  \  "
		@echo "  \        (  <_> )  |_|  |     /       \|    \`   \ "
		@echo "   \__/\  / \____/|____/__|    /______  /_______  / "
		@echo "        \/                            \/        \/  "
		@echo -e "\033[1;33m"

begin_compil:
		@echo ""
		@echo -e "\033[1;35m"
		$(BEGIN_COMPIL)
		@echo -e "\033[1;33m"

save:
		@echo -e "\033[1;35m"
		$(BEGIN_SAVE)
		@echo -e "\033[1;33m"

		$(RM) $(SAVE_NAME)
		$(SAVE)

		@echo -e "\033[1;35m"
		$(END_SAVE)
		@echo -e "\033[00m"

clean:
		@echo ""
		@echo -e "\033[1;35m"
		$(BEGIN_CLEAN)
		@echo -e "\033[1;33m"

		$(RM) *~
		$(RM) $(OBJ)

		@echo -e "\033[1;35m"
		$(END_CLEAN)
		@echo -e "\033[00m"

fclean:
		@echo ""
		@echo -e "\033[1;35m"
		$(BEGIN_CLEAN)
		@echo -e "\033[1;33m"

		$(RM) *~
		$(RM) $(OBJ)

		@echo -e "\033[1;35m"
		$(END_CLEAN)
		@echo -e "\033[1;33m"

		$(RM) $(NAME)

		@echo -e "\033[1;35m"
		@echo " Old binary deleted."
		@echo -e "\033[00m"

end:
		@echo -e "\033[1;32m"
		@echo " Installation successful."
		@echo -e "\033[00m"

re: 		echo_name fclean begin_compil all end_compil save end

.PHONY:		all clean re echo_name begin_compil end_compil save end
