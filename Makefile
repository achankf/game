CC = gcc
CFLAGS = -O3 -std=c99 -ggdb -Wall -Werror -pedantic
CFLAGS += -lncurses #$(shell sdl2-config --cflags)
LDLIBS = # $(shell sdl2-config --libs)

SOURCES = $(shell find -name "*.c")
OBJECTS = $(SOURCES:.c=.o)
EXE = main

all : $(EXE)

$(EXE) : main.c
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@
