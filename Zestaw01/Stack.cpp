#define MAX 1000000
#include<iostream>
#include "LinkedStack.hpp"
int limit;
char op;
int x;

int main(int argc, const char *argv[]) {

	std::cin >> limit;
	if(limit>MAX) throw std::out_of_range("the limit excedes maximum stack capacity");
	Stack s(limit);

	while (std::cin>>op) {
		
		switch(op) {
			case 'A' :
				std::cin >> x;
				s.push(x);
				break;
			case 'D' :
				if(s.empty())
					std::cout << "EMPTY" <<std::endl;
				else
					std::cout << s.pop() <<std::endl;
				break;
			case 'S' :
				std::cout << s.size() <<std::endl;
				break;
		}
	}
}
