# きれいなMakefileにしよう!

CFLAGS =
LFLAGS =

CC = gcc $(CFLAGS)

OBJS = main.o event.o tools.o

all : main

main : $(OBJS)
	$(CC) -o $@ $(LFLAGS) $^

.c.o:
	$(CC) -c $<

clean:
	rm -rf *.o main
