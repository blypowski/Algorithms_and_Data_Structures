#include <iostream>
#include "BinaryTree.hpp"

int main() {
    int n;
    std::cin >> n;
    int i = 0;
    BST tree;

    int x;
    while(i<n) {
        std:: cin >> x;
        tree.insert(x);
    }

    std::cout << tree.size(tree.root);
    std::cout << tree.depth(tree.root);
    std::cout << tree.maximum();
    std::cout << tree.minimum();
    tree.preorder(tree.root);
    
    for(int liczba =1;liczba<=9;liczba++) {
        BSTNode * found = tree.search(liczba);
        if(found!=nullptr) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}