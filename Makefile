CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = page_replacement
SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del /Q $(TARGET).exe 2>nul