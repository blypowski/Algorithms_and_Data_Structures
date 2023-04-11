#include<iostream>
#include<vector>

void sort(std::vector<int>& v) {
    int counter=0;
    bool swap = true;
    while(swap) {
        swap = false;
        for(auto i=v.begin();i!=v.end()-1;i++) {
            for(auto j=v.begin(); j<v.size()-i-1;j++)
            if(*i>*(i+1)) {
                counter++;
                iter_swap(i,i+1);
                swap = true;
            }
        }
    }

    std::cout << "Liczba operacji dominujacych wynosi: " << counter << "\n";
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
