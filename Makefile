CFLAGS = -Wall -Wextra -Werror

CLIENT = client
CLIENTSRC = client.c
CLIENTOBJ = client.o

SERVER = server
SERVERSRC = server.c
SERVEROBJ = server.o

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVEROBJ)
	cc $(CFLAGS) -c $(SERVERSRC)
	cc $(CFLAGS) $(SERVEROBJ) -o $(SERVER)

$(CLIENT): $(CLIENTOBJ)
	cc $(CFLAGS) -c $(CLIENTSRC)
	cc $(CFLAGS) $(CLIENTOBJ) -o $(CLIENT)

clean:
	rm -f $(CLIENTOBJ)
	rm -f $(SERVEROBJ)

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re: fclean all

.PHONY: all clean fclean re
