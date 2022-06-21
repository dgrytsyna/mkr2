//
//  Tree.hpp
//  tree3
//
//  Created by Діана on 20.06.2022.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct Node{
    char data;
    Node *left;
    Node *right;
    Node(char x): data(x), left(NULL), right(NULL){};
};
class Tree{
    Node *root;
public:
    Tree(): root(NULL){};
    Node* makeTree(char m[], int from, int n);
    void printTree(const string& prefix, Node* node, bool isLeft);
    void deleteDuplicates(Node* root, int size);
    void postfix(Node* root);
};
#endif /* Tree_hpp */
