
CC=g++

CFLAGS=-g -Wall
OBJS=ExtendableArray.o driver1.o 
TARGET=test
$(TARGET): $(OBJS)
	$(CC) -g -o $@ $(OBJS)


driver1.o: ExtendableArray.h driver1.cpp
ExtendableArray.o: ExtendableArray.h ExtendableArray.cpp
clean:
	rm -rf *.o
	rm -f test
