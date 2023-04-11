.PHONY: all clean
CC := g++
LDFLAGS := -O3 -march=native

all: Generator.x Stack.x ONP.x

%.x: %.cpp
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.x
