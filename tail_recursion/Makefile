
# Compiler and flags
CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2
LDFLAGS = -shared

# Directory structure
LIBSRCDIR = include
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
BINDIR = bin
MAINDIR = main

# Add include
INCDIR = $(LIBSRCDIR)

# Source files and corresponding object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
TARGET = $(LIBDIR)/libtailrecursion.so

# Main source and target
MAIN_SRC = $(MAINDIR)/main.c
MAINTARGET = $(BINDIR)/main
MAINASSAM =  $(BINDIR)/main.s

lib: $(TARGET)

# Default target
all: $(TARGET) $(MAINTARGET)

# Rule to create the output directories if they don't exist
$(OBJDIR) $(LIBDIR) $(BINDIR):
	mkdir -p $@

# Rule to create the shared library
$(TARGET): $(OBJDIR) $(LIBDIR) $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Rule to compile each source file into an object file in the obj directory
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

main:$(MAINTARGET)

# Rule to compile the main program using the shared library
$(MAINTARGET): $(MAIN_SRC) $(LIBTARGET) | $(BINDIR)
	$(CC) -O3 -o $@ $(MAIN_SRC) -I$(INCDIR)  -L$(LIBDIR) -ltailrecursion -Wl,-rpath,$(LIBDIR)

asm:$(MAINASSAM)

$(MAINASSAM):
	$(CC) -O3 -S -o bin/quicksort.s src/quicksort.c -Iinclude

# Clean target to remove generated files
clean:
	rm -f $(OBJDIR)/*.o $(LIBTARGET) $(MAINTARGET) bin/quicksort.s

.PHONY: all clean