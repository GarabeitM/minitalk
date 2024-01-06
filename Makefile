SRCS    = client.c server.c

OBJS    := $(SRCS:%.c=%.o)

NAME    = minitalk

CC      = cc
RM      = rm -f

CFLAGS  = -Wall -Wextra -Werror

all:        ${NAME}

%.o:    %.c
	@${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

${NAME}: server client

server:     server.o
	@make --no-print-directory -C libft
	@make --no-print-directory -C printf
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server

client:     client.o
	@make --no-print-directory -C libft
	@make --no-print-directory -C printf
	@${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client

libft:
	@make --no-print-directory -C libft

printf:
	@make --no-print-directory -C printf

clean:
	@make --no-print-directory clean -C libft
	@make --no-print-directory clean -C printf
	@${RM} ${OBJS}

fclean:     clean
	@${RM} server client

re:         fclean all

.PHONY:     libft printf

