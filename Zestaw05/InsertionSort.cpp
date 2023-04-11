#include<iostream>
#include<vector>
#include<algorithm>

void sort(std::vector<int>& v){
    for(auto i=v.begin();i!=v.end();i++) {
        std::vector<int>::iterator x = std::upper_bound(v.begin(),i, *i);
        std::rotate(x, i, i+1);
    }
}

int main() {
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);

    sort(v);
    for(const auto& i : v)
        std::cout << i << std::endl;
    
}