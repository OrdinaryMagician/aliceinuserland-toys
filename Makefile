CFLAGS := -std=c99 -Wall -Wextra -Werror -pedantic -O2 -pipe \
	  -Wno-unused-function -Wno-unused-parameter -Isrc/
PREFIX ?= /usr/local
.PHONY : clean install
UTILS := 1000monkeys
SOURCES := $(patsubst %.c,%.o,$(wildcard src/*.c))
all: $(SOURCES) $(UTILS)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
1000monkeys:
	$(CC) $(CFLAGS) src/helpers.o src/1000monkeys.o -o bin/1000monkeys
clean:
	rm -f bin/*
	rm -f src/*.o
install:
	mkdir -p "$(PREFIX)/bin"
	cp -r bin/ "$(PREFIX)/bin/"
