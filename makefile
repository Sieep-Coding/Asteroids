CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = asteroids
SRCDIR = ./include
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SOURCES:.c=.o)
MAIN = main.c

$(TARGET): $(OBJS) $(MAIN:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN:.c=.o): $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN:.c=.o) $(TARGET)

.PHONY: clean
