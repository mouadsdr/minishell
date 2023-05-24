NAME = minishell

LIBFT = libft/libft.a

CC = cc

RM = rm -rf

FLAGS =  -lreadline

# BUILT = $(addprefix builtins/,)
LEXER = $(addprefix lexer/, lexer.c list.c)

SRC = minishell.c $(LEXER)\

all : $(NAME) 

$(NAME) : $(SRC) $(LIBFT)
	$(CC)  $(SRC) -o $(NAME) $(LIBFT) $(FLAGS)

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

$(LIBFT) :
	make -C libft
clean : 
	$(RM) $(NAME)