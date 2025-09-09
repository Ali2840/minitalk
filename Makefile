SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c $(wildcard ft_printf/*.c)
SRC_CLIENT = client.c $(wildcard Libft/*.c)

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re