CC = gcc
CFLAGS = -Wall -Wextra -Werror
all: multi course observe

multi: multi.o
	$(CC) $(CFLAGS) -o multi multi.o

multi.o: multi.c
	$(CC) $(CFLAGS) -c multi.c

course: course.o
	$(CC) $(CFLAGS) -o course course.o

course.o: course.c
	$(CC) $(CFLAGS) -c course.c

observe: observe.o
	$(CC) $(CFLAGS) -o observe observe.o

observe.o: observe.c
	$(CC) $(CFLAGS) -c observe.c

clean:
	rm -f *.o multi course observe

.PHONY: clean