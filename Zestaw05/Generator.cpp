#include<iostream>
#define MAX 1000000

int main() {
    int numOp;
    std::cin >> numOp;

	for(int i=0; i<numOp; i++) {
		std::cout<<rand()%MAX <<"\n";
	}
	return 0;
}