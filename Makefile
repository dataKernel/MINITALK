WARNING_FLAGS = -Wall -Wextra -Werror

PRINTF/libftprintf.a:
	make -C PRINTF fclean
	make -C PRINTF

client: client.c
	gcc $(WARNING_FLAGS) client.c -o client

server: server.c PRINTF/libftprintf.a
	gcc $(WARNING_FLAGS) server.c PRINTF/libftprintf.a -o server

clean:
	rm -f client server

fclean:
	rm -f client server
	make -C PRINTF fclean

all: client server

re: fclean all
