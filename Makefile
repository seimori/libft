#
#	Variables
#

#	Path of source files
SRC_PATH = sources

#	!!!!!To change!!!!!!
#	List of source files
#	!!!!!!!!!!!!!!!!!!!!
SRC_NAME = printf.c print_args.c \
		   tools.c fillers.c identifiers.c get_typeindex.c \
		   print_i.c print_u.c print_c.c print_s.c print_p.c \
		   print_signed.c print_unsigned.c print_hexadecimal.c \
		   print_hexadecimal_big.c print_octal.c \
		   \
		   main.c extra.c

#	Source full name
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

#	Path of object files
OBJ_PATH = objects

#	Get objects names from source files
OBJ_NAME = $(SRC_NAME:.c=.o)

#	Object full name
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

#	!!!!!To change!!!!
#	Include files path
#	!!!!!!!!!!!!!!!!!!

INC = includes/printf.h

#	Include files path
INC_PATH = includes

#	Include files path flag
CPPFLAGS = -Iincludes

#	Uncomment if you want to compile libft
LIB_PATH = libft

#	Lib file path flag
LDFLAGS = -Llibft

#	-lft represents libft.a
LDLIBS = -lft

#	!!!!!To change!!!!!!
#	Output name
#	!!!!!!!!!!!!!!!!!!!!
NAME = a.out

#	Compilator
CC = gcc

#	Compilator options
CFLAGS = -Werror -Wall -Wextra

#
#	Rules
#

.PHONY: all, clean, fclean, re, norm

all: $(NAME)

#	$^ is $(OBJ)
#	$@ is $(NAME)
# 	Uncomment "@cd $(LIB_PATH) && $(MAKE)" if you want to compile lib
$(NAME): $(OBJ)
	@cd $(LIB_PATH) && $(MAKE)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

#	2> /dev/null || true is to avoid errors and messages if folder already exists
#	$< is first dependance ($(SRC_PATH)%.c)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	rm -fv $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

norm:
	norminette $(SRC)
	norminette $(INC)
