# $B$-$l$$$J(BMakefile$B$K$7$h$&(B!

CFLAGS =
LFLAGS =

CC = gcc $(CFLAGS)

OBJS = main.c event.o tools.o

all : main

main : $(OBJS)
	$(CC) -o $@ $(LFLAGS) $^

.c.o:
	$(CC) -c $<

clean:
	rm -rf *.o main
