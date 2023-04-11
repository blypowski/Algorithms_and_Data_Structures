#include<iostream>
#include<vector>
#include<algorithm>

void sort(std::vector<int>& v) {
    int counter=0;
    bool swap = true;
    while(swap) {
        swap = false;
        for(auto i=v.begin();i!=v.end()-1;i++) {
            if(*i>*(i+1)) {
                counter++;
                iter_swap(i,i+1);
                swap = true;
            }
        }
    }
}

int main() {

    std::vector<int> v;

    sort(v);

    for(const auto& i: v)
        std::cout << i << std::endl;

}
