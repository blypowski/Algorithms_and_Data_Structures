#include<iostream>
#include "CursorList.hpp"

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
				//std::cout << "F " << x <<"\n";
				if(x>MAX || x<0) std::out_of_range("element not within bounds");
				else if(x==MAX) std::out_of_range("list is full");
				else
					l.push_front(x);
				break;
			case 'B' :
				std::cin >> x;
				//std::cout << "B " << x <<"\n";
				if(x>MAX || x<0) {
					std::out_of_range("element not within bounds");
				}
				if(l.size()<MAX)
					l.push_back(x);
				else std::out_of_range("list is full");
				break;
			case 'f' :
				//std::cout << "f \n";
				if(l.empty())
					std::cout << "EMPTY" << "\n";
				else
					std::cout << l.pop_front() << "\n";
				break;
			case 'b' :
				//std::cout << "b \n";
				if(l.empty())
					std::cout << "EMPTY" << "\n";
				else
					std::cout << l.pop_back() << "\n";
				break;
			case 'R' :
				std::cin>> x;
				std::cin>> y;
				//std::cout << "R " << x <<" " << y << "\n";
				tmp = l.find(x);
				if(tmp==-1) std::cout<<"FALSE" << "\n";
				else {
					l.erase(tmp);
					if(tmp==0) l.insert(tmp, y);
					else l.insert(tmp-1, y);
					std::cout << "TRUE" << "\n";
				}
				break;
			case 'S' :
				std::cout<<l.size() << "\n";
				break;
			case 'E' :
				std::cin>>x;
				std::cout<< "E " << x << "\n";
				l.erase(x);
				break;
			case 'O' :
				std::cin>>x;
				std::cout<< "F " << x << "\n";
				std::cout << "pozycja " << l.find(x) <<"\n";
				break;
			case 'I' :
				std::cin >> x;
				std::cin >> y;
				std::cout << "I " << x << " " << y << "\n";
				l.insert(x, y);
				break;
			case 'T' :
				l.traverse();
				break;
		}
		
		counter++;
		if(counter>limit) throw std::out_of_range("number of operations performed excedes limit");
		
	}
	
	return 0;
}
