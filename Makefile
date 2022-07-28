SRCS = $(shell find "." -name "*.c")
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC   = gcc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

${NAME} : ${OBJS}
	${CC} ${FLAGS} ${MLXFLAGS} ${SRCS} -o so_long

all : ${NAME}

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

bonus : all

.PHONY :
		all clean fclean
