CC = g++
CFLAGS += -std=c++11 -ggdb -Wall -Werror -pedantic
CFLAGS += -lncurses -lnoise -lsqlite3 #$(shell sdl2-config --cflags)
LDLIBS = # $(shell sdl2-config --libs)
SOURCES = $(shell find -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)

all : main
	[ -f save.db ] && echo "Database already exists" || sqlite3 save.db < gamedb.sql

main : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(LDLIBS) $< -c

.phony : clean

clean :
	rm -f *.o
