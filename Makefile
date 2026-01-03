NAME = push_swap
B_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c ft_strdup.c ft_strlen.c ft_substr.c \
       parsing.c stack_man1.c stack_man2.c stack_man3.c main.c swap.c push.c rotate.c \
	   reverse_rotate.c ft_atoi.c sort.c

OBJS = $(SRCS:.c=.o)

B_SRCS = ft_split.c ft_strdup.c ft_strlen.c ft_substr.c \
       parsing.c stack_man1.c stack_man2.c stack_man3.c swap.c push.c rotate.c \
	   reverse_rotate.c ft_atoi.c  get_next_line.c get_next_line_utils.c checker.c
B_OBJS = $(B_SRCS:.c=.o)
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "push_swap compiled successfully"

bonus: $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)
	@echo "checker compiled successfully"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@echo "object files removed"

fclean: clean
	@rm -f $(NAME) $(B_NAME)
	@echo "push_swap removed"

re: fclean all


