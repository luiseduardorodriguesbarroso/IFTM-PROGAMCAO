TARGET = programa
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRCS = programa.c
DEPS = pilha_fila.h

ifeq ($(OS),Windows_NT)
    BIN = $(TARGET).exe
    RM = del /Q /F
else
    BIN = $(TARGET)
    RM = rm -f
endif

all: $(BIN)

$(BIN): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN)

run: $(BIN)
ifeq ($(OS),Windows_NT)
	.\$(BIN)
else
	./$(BIN)
endif

clean:
	$(RM) $(BIN)

.PHONY: all run clean
