# ============================================================
# Makefile — Sistema de Controle de Pedidos (SCP)
# Versão Híbrida (Windows com MinGW / Linux)
# ============================================================

# === CONFIGURAÇÕES GERAIS ===
CC = gcc
# Inclui a pasta local 'include' onde está o curses.h
CFLAGS = -Wall -Wextra -Iinclude 

# Detecta Windows ou Linux automaticamente
ifeq ($(OS),Windows_NT)
    # --- CONFIGURAÇÃO WINDOWS ---
    EXT = .exe
    # Procura a biblioteca na pasta 'lib' e usa o pdcurses
    LIBS = -Llib -lpdcurses 
    RM = del /Q
    fix_path = $(subst /,\,$1)
    MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
else
    # --- CONFIGURAÇÃO LINUX ---
    EXT = 
    LIBS = -lncurses
    RM = rm -rf
    fix_path = $1
    MKDIR = mkdir -p $1
endif

# Diretórios
BUILD_DIR = build
SRC_DIR = src
DATA_DIR = data

# Nome do executável
EXEC = $(BUILD_DIR)/scp$(EXT)

# Lista de arquivos
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# ============================================================
# REGRAS PRINCIPAIS
# ============================================================

all: directories $(EXEC)
	@echo "Compilacao concluida com sucesso!"

# Cria as pastas necessárias (build e data)
directories:
	@$(call MKDIR,$(BUILD_DIR))
	@$(call MKDIR,$(DATA_DIR))

# Linkagem (Gera o executável final)
$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LIBS)

# Compilação (Gera os arquivos .o)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	@echo "Limpando arquivos..."
	@$(RM) $(call fix_path,$(BUILD_DIR)/*)
	@echo "Limpeza concluida."

# Executar
run: all
	@echo "Executando o Sistema..."
	@$(call fix_path,$(EXEC))

.PHONY: all clean run directories