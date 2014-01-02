CC = g++
INCLUDES = -Iinclude
CFLAGS = -flto -Os
CFLAGS += -ffast-math -ffinite-math-only -fno-trapping-math
CFLAGS += -std=c++11 -pipe -ggdb -Wall -Werror -pedantic -pedantic-errors -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations
CPPFLAGS = $(INCLUDES) -MMD
LDLIBS += -lncurses -lnoise -lsqlite3 -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = $(shell find -name "*.cpp")
HEADERS = $(shell find -name "*.h")
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)
EXE = main
DB = save.db

all : $(EXE) $(DB)

-include $(DEPENDS)

$(DB) : 
	[ -f save.db ] && echo "Database already exists" || sqlite3 save.db < gamedb.sql

$(EXE) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c -o $@

.phony : clean style strip

clean :
	rm -f $(OBJECTS)

style :
	find -name "*.cpp" -exec astyle --indent=tab --style=java {} \;
	find -name "*.h" -exec astyle --indent=tab --style=java {} \;

strip : $(EXE)
	strip $<
