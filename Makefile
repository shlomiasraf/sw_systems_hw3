CC= gcc
FLAGS= -Wall -g 
OBJECTS_MAIN= Main.o

all: StrList
# Compile main.c	
Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c Main.c
# Compile StrList.c	
StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c
# Create the run file 	
StrList: $(OBJECTS_MAIN) StrList.o
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) ./StrList.o
# Clear everything we create
clean:
	rm -f *.o *.so StrList