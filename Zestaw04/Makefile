.PHONY: all clean
CC := g++
LDFLAGS := -O3 -march=native

all: CursorList.x ArrayList.x

%.x: %.cpp
	$(CC) $(LDFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.x
