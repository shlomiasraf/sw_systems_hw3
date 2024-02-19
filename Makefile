CC= gcc
FLAGS= -Wall -g 
OBJECTS_MAIN= Main.o
OBJECTS_LIST = StrList.o

all: mains

Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c Main.c

libStrlist.so: $(OBJECTS_LIST) StrList.h
	$(CC) -shared -fpic -o $@ $^

mains: $(OBJECTS_MAIN) libStrlist.so
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) ./libStrlist.so

clean:
	rm -f *.o *.so mains