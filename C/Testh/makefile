CC = gcc
CFLAGS = -I./output/include/ -DDTEST_CASE -std=c11 -Wall -g
OBJS = main.o newton.o cut.o gcd.o

.PHONY: clean

a.out : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) output/libs/libtest.a 

main.o : main.c
	$(CC) -c $(CFLAGS) main.c

newton.o : newton.c newton.h
	$(CC) -c $(CFLAGS) newton.c

cut.o : cut.c cut.h
	$(CC) -c $(CFLAGS) cut.c

gcd.o : gcd.c gcd.h
	$(CC) -c $(CFLAGS) gcd.c

clean :
	rm -rf *.o a.out
