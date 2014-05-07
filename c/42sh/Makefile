CC		=	gcc
NAME		=	42sh

PARSER		=	./parser/

TERMCAP		=	./termcap/

SRC		=	main.c					\
			$(TERMCAP)get_command.c			\
			$(TERMCAP)init_struct.c			\
			$(TERMCAP)sigwinch.c			\
			$(TERMCAP)add_elem_to_list.c		\
			$(TERMCAP)function_term.c		\
			$(TERMCAP)xfunction_termcap.c		\
			$(TERMCAP)xfunction_termcap_next.c	\
			$(TERMCAP)gere_key.c			\
			$(TERMCAP)gere_del.c			\
			$(TERMCAP)gere_key_right.c		\
			$(TERMCAP)gere_key_left.c		\
			$(TERMCAP)gere_enter.c			\
			$(TERMCAP)gere_backspace.c		\
			$(TERMCAP)gere_home.c			\
			$(TERMCAP)gere_end.c			\
			$(TERMCAP)del_element.c			\
			$(TERMCAP)list.c			\
			$(TERMCAP)utils.c			\
			$(PARSER)list_for_env.c			\
			$(PARSER)init_env.c			\
			$(PARSER)builtins_env.c			\
			$(PARSER)first_parsing.c		\
			$(PARSER)builtins.c			\
			$(PARSER)check_parenth.c		\
			$(PARSER)check_redir.c			\
			$(PARSER)check_valid.c			\
			$(PARSER)count_fcts.c			\
			$(PARSER)error.c			\
			$(PARSER)builtins_cd.c			\
			$(PARSER)free_list.c			\
			$(PARSER)execution.c			\
			$(PARSER)init_parsing.c			\
			$(PARSER)logic_parse.c			\
			$(PARSER)display_str_fcts.c		\
			$(PARSER)make_redir.c			\
			$(PARSER)modif_str_fcts.c		\
			$(PARSER)my_env.c			\
			$(PARSER)parenth.c			\
			$(PARSER)parse_pipe.c			\
			$(PARSER)parse_redir.c			\
			$(PARSER)quote.c			\
			$(PARSER)token.c			\
			$(PARSER)wordtab.c			\
			$(PARSER)x_function.c			\
			$(PARSER)x_function_next.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-I./include/\
			-W -Wall -ansi -pedantic -o $@

LIB		=	-ltermcap

RM		=	rm -rf

SAVE		=	tar cfz save_42sh.tar.gz Makefile include/*.h $(SRC)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)


save:
	$(SAVE)

clean:
	$(RM) *~
	$(RM) $(OBJ)


fclean:
	$(RM) *~
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: 	 fclean all save

.PHONY:		all clean re save
