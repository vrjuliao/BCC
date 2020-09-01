CC := g++
OBJDIR := build
BINDIR := bin

SERVER := server.cpp
CLIENT := client.cpp

SRCEXT := cpp

# -g debug, --coverage para cobertura
#CFLAGS := --coverage -g -Wall -O3 -std=c++11
CFLAGS := -std=c++11

all: clean main

clean:
	$(RM) -rf servidor cliente

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(SERVER) -o servidor
	$(CC) $(CFLAGS) $(CLIENT) -o cliente