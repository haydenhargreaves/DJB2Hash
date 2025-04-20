CC = gcc
CFLAGS = -ansi -Wall

OBJS = hashbat.o hash.o
HEDAERS = hashbat.h

application: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hashbat
		

hashbat.o: hashbat.c $(HEDAERS)
	$(CC) $(CFLAGS) -c hashbat.c

hash.o: hash.c $(HEADERS)
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm *.o hashbat
