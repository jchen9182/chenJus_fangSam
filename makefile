CC = gcc
CFLAGS = -g

all: main.o run.o
	$(CC) $(CFLAGS) -o shell main.o run.o
main.o: main.c headers.h
	$(CC) -c main.c
run.o: run.c headers.h
	$(CC) -c run.c
run:
	./shell
clean:
	rm *.o shell
