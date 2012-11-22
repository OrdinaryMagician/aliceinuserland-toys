CFLAGS := -std=c99 -Wall -Wextra -O2 -pipe
LDFLAGS := -Wall -Wextra -O1
PREFIX =? /usr/local
.PHONY : clean install
au: au-obj
	$(CC) $(LDFLAGS) obj/thousandmonkeys.o -o bin/thousandmonkeys
au-obj:
	$(CC) $(CFLAGS) -c helpers.c -o obj/helpers.o
	$(CC) $(CFLAGS) -c thousandmonkeys.c -o obj/thousandmonkeys.o
clean:
	rm -f bin/*
	rm -f obj/*
install:
	cp bin/ "$(PREFIX)"
