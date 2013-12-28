CC = g++
CFLAGS += -std=c++11 -ggdb -Wall -Werror -pedantic -pedantic-errors -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations
CFLAGS += -Iinclude
LDLIBS += -lncurses -lnoise -lsqlite3
SOURCES = $(shell find -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
EXE = main
DB = save.db

all : $(EXE) $(DB)

$(DB) : 
	[ -f save.db ] && echo "Database already exists" || sqlite3 save.db < gamedb.sql

$(EXE) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

.phony : clean style

clean :
	rm -f $(OBJECTS)

style :
	find -name "*.cpp" -exec astyle --indent=tab --style=java {} \;
	find -name "*.h" -exec astyle --indent=tab --style=java {} \;
