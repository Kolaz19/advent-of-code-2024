CC = gcc
OBJ_DIR = ./object_files/

C_FLAGS = -Wall -Wextra -Wconversion -std=c99 -fdiagnostics-color=always -pedantic
DEBUG_FLAG = -g

C_FILES = $(wildcard *.c)
OBJ_FILES_LIN = $(patsubst %.c, $(OBJ_DIR)%_lin.o, $(C_FILES))

build: main

main: $(OBJ_FILES_LIN)
	$(CC) $(DEBUG_FLAG) $(C_FLAGS) -o main $(OBJ_DIR)*_lin.o

$(OBJ_FILES_LIN): $(OBJ_DIR)%_lin.o: %.c
	$(CC) -c $(DEBUG_FLAG) $< -o $@

clean: 
	rm -f $(OBJ_DIR)*.o main.exe main

run: 
	./main
