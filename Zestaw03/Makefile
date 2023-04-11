.PHONY: all clean
CC := g++
LDFLAGS := -O3 -march=native

all: LinkedList.x Generator.x

%.x: %.cpp
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.x
