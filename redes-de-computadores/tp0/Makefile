CC := gcc
SRCDIR := src
OBJDIR := build
BINDIR := bin

MAIN := main.cpp
SERVIDOR := servidor.c
PROFESSOR := cliente-prof.c
ALUNO := cliente-aluno.c
SERVIDOR_MT := servidor-mt.c

SRCEXT := c

# -g debug, --coverage para cobertura
#CFLAGS := --coverage -g -Wall -O3 -std=c++11
CFLAGS := -std=c11

all: clean main

clean:
	$(RM) -rf servidor cliente-prof cliente-aluno servidor-mt

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(SERVIDOR) -I include/ -o servidor
	$(CC) $(CFLAGS) $(SERVIDOR_MT) -I include/ -o servidor-mt -lpthread
	$(CC) $(CFLAGS) $(PROFESSOR) -I include/ -o cliente-prof
	$(CC) $(CFLAGS) $(ALUNO) -I include/ -o cliente-aluno