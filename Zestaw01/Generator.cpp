#include<iostream>
#define MAX 1000000
int numOp = rand() % MAX;
int chosen;
char c;
char ops[] = {'A', 'D', 'S'};

int main() {
	for(int i=0; i<numOp; i++) {
		chosen = rand()%2;
		std::cout<<ops[chosen];
		if(chosen==0) std::cout<<" "<<rand()%MAX;
		std::cout<<std::endl;
	}
	return 0;
}
