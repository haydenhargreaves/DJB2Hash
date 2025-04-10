CC = gcc
CFLAGS = -ansi -Wall

OBJS = main.o hash.o io.o
HEADERS = hash.h io.h

application: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main
		

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c


hash.o: hash.c $(HEADERS)
	$(CC) $(CFLAGS) -c hash.c

io.o: io.c $(HEADERS)
	$(CC) $(CFLAGS) -c io.c

clean:
	rm *.o main
