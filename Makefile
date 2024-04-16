# Variables 
CC = gcc
CFLAGS = -Wall -Werror -I/usr/include/tirpc

# LIBRERIA DINAMICA
PROXY_SOURCES = proxy.c
PROXY_OBJECTS = $(PROXY_SOURCES:.c=.o)
PROXY = libclaves.so

#SERVIDOR 
TARGETS_SVC.c = mensaje_svc.c mensaje_xdr.c
OBJECTS_SVC = $(TARGETS_SVC.c:%.c=%.o)
SERVER_SOURCES = servidor.c claves.c list.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
SERVER = servidor

#CLIENTE
TARGETS_CLNT.c = mensaje_clnt.c mensaje_xdr.c
OBJECTS_CLNT = $(TARGETS_CLNT.c:%.c=%.o)
CLIENT_SOURCES = cliente.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
CLIENT = cliente


all: $(PROXY) $(SERVER) $(CLIENT)

$(PROXY): $(PROXY_OBJECTS)
	$(CC) -shared -o $(PROXY) $(PROXY_OBJECTS) -lrt

$(PROXY_OBJECTS): $(PROXY_SOURCES)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJECTS_CLNT) : $(TARGETS_CLNT.c)
$(CLIENT): $(CLIENT_OBJECTS) $(OBJECTS_CLNT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJECTS) -L. -lclaves -Wl,-rpath,. -lpthread -lnsl -ltirpc

$(OBJECTS_SVC) : $(TARGETS_SVC.c) 
$(SERVER): $(SERVER_OBJECTS) $(OBJECTS_SVC)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJECTS) -lrt -lpthread -lnsl -ltirpc

runc1:
	./cliente 1

runc2:
	./cliente 2

runc3:
	./cliente 3
runs:
	./servidor

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(PROXY)
clean:
	rm -f $(PROXY_OBJECTS) $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(OBJECTS_CLNT) $(OBJECTS_SVC)

re: fclean all
