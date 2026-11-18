# A ideia deste Makefile é que os arquivos do projeto podem estar todos no mesmo diretório:
# programa.c
# teste.c
# teste.h
# Ou então separados em diretórios:
# src
#	programa.c
#	teste.c
# include
# 	teste.h
# O código gerado será separado em versão Debug e versão Release.
# O diretório de saída é sempre o bin, gerando:
# bin
#	debug
#		obj
#			programa.o
#			teste.o
#		programa ou progrma.exe
#	release
#		obj
#			programa.o
#			teste.o
#		programa ou programa.exe

# ==========================================

PROGRAM_NAME = programa
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
OBJ_DIR = obj
REL_DIR = release
DEB_DIR = debug

# Deteção do Sistema Operacional
ifeq ($(OS),Windows_NT)
	CC = gcc
	EXT = .exe
	EXEC = $(TARGET_DIR)/$(PROGRAM_NAME)$(EXT)
else
	CC = /usr/bin/gcc
	EXT =
	EXEC = ./$(TARGET_DIR)/$(PROGRAM_NAME)$(EXT)
endif

# Define um conjunto de flags do compilador bem restritivas.
BASE_CFLAGS = -std=c2x -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wconversion -Wunreachable-code -fdiagnostics-color=always

# Procura automaticamente por todos os ficheiros .c no diretório atual e na pasta src.
SRC_FILES = $(wildcard *.c) $(wildcard $(SRC_DIR)/*.c)

# Inclui o diretório atual e verifica se o diretório include existe.
INCLUDES = -I. $(if $(wildcard $(INC_DIR)),-I$(INC_DIR))

ifeq ($(MAKECMDGOALS),release)
	TARGET_DIR = $(BIN_DIR)/$(REL_DIR)
	CFLAGS = $(BASE_CFLAGS) -O3 -s $(INCLUDES)
else
	TARGET_DIR = $(BIN_DIR)/$(DEB_DIR)
	CFLAGS = $(BASE_CFLAGS) -g -O0 $(INCLUDES)
endif

OBJ_FILES = $(patsubst %.c, $(TARGET_DIR)/$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
TARGET = $(TARGET_DIR)/$(PROGRAM_NAME)$(EXT)

vpath %.c . $(SRC_DIR)

# Regra padrão. Manda construir o executável versão Debug
all: directories $(TARGET)

# Cria os diretórios necessários caso não existam
directories:
	@mkdir -p $(TARGET_DIR)/$(OBJ_DIR)

# Regras de Linkagem
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET) -lm

# Compilação individual (.c -> .o) direto no diretório do modo ativo
$(TARGET_DIR)/$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra Release
release: directories $(TARGET)

# Executar (Padrão Debug)
run: all
	@$(EXEC)

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean run release directories