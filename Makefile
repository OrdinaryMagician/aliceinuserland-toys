CFLAGS := -std=c99 -Wall -Wextra -pedantic -O2 -pipe -Wno-unused-function -Wno-unused-parameter -Isrc/
PREFIX ?= /usr/local
.PHONY : clean install
UTILS := thousandmonkeys
SOURCES := $(patsubst %.c,%.o,$(wildcard src/*.c))
all: $(SOURCES) $(UTILS)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
thousandmonkeys:
	$(CC) $(CFLAGS) src/thousandmonkeys.o -o bin/thousandmonkeys
clean:
	rm -f bin/*
	rm -f src/*.o
install:
	mkdir -p "$(PREFIX)/bin"
	cp -r bin/ "$(PREFIX)/bin/"
