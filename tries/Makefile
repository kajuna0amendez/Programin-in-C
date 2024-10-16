
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
TARGET = $(LIBDIR)/libinsertiontree.so

# Main source and target
MAIN_SRC = $(MAINDIR)/main.c
MAINTARGET = $(BINDIR)/main

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
	$(CC) -o $@ $(MAIN_SRC) -I$(INCDIR)  -L$(LIBDIR) -linsertiontree -Wl,-rpath,$(LIBDIR)

# Clean target to remove generated files
clean:
	rm -f $(OBJDIR)/*.o $(LIBTARGET) $(MAINTARGET)

.PHONY: all clean