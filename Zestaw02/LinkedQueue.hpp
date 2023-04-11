#include<iostream>

struct Node {
    Node * next;
    int element;
};

class Queue {
	private:
		Node * head;
		Node * tail;
	public:
		Queue(); // Konstruktor domyślny
		void push(int x); // Wstawia element x do kolejki (także enqueue)
		int pop(); // Usuwa element z kolejki i zwraca jego wartość (dequeue)
		int size(); // Zwraca liczbę elementów w kolejce
		bool empty(); // Sprawdza czy kolejka jest pusta
};

Queue::Queue() {
	head = new Node;
	head->next = NULL;
	tail = head;
}

void Queue::push(int x) {
    Node * pushed = new Node;
    pushed->element = x;
    pushed->next = NULL;
    tail->next = pushed;
    tail = pushed;
}

int Queue::pop() {
	if(empty()) throw std::out_of_range("underflow");
        int x = head->next->element;
        Node * popped = head;
        head = head->next;
        delete popped;
        return x;
}

int Queue::size() {
	Node * i = head;
	int counter = 0;
	while(i->next!=NULL) {
		i=i->next;
		counter++;
	}
	return counter;
}

bool Queue::empty() {
    return head->next==NULL;
}
