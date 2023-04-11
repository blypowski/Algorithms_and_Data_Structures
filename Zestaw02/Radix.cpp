#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
#include "LinkedQueue.hpp"
void radix(std::vector<int>& v); //sortuje wektor v
int main() {

	std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
	radix(v);

	for(const auto& i : v)
		std::cout << i << std::endl;
	
	return 0;
}

void radix(std::vector<int>& v) {
	//szukanie najwiekszego elementu
	int max=0;
	for(int i=0; i<v.size(); i++) {
		if(v[i]>max) max = v[i];
	}
	
	//znajdywanie ilosci cyfr najwiekszego elementu
	int digits = 0;
	int tmp = max;
	while(tmp != 0) {
		tmp = tmp/10;
		digits++;
	}
	
	Queue t[10];
	
	int liczba;
	int digit;
	for (int i = 0;i<digits;i++) {
		for (int j = 0; j<v.size();j++) {
			liczba = v[j];
			digit = (liczba/ (int)pow(10, i))%10;
			t[digit].push(liczba);
		}
		
		v.clear();
	
		for (int i =0; i<10;i++) {
			while(t[i].empty()==false) {
				int element = t[i].pop();
				v.push_back(element);
			}
		}
	}
}

