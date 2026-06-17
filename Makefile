CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c89 -Iinclude
TARGET = search.exe

SOURCES = src/main.c \
          src/buffer.c \
          src/options.c \
          src/search.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) src/*.o