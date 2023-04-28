CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT):
	cc $(CFLAGS) client.c -o $(CLIENT)

$(SERVER):
	cc $(CFLAGS) server.c -o $(SERVER)

clean:
	rm -f $(CLIENT) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
