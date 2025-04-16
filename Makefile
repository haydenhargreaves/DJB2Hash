CC = gcc
CFLAGS = -ansi -Wall

OBJS = main.o hash.o io.o cli.o cmds.o
HEADERS = include/hash.h include/io.h include/cli.h include/cmds.h

PREFIX = $(HOME)
BINDIR = $(PREFIX)/.local/bin

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

clean:
	rm *.o hashbat
