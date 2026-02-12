CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
TARGET = bin/bst
SRC = src/main.c src/bst.c
OBJ = build/main.o build/bst.o

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Generic rule to compile .c to .o
build/%.o: src/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning build and bin directories..."
	rm -f build/* bin/*

run: $(TARGET)
	@echo "Running BST..."
	./$(TARGET)

.PHONY: all clean run
