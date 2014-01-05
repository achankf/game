CC = clang++
#CC = g++
INCLUDES = -Iinclude
CFLAGS = -O0
#CFLAGS += -ffast-math -ffinite-math-only -fno-trapping-math
CFLAGS += -std=c++11 -pipe -ggdb
CFLAGS += -Wall -pedantic -pedantic-errors -Wextra -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations
#CFLAGS += -Werror
CPPFLAGS = $(INCLUDES) -MMD
LDLIBS += -lncurses -lnoise -lsqlite3 -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = $(shell find -name "*.cpp")
HEADERS = $(shell find -name "*.hpp")
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
	find -name "*.hpp" -exec astyle --indent=tab --style=java {} \;

strip : $(EXE)
	strip $<
