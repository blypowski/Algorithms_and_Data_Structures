#include<iostream>

class Queue {
    int read;
    int write;
    int t[MAX];
Queue(); // Konstruktor domyślny
void push(int x); // Wstawia element x do kolejki (także enqueue)
int pop(); // Usuwa element z kolejki i zwraca jego wartość (dequeue)
int size(); // Zwraca liczbę elementów w kolejce
bool empty(); // Sprawdza czy kolejka jest pusta
};

/*
uint32 read;
uint32 write;
mask(val)  { return val & (array.capacity - 1); }
push(val)  { assert(!full()); array[mask(write++)] = val; }
shift()    { assert(!empty()); return array[mask(read++)]; }

empty()    { return read == write; }
full()     { return size() == array.capacity }
size()     { return write - read; }
*/

void Queue::push(int x) {
    assert(size()< MAX);
    t[write++ % MAX] = x;
}

int Queue::pop() {
    assert(!empty()); return t[read++ % MAX];
}

bool Queue::empty() {
    return read == write;
}

int Queue::size() {
    return write - read;
}





