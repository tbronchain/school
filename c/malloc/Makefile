##CC		=	gcc
CC_sun4		=	/usr/sfw/bin/gcc
CC_FreeBSD	=	/usr/bin/gcc
CC_ia64-linux	=	/usr/bin/gcc
CC		=	$(CC_$(HOSTTYPE))
NAME		=	libmy_malloc_$(HOSTTYPE).so
SRC		=	src/calc.c		\
			src/free.c		\
			src/malloc.c		\
			src/my_lib.c		\
			src/realloc.c		\
			src/show_alloc_mem.c
CFLAGS 		=	-W -Wall -ansi -pedantic -O2 -o $@ -fPIC -I$(INCLUDE)
OBJ		=	$(SRC:.c=.o)
INCLUDE		=	./includes/
RM		=	rm -rf
CLEAN		=	rm -rf `find . \( -name '*~' -or -name '.*~' -or -name '.\#*\#' -or -name '\#*\#' \)`
SHARED		=	-shared

$(NAME):$(OBJ)
	@echo ""
	@echo "Compilating shared library..."
	$(CC) -fPIC $(SHARED) -o $(NAME) -I$(INCLUDE) $(OBJ)
	ln -fs $(NAME) libmy_malloc.so
	@echo ""

all:	$(NAME)

clean:
	@echo "Removing temporary files..."
	$(CLEAN)
	$(RM) $(OBJ)
	@echo ""

fclean:	clean
	@echo "Removing old binary..."
	$(RM) $(NAME)
	@echo ""

save:
	@echo "Saving sources..."
	mkdir -p bkp
	tar cfj bkp/save_$(NAME).bz2 src $(INCLUDE) Makefile
	@echo ""

re:	fclean all save

.PHONY:	all clean fclean save re
