CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/cli.c src/game_logic.c
OBJ = $(SRC:.c=.o)

TARGET = i-C-mines

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
