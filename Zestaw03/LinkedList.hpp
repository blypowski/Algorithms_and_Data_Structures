#include <iostream>

struct Node {
    Node * prev;
    Node * next;
    int element;
};

class List {
	private:
		Node * guard;
	public:
		List();
		void push_front(int x); // Dołącza element na początek listy
		int pop_front(); // Usuwa i zwraca element z początku listy
		void push_back(int x); // Dołącza element na koniec listy
		int pop_back(); // Usuwa i zwraca element z końca listy
		int size(); // wraca liczbę elementów w liście
		bool empty(); // CHECK Zwraca true gdy lista jest pusta
		void clear(); // Czyści listę
		int find(int x); // Zwraca pozycję pierwszego elementu o wartości x
		int erase(int i); // Usuwa i zwraca element na pozycji i
		void insert(int i, int x); // Wstawia element x przed pozycję i
		int remove(int x); // Usuwa wystąpienia x i zwraca ich liczbę
};

List::List() {
    guard = new Node;
    guard->next = guard;
    guard->prev = guard;
    guard->element = 0;
}

void List::push_front(int x) {
	Node * newhead = new Node;
	newhead->element = x;
	newhead->next = guard->next;
	newhead->prev = guard;
	guard->next->prev = newhead;
	guard->next = newhead;
	guard->element++;
}

void List::push_back(int x) {

    Node * newtail = new Node;
    newtail->element = x;
    
    newtail->next = guard;
    newtail->prev = guard->prev;
    guard->prev->next = newtail;
    guard->prev = newtail;
    
    
    guard->element++;
    
}

void List::insert(int i, int x) {
	
    Node * inserted = new Node;
    inserted->element = x;
    Node * finder = guard;
    int counter = 0;
    while(counter<i) {
        finder = finder->next;
        counter++;
    }
    
    inserted->next = finder->next;
    finder->next->prev = inserted;
    finder->next = inserted;
    inserted->prev = finder;
    guard->element++;

}

int List::pop_front() {
	if(empty()) throw std::out_of_range("underflow");
	int x = guard->next->element;
	Node * popped = guard->next;
	guard->next = popped->next;
	popped->next->prev=guard;
	delete popped;
	guard->element--;
	return x;
}

int List::pop_back() {
	if(empty()) throw std::out_of_range("underflow");
	Node * popped = guard->prev;
	int x = popped->element;
	
	guard->prev = popped->prev;
	guard->prev->next = guard;
	delete popped;
	guard->element--;
	return x;
}

int List::erase(int i) {
	if (i>size() || i<0) throw std::out_of_range("element you want to delete is out of range");
	Node * tmp = guard->next;
	int counter = 0;
	while(counter<i) {
		tmp = tmp->next;
		counter++;
	}
	int x = tmp->element;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	guard->element--;
	
	return x;
}

int List::size() {
    
    return guard->element;
}

int List::find(int x) {

    Node * i = guard->next;
    int counter = 0;
    
    while(i != guard) {
        if(i->element == x) {
            return counter;
        }
       i = i->next;
       counter++;
    }
    return -1;
    
}

bool List::empty() {
	return (guard->element==0);
}

void List::clear() {
	Node * i = guard->next;
	Node * tmp = i;
	if(!empty())
	while(i->next!=guard) {
		tmp = i;
		i=i->next;
		delete tmp;
	}
	guard->element = 0;
	
		
}

int List::remove(int x) {
	if(empty()) throw std::out_of_range("cannot find the element - list is empty"); 
	Node * i = guard;
	int counter = 0;
	while(i->next!=guard) {
		if(i->element == x) {
		Node * tmp = i;
		i=i->next;
		delete tmp;
		counter++;
	}
	else {
		i = i->next;
	}
    }
    return counter;
}
