# Variables 
CC = gcc
CFLAGS = -Wall -Werror -I/usr/include/tirpc

# LIBRERIA DINAMICA
PROXY_SOURCES = proxy.c
PROXY_OBJECTS = $(PROXY_SOURCES:.c=.o)
PROXY = libclaves.so

#SERVIDOR 
TARGETS_SVC = mensaje_svc.c
OBJECTS_SVC = $(TARGETS_SVC:%.c=%.o)
SERVER_SOURCES = servidor.c claves.c list.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
SERVER = servidor

#CLIENTE
TARGETS_CLNT = mensaje_clnt.c mensaje_xdr.c
OBJECTS_CLNT = $(TARGETS_CLNT:%.c=%.o)
CLIENT_SOURCES = cliente.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
CLIENT = cliente


all: $(PROXY) $(SERVER) $(CLIENT)

$(OBJECTS_CLNT) : %.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@
$(PROXY): $(PROXY_OBJECTS) $(OBJECTS_CLNT)
	$(CC) -shared -o $(PROXY) $(PROXY_OBJECTS) $(OBJECTS_CLNT) -lrt -lnsl -ltirpc

$(PROXY_OBJECTS): $(PROXY_SOURCES)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@


$(CLIENT): $(CLIENT_OBJECTS) 
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJECTS) -L. -lclaves -Wl,-rpath,. -lpthread -lnsl -ltirpc

$(OBJECTS_SVC) : $(TARGETS_SVC)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(SERVER_OBJECTS) $(OBJECTS_SVC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJECTS) $(OBJECTS_SVC) mensaje_xdr.o -lrt -lpthread -lnsl -ltirpc

runc1:
	env IP_TUPLAS=localhost ./cliente 1

runc2:
	env IP_TUPLAS=localhost ./cliente 2

runc3:
	env IP_TUPLAS=localhost ./cliente 3
runs:
	./servidor

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(PROXY)
clean:
	rm -f $(PROXY_OBJECTS) $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(OBJECTS_CLNT) $(OBJECTS_SVC)

re: fclean all
