#include<iostream>


struct BSTNode {
    BSTNode * up;
    BSTNode * left;
    BSTNode * right;
    int element;
};

class BST {
    public:
        BSTNode * root;
        BST();
        void insert(int x); //wstawia element x do drzewa
        BSTNode * search(int x); //iteratywny search
        BSTNode * searchRecursive(int x, BSTNode * i); //sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr. Napisać wersję iteracyjną i rekurencyjną
        int size(BSTNode * i); //zwraca liczbę węzłów
        int minimum(); //zwraca wartość najmniejszego elementu
        int maximum(); //zwraca wartość największego elementu
        int depth(BSTNode * i); //zwraca wysokość drzewa
        void inorder(BSTNode * i);
        void preorder(BSTNode * i);
        void postorder(BSTNode * i); //wypisuje zawartość wszystkich węzłów odpowiednio w porządku inorder, preorder i postorder. Wykorzystać rekurencje
};

BST::BST() {
    root = nullptr;
}

void BST::insert(int x) {

}

BSTNode * BST::search(int x) {
    BSTNode * i = root;
    while(i!=nullptr) {
        if(x>i->element) i = i->right;
        else if (x<i->element) i = i->left;
        else return i;
    }
    return nullptr;
}

BSTNode * BST::searchRecursive(int x, BSTNode * i) {
    if(i==nullptr || i->element == x)
        return i;
    if(i->element < x) return searchRecursive(x, i->right);
    return searchRecursive(x, i->left);
}

int size(BSTNode * i) {
    if(i==nullptr)
        return 0;
    else
        return(size(i->left) + size(i->right) +1);
}

int BST::minimum() {
    BSTNode * i = root;
    if(i){
        while (i->left){
            i = i->left;
        }
    }
    return i->element;
}

int BST::maximum() {
    BSTNode * i = root;
    if(i){
        while (i->right){
            i = i->right;
        }
    }
    return i->element;
}

int BST::depth(BSTNode * i) {
    if(i==nullptr)
        return -1;
    else {
        int l = depth(i->left);
        int r = depth(i->right);
        if(l>r) return (l+1);
        else return (r+1);
    }
}

void BST::inorder(BSTNode * i) {
    if(i) {
        inorder(i->left);
        std::cout << i->element << "\n";
        inorder(i->right);
    }
}

void BST::preorder(BSTNode * i) {
    if(root) {
        std::cout << i->element << "\n";
        preorder(i->left);
        preorder(i->right);
    }
}

void BST::postorder(BSTNode * i) {
    if(i) {
        postorder(i->left);
        postorder(i->right);
        std::cout << i->element << "\n";
    }
}

