CC = gcc
CFLAGS = -ansi -Wall

OBJS = main.o hash.o io.o cli.o cmds.o
HEADERS = include/hash.h include/io.h include/cli.h include/cmds.h

TOBJS = hash.o io.o cli.o cmds.o
TFILES = test/test.c test/hash_tests.c test/cli_tests.c test/io_tests.c

PREFIX = $(HOME)
BINDIR = $(PREFIX)/.local/bin

.PHONY: clean test install uninstall

application: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hashbat
		

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c

hash.o: hash.c $(HEADERS)
	$(CC) $(CFLAGS) -c hash.c

io.o: io.c $(HEADERS)
	$(CC) $(CFLAGS) -c io.c

cli.o: cli.c $(HEADERS)
	$(CC) $(CFLAGS) -c cli.c

cmds.o: cmds.c $(HEADERS)
	$(CC) $(CFLAGS) -c cmds.c

install: application
	install -d "$(BINDIR)"
	install -m 755 hashbat "$(BINDIR)/hashbat"

uninstall:
	rm -f "$(BINDIR)/hashbat"

test: $(TFILES) $(OBJS)
	$(CC) $(CFLAGS) $(TFILES) $(TOBJS) -o tests
	./tests

clean:
	rm *.o hashbat tests
