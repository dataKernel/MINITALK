WARNING_FLAGS = -Wall -Wextra -Werror

PRINTF-master/libftprintf.a:
	make -C PRINTF-master fclean
	make -C PRINTF-master

client: client.c
	gcc $(WARNING_FLAGS) client.c -o client

server: server.c PRINTF-master/libftprintf.a
	gcc $(WARNING_FLAGS) server.c PRINTF-master/libftprintf.a -o server

clean:
	rm -f client server

fclean:
	rm -f client server
	make -C PRINTF-master fclean

all: client server

re: fclean all
