CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa.exe
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
	del /f /q $(OBJS) $(TARGET) 2>nul || rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
