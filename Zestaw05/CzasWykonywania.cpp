#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#define MAX 1000

void sort(std::vector<int>& v) {
    for(auto i=v.begin();i!=v.end();i++) {
        std::vector<int>::iterator x = std::upper_bound(v.begin(),i, *i);
        std::rotate(x, i, i+1);
    }
}

int main() {


    std::vector<int> sredni;
    std::vector<int> pesymistyczny;
    std::vector<int> optymistyczny;
    std::vector<double> czasOptymistyczny;
    std::vector<double> czasPesymistyczny;
    std::vector<double> czasSredni;

    int x;
    for(int numOp=0; numOp<1000;numOp+=100) {

        sredni.clear();
        optymistyczny.clear();
        pesymistyczny.clear();


        for(int i=0; i<numOp; i++) {
	    	x=rand()%MAX;
            sredni.push_back(x);
        }

        optymistyczny = sredni;
        sort(optymistyczny);
        pesymistyczny = optymistyczny;
        reverse(pesymistyczny.begin(), pesymistyczny.end());

        auto start = std::chrono::high_resolution_clock::now();
        sort(sredni);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        czasSredni.push_back(elapsed.count());

        start = std::chrono::high_resolution_clock::now();
        sort(optymistyczny);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        czasOptymistyczny.push_back(elapsed.count());

        start = std::chrono::high_resolution_clock::now();
        sort(pesymistyczny);
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        czasOptymistyczny.push_back(elapsed.count());
    
    }

    int n = czasSredni.size();

    for(int i =0;i<n;i++) {
        std::cout << czasSredni[i] << "\t" << czasOptymistyczny[i] << "\t" << czasPesymistyczny[i] <<"\n";
    }

    return 0;
}