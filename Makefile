CFLAGS := -std=c99 -Wall -Wextra -pedantic -O2 -pipe -Wno-unused-function -Wno-unused-parameter
PREFIX ?= /usr/local
.PHONY : clean install
all: thousandmonkeys
thousandmonkeys: thousandmonkeys-obj
	$(CC) $(CFLAGS) obj/thousandmonkeys.o -o bin/thousandmonkeys
thousandmonkeys-obj:
	$(CC) $(CFLAGS) -c src/thousandmonkeys.c -o obj/thousandmonkeys.o
helpers-obj:
	$(CC) $(CFLAGS) -c src/helpers.c -o obj/helpers.o
clean:
	rm -f bin/*
	rm -f obj/*
install: install-thousandmonkeys
install-thousandmonkeys: install-prepare
	cp bin/thousandmonkeys "$(PREFIX)/bin/"
install-prepare:
	mkdir -p "$(PREFIX)/bin"
