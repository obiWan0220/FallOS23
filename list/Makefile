# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Michael Obi>
## Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCDIR = src
SOURCES = $(SRCDIR)/list.c $(SRCDIR)/main.c

# Object files
OBJDIR = obj
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Executable name
EXECUTABLE = list_test

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
    $(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
    mkdir -p $(OBJDIR)

clean:
    rm -rf $(OBJDIR) $(EXECUTABLE)

.PHONY: all clean
