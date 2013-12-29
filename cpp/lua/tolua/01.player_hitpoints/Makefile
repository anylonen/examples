CC=g++
INCLUDES=-I/usr/include/lua5.1
LIBS=-ltolua++5.1 -llua5.1
CFLAGS=-c -Wall $(INCLUDES)
LDFLAGS=$(LIBS)
SOURCES=player.cpp player_lua.cpp ex01.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ex01
TOLUA=tolua++5.1
PKGS=player.pkg

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(SOURCES):$(PKGS)
	$(TOLUA) -n $(basename $<) -H $(basename $<)_lua.h -o $(basename $<)_lua.cpp $(basename $<).pkg

clean:
	rm -rf *_lua.* *o ex01
