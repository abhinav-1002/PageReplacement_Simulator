CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = page_replacement
SRC = src/main.c src/fifo.c

all:
	$(CC) $(CFLAGS) $(SRC) -Iinclude -o $(TARGET)

clean:
	del /Q $(TARGET).exe 2>nul