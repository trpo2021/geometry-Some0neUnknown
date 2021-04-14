CFLAGS := -Wall -Wextra -Werror 
CPPFLAGS := 
CC := gcc

TARGET := bin/geometry

SOURCES := $(wildcard src/*.c)
LIBSOURCES := $(wildcard src/lib/*.c)

LIBOBJ := $(patsubst src/lib/%.c, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/geometrylib.a

OBJ := $(patsubst src/%.cpp, obj/src/%.o, $(SOURCES))

all: $(TARGET)


$(TARGET): $(LIB) $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) -I src/lib

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/lib

obj/src/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/lib

	
run:
	./$(TARGET)


.PHONY: clean run
clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "geometry" -exec rm {} \;


