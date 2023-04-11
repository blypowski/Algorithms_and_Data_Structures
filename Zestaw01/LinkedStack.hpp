#include<iostream>
#define MAX 1000000
struct Node {
	int element;
	Node* prev;
};

class Stack {
	private:
		Node* top;
		int capacity;
	public:
		Stack();
		Stack(int cap);
		void push(int x);
		int pop();
		int size();
		bool empty();
};

Stack::Stack(int cap) {
	top = NULL;
	if(cap>=0) {
		capacity=cap;
	}
	else throw std::out_of_range("wrong number was input");
}

Stack::Stack() {
	capacity=MAX;
	this->top = NULL;
}

void Stack::push(int x) {
	//if(this->size()<this->capacity) {
		Node *tmp = new Node;
		tmp->element = x;
		tmp->prev = top;
		top = tmp;
		//std::cout<<top->element;
		//}
	//else throw std::out_of_range("can't push, stack is full");
}

int Stack::pop() {
	if(this->empty()) throw std::out_of_range("can't pop, stack is empty");
	else {
		int x;
		x = top->element;
		if(top->prev) {
			Node* tmp = top;
			top = top->prev;
			tmp->prev = nullptr;
			free(tmp);
		}
		else top=nullptr;
		return x;
	}
}

int Stack::size() {
	int x = 0;
	if(this->empty()) return 0;
	else {
		Node* count=top;
		while(count!=NULL) {
			count = count->prev;
			x++;	
		}

	}
	return x;
}

bool Stack::empty() {
	if(top) return false;
	else return true;
}
