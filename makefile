CC = gcc
CFLAGS = -g

all: run.o
	$(CC) $(CFLAGS) -o program run.o
run.o: run.c headers.h
	$(CC) -c run.c
clean:
	rm *.o program
