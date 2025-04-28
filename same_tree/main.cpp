#include <iostream>

#include "bst.h"

bool isSameTree(bst_node_t* p, bst_node_t* q){
    bool same = true;
        if(p && q){
            if(p->value != q->value) same = false;
            if(p->left != nullptr && q->left != nullptr){
                if(isSameTree(p->left, q->left) == false) same = false;
            }
            if(p->right != nullptr && q->right != nullptr){
                if(isSameTree(p->right, q->right) == false) same = false;
            }
            if((p->right && q->right == nullptr) || (p->right && q->right == nullptr) || (p->right == nullptr && q->right) || (p->left == nullptr && q->left))
                same = false;
        }
        else if((p == nullptr && q) || (p && q == nullptr)) same = false;

        return same;
}

int main(){
    bst_node_t* f = bst_node_alloc(1);
    bst_node_insert(f, 2);
    bst_node_insert(f, 3);

    bst_node_t* s = bst_node_alloc(1);
    bst_node_insert(s, 2);
    bst_node_insert(s, 3);

    std::cout << isSameTree(f, s) << '\n';

    bst_node_free(f);
    bst_node_free(s);

    return EXIT_SUCCESS;
}