CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -fPIC -Iinclude
TARGET = librational.so

all: $(TARGET)

$(TARGET): src/rational.c
	$(CC) $(CFLAGS) -shared -o $@ $<

test: $(TARGET)
	$(CC) $(CFLAGS) tests/test_rational.c -L. -lrational -o test_rational
	LD_LIBRARY_PATH=. ./test_rational

clean:
	rm -f $(TARGET) test_rational

.PHONY: all test clean
