NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c ft_strdup.c ft_strlen.c ft_substr.c \
       parsing.c stack_man.c main2.c swap.c push.c rotate.c \
	   reverse_rotate.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "push_swap compiled successfully"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap removed"

re: fclean all

.PHONY: all clean fclean re
