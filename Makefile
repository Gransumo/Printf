CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= libftprintf.a
SRCS	= ft_libftprintf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_putnbr_base.c
OBJS	= ${SRCS:.c=.o}

AR		= ar rc

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM}  ${NAME}
re: fclean all
.PHONY: all clean fclean re