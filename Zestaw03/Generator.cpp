#include<iostream>
#define MAX 1000
int numOp = rand() % MAX;
int chosen;
char c;
char ops[] = {'F', 'B', 'f', 'b', 'R', 'S'};

int main() {
	for(int i=0; i<numOp; i++) {
		chosen = rand()%5;
		std::cout<<ops[chosen];
		if(chosen==0 || chosen==1) std::cout<<" "<<rand()%MAX;
		std::cout<<std::endl;
		if(chosen==4)
			std::cout << " " <<rand()%MAX << " " << rand()%MAX;
			
		std::cout << "\n";
	}
	return 0;
}
