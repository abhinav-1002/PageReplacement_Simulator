CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = page_replacement
SRC = src/main.c src/fifo.c src/lru.c

all:
	$(CC) $(CFLAGS) $(SRC) -Iinclude -o $(TARGET).exe

clean:
	del /Q $(TARGET).exe 2>nul