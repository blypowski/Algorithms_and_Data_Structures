#include<iostream>
#include<vector>
#include<algorithm>

void sort(std::vector<int>& v){

    std::vector<int>::iterator n = v.end();
    std::vector<int>::iterator min;
    for(auto i=v.begin();i!=n;i++) {
        min = std::min_element(i,n);
        std::iter_swap(i, min);
    }
}
int main() {
    int x;
    std::vector<int> v;
    while(std::cin >> x)
        v.push_back(x);

    sort(v);

    for(const auto& i: v)
        std::cout << i << std::endl;
}