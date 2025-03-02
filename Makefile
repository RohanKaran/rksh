#Compiler
CC = gcc

#Compiler Flags
CFLAGS = -I include -Wall -Wextra

#Source and Object Files
SRC = $(wildcard src/*.c)  # Get all .c files in src/
OBJ = $(patsubst src/%.c, src/%.o, $(SRC))      # Convert .c files to .o files

# Output Executable
TARGET = build/rksh

# Build Rule
$(TARGET): $(OBJ) | build
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

build:
	mkdir -p build

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Command
clean:
	rm -f src/*.o $(TARGET)