##
## Makefile for malloc in /u/all/nougar_m/cu/rendu/proj/malloc
## 
## Made by maxime nougarede-
## Login   <nougar_m@epitech.net>
## 
## Started on  Tue Feb  9 14:27:14 2010 maxime nougarede-
## Last update Thu Apr  1 16:40:20 2010 thibault bronchain
##

CC		=	gcc
NAME1		=	my_objdump
NAME2		=	my_nm
DIR1		=	src_objdump/
DIR2		=	src_nm/
SRC1		=	$(DIR1)header.c		\
			$(DIR1)main.c		\
			$(DIR1)sections.c	\
			$(DIR1)xfunct.c		\
			$(DIR1)xfunct2.c
SRC2		=	$(DIR2)main.c
INCLUDE		=	./includes/
CFLAGS 		+=	-W -Wall -ansi -pedantic -O2 -o $@ -I$(INCLUDE)
OBJ1		=	$(SRC1:.c=.o)
OBJ2		=	$(SRC2:.c=.o)
RM		=	rm -rf
CLEAN		=	rm -rf `find . \( -name '*~' -or -name '.*~' -or -name '.\#*\#' -or -name '\#*\#' \)`

$(NAME1):	$(OBJ1)
		@echo ""
		@echo "Compilating objects files (my_objdump)..."
		$(CC) -o $(NAME1) -I$(INCLUDE) $(OBJ1)
		@echo ""

$(NAME2):	$(OBJ2)
		@echo ""
		@echo "Compilating objects files (my_nm)..."
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
		tar cfj bkp/save_$(NAME1).bz2 $(DIR1) $(INCLUDE) Makefile
		tar cfj bkp/save_$(NAME2).bz2 $(DIR2) $(INCLUDE) Makefile
		@echo ""

objdump:	$(NAME1)

nm:		$(NAME2)

re:		fclean all save

.PHONY:		all clean fclean save re objdump nm
