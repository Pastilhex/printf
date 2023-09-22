SRCS = 	ft_printf.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putnbr_u.c\
		ft_putnbr_base.c\
		ft_putnbr_hexa.c\
		ft_putstr.c\
		ft_strlen.c

OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:	fclean $(NAME)
so:	$(CC) $(CFLAGS) $(OBJS)

.PHONY:	all clean fclean re
