CC = gcc
OBJ_DIR = ./object_files/

ifeq ($(MAKECMDGOALS), test)
C_FILES = $(filter-out main.c, $(wildcard *.c))
else
C_FILES = $(filter-out unitTest.c, $(wildcard *.c))
endif

C_FLAGS = -Wall -Wextra -Wconversion -std=c99 -fdiagnostics-color=always -pedantic
DEBUG = -g
UNIT_TEST_LIB = -lcriterion

OBJ_FILES_LIN = $(patsubst %.c, $(OBJ_DIR)%_lin.o, $(C_FILES))

.PHONY: build, clean, run, runtest
build: main

test: $(OBJ_FILES_LIN)
	$(CC) $(DEBUG) $(C_FLAGS) -o test $(OBJ_DIR)[!main]*_lin.o $(UNIT_TEST_LIB)

main: $(OBJ_FILES_LIN)
	$(CC) $(DEBUG) $(C_FLAGS) -o main $(OBJ_DIR)[!unitTest]*_lin.o

$(OBJ_FILES_LIN): $(OBJ_DIR)%_lin.o: %.c
	$(CC) -c $(DEBUG) $< -o $@

clean: 
	rm -f $(OBJ_DIR)*.o main.exe main unitTest.exe test

run: 
	./main

runtest: 
	./test
