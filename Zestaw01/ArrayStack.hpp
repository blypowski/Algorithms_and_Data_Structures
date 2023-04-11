#define MAX 1000000
#include<iostream>

//stos implementacja tablicowa

class Stack {
	private:
		int t[MAX];
		int top;
		int maxSize;
	public:
		Stack(int capacity);
		void push(int x);
		int pop();
		int size();
		bool empty();
};

Stack::Stack(int capacity) {
	maxSize = capacity;
}

void Stack::push(int x) {
	if(size()<maxSize) t[top++]=x;
	else throw std::out_of_range("overflow");
}

int Stack::pop() {
	if(size()>0) return t[--top];
	else throw std::out_of_range("underflow");
}

int Stack::size() {
	return top;
}

bool Stack::empty() {
	if(top>0) return false;
	else return true;
}
