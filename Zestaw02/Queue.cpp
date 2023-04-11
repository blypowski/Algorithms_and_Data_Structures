#define MAX 1000000
#include<iostream>
#include "LinkedQueue.hpp"

int main(int argc, const char *argv[]) {
	
	int limit;
	int counter;
	char op;
	int x;

	std::cin >> limit;
	if(limit>MAX) throw std::out_of_range("the limit excedes maximum number of operations possible");
	Queue q;
	counter = 0;

	while (std::cin>>op) {
		
		switch(op) {
			case 'A' :
				std::cin >> x;
				q.push(x);
				break;
			case 'D' :
				if(q.empty())
					std::cout << "EMPTY" <<std::endl;
				else
					std::cout << q.pop() <<std::endl;
				break;
			case 'S' :
				std::cout << q.size() <<std::endl;
				break;
		}
		
		counter++;
		if(counter>limit) throw std::out_of_range("number of operations performed excedes limit");
		
	}
}
