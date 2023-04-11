#define MAX 1000000
#include<iostream>
#include "LinkedList.hpp"

int main(int argc, const char *argv[]) {
	
	int limit;
	int counter;
	char op;
	int x;
	int y;
	int tmp;

	std::cin >> limit;
	if(limit>MAX) throw std::out_of_range("the limit excedes the maximum number of possible operations");
	List l;
	counter = 0;

	while (std::cin>>op) {
		
		switch(op) {
			case 'F' :
				std::cin >> x;
				if(x>MAX || x<0) std::out_of_range("element not within bounds");
				if(l.size()<MAX)
					l.push_front(x);
				else std::out_of_range("list is full");
				break;
			case 'B' :
				std::cin >> x;
				if(x>MAX || x<0) {
					std::out_of_range("element not within bounds");
				}
				if(l.size()<MAX)
					l.push_back(x);
				else std::out_of_range("list is full");
				break;
			case 'f' :
				if(l.empty())
					std::cout << "EMPTY" << "\n";
				else
					std::cout << l.pop_front() << "\n";
				break;
			case 'b' :
				if(l.empty())
					std::cout << "EMPTY" << "\n";
				else
					std::cout << l.pop_back() << "\n";
				break;
			case 'R' :
				std::cin>> x;
				std::cin>> y;
				tmp = l.find(x);
				if(tmp==-1) std::cout<<"FALSE" << "\n";
				else {
					l.erase(tmp);
					l.insert(tmp, y);
					std::cout << "TRUE" << "\n";
				}
				break;
			case 'S' :
				std::cout<<l.size() << "\n";
		}
		
		counter++;
		if(counter>limit) throw std::out_of_range("number of operations performed excedes limit");
		
	}
	
	return 0;
}
