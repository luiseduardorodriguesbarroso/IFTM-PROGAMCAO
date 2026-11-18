# Detecção do Sistema Operacional (Windows vs Linux)
ifeq ($(OS),Windows_NT)
    CC = gcc
    EXT = .exe
    RM = -del /f /q 2>nul
else
    CC = gcc
    EXT =
    RM = rm -f
endif

CFLAGS = -Wall -Wextra -std=c99
TARGET = programa$(EXT)
SRCS = programa.c prova.c pilha.c fila.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	-del /f /q $(OBJS) $(TARGET) 2>nul
else
	rm -f $(OBJS) $(TARGET)
endif

.PHONY: all run clean

