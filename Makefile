CC = gcc
FILENAME1 = thread_ex
FILENAME2 = thread_ex2
FLAGS = -lpthread

all:	$(FILENAME1) $(FILENAME2)

$(FILENAME1):
	$(CC) -o $(FILENAME1) $(FILENAME1).c $(FLAGS)

$(FILENAME2):
	$(CC) -o $(FILENAME2) $(FILENAME2).c $(FLAGS)

clean:
	rm $(FILENAME1) $(FILENAME2)
