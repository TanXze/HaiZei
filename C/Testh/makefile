CC = gcc
CFLAGS = -DDTEST_CASE -std=c11 -Wall -g
OBJS = main.o newton.o cut.o gcd.o test.o

.PHONY: clean

a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

main.o : main.c
	$(CC) -c $(CFLAGS) main.c

newton.o : newton.c newton.h
	$(CC) -c $(CFLAGS) newton.c

cut.o : cut.c cut.h
	$(CC) -c $(CFLAGS) cut.c

gcd.o : gcd.c gcd.h
	$(CC) -c $(CFLAGS) gcd.c

test.o : test.c test.h
	$(CC) -c $(CFLAGS) test.c

clean :
	rm -rf *.o a.out
