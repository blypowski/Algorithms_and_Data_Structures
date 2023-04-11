.PHONY: all clean
CC := g++
LDFLAGS := -O3 -march=native

all: Queue.x Radix.x

%.x: %.cpp
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.x
