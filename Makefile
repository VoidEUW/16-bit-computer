# Makefile for 16 computer
# Void (c) 2024
# Version 1.0.0

# Compiler flags
CFLAGS = -std=c99 -Wall -Wextra #-g #-Werror -pedantic -g
# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
BUILD_DIR = ./build

# Executable name
TARGET = $(BUILD_DIR)/cpu

# Find all .c files recursively in SRC_DIR
SRC_FILES = $(shell find $(SRC_DIR) -type f -name '*.c')

# Create corresponding .o paths in OBJ_DIR with the same structure
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default rule
all: $(OBJ_DIR) $(BUILD_DIR) $(TARGET)

# Create obj directory if not exists
$(OBJ_DIR):
	@echo "Creating obj directory:"
	mkdir -p $(OBJ_DIR)
	@echo "Creating subdirectories in obj:"
	@find $(SRC_DIR) -type d | sed "s@$(SRC_DIR)@$(OBJ_DIR)@" | xargs mkdir -p

# Create build directory if not exists
$(BUILD_DIR):
	@echo "Creating build directory:"
	mkdir -p $(BUILD_DIR)

# Compile each .c to .o in corresponding obj structure
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	gcc $(CFLAGS) -c $< -o $@

# Link object files to create the final executable
$(TARGET): $(OBJ_FILES)
	@echo "Linking object files to create the executable:"
	gcc $(CFLAGS) $^ -o $(TARGET)

# Clean rule
clean:
	@echo "Cleaning all build files:"
	rm -rf $(OBJ_DIR) $(TARGET)

asm:
	@echo "Creating assembly files:"
	gcc $(CFLAGS) src_assembler/assembler.c -o $(BUILD_DIR)/assim