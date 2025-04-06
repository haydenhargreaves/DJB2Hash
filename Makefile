CC = gcc
CFLAGS = -ansi -Wall

OBJS = main.o hash.o
HEDAERS = hash.h

application: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main
		

main.o: main.c $(HEDAERS)
	$(CC) $(CFLAGS) -c main.c


hash.o: hash.c $(HEADERS)
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm *.o main
