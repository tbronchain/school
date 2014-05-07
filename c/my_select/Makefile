CC		=	gcc
NAME		=	my_select
SRC		=	./main.c		\
			./x_fonctions.c		\
			./x_fonctions_2.c	\
			./lib.c			\
			./lib2.c		\
			./my_put_nbr.c		\
			./canon.c		\
			./xtgetstr.c		\
			./find.c		\
			./my_strcpy.c		\
			./exit.c		\
			./delete.c		\
			./check.c		\
			./display.c		\
			./check_ctrl.c		\
			./my_strcmp.c
OBJ		=	$(SRC:.c=.o)
INCLUDE		=	-I.
CFLAGS		=	-W -Wall -ansi -pedantic
RM		=	rm -f
BEGIN_COMPIL	=	@echo " Compilation launched."
END_COMPIL	=	@echo " Compilation ended."
BEGIN_CLEAN	=	@echo " Clean launched."
END_CLEAN	=	@echo " Clean ended."
BEGIN_SAVE	=	@echo " Save launched."
END_SAVE	=	@echo " Save ended."
SAVE		=	tar cfz save_my_select.tar.gz Makefile my_select.h $(SRC)
TERMCAP		=	-ltermcap
LDFLAGS		=	-L/usr/pkg/lib -lefence

$(NAME): 	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(TERMCAP) $(LDFLAGS)

all:		$(NAME)

end_compil:
		@echo -e "\033[1;35m"
		$(END_COMPIL)
		@echo -e "\033[00m"
		@echo ""

echo_name:
		@echo -e "\033[1;32m"
		@echo ""
		@echo "  ______                   _          _                 "
		@echo " |  ___ \                 | |        | |           _    "
		@echo " | | _ | |_   _            \ \   ____| | ____ ____| |_  "
		@echo " | || || | | | |            \ \ / _  ) |/ _  ) ___)  _) "
		@echo " | || || | |_| |_______ _____) | (/ /| ( (/ ( (___| |__ "
		@echo " |_||_||_|\__  (_______|______/ \____)_|\____)____)\___)"
		@echo "         (____/                                         "
		@echo ""
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
