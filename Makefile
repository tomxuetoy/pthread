CC = gcc
FILENAME = thread_ex
FLAGS = -lpthread

all:
	$(CC) -o $(FILENAME) $(FILENAME).c $(FLAGS)

clean:
	rm $(FILENAME)
