CFLAGS := -Wall -Wextra -Werror 
CPPFLAGS := 
CC := gcc

TARGET := bin/geometry

SOURCES := $(wildcard src/*.c)
LIBSOURCES := $(wildcard src/lib/*.c)

LIBOBJ := $(patsubst src/lib/%.c, obj/%.o, $(LIBSOURCES))
LIB := obj/geometrylib.a

OBJ := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: $(TARGET)


$(TARGET): $(LIB) $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/%.o: src/lib/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 

obj/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 

	
run:
	./$(TARGET)


.PHONY: clean run
clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "geometry" -exec rm {} \;


