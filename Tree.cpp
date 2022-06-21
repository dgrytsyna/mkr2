//
//  Tree.cpp
//  tree3
//
//  Created by Діана on 20.06.2022.
//

#include "Tree.hpp"
#include "Stack.hpp"
#include <iostream>
using namespace std;
Node* Tree::makeTree(char m[], int from, int n){
    if(n==0) return NULL;
    char *arrLeft = new char[n];
    char *arrRight = new char[n];
    int j=0;
    int k=0;
    for(int i=0; i<n; i++){
        if(i<from){
            arrLeft[j] = m[i];
            j++;
        }else if(i>from){
            arrRight[k] = m[i];
            k++;
        }
    }
    Node *p = new Node(m[from]);
    p->left = makeTree(arrLeft, j/2, j);
    p->right = makeTree(arrRight, k/2, k);
    return p;
}
void Tree::printTree(const string& prefix, Node* node, bool isLeft){
    if(node!=nullptr){
        cout<<prefix;
        cout<<(isLeft? "|___":"`---");
        cout<<node->data;
        cout<<endl;
        printTree(prefix + (isLeft ? "|   ": "   " ), node->left, true);
        printTree(prefix + (isLeft ? "|   ": "   " ), node->right, false);
    }
}
void Tree::deleteDuplicates(Node* root, int size){
    char *symbArr = new char[size];
    int stop = 0;
    Node *current = root;
    int counter = 0;
    Stack stack;
    while(stop==0){
        while(current!=NULL){
            stack.push(current);
            current = current->left;
        }
        if(stack.isEmpty()) stop = 1;
        else{
            Node *stackNode = stack.pop();
            current = stackNode;
            symbArr[counter] = current->data;
            counter++;
            current = current->right;
        }
    }
    
    for(int i=0; i<counter; i++){
        cout<<symbArr[i]<<endl;
    }
    bool duplicate = false;
    for(int i=0; i<counter-1; i++){
        if(symbArr[i]!='\0'){
        for(int j=i+1; j<counter; j++){
            if(symbArr[i]==symbArr[j]) {
                symbArr[j] = '\0';
                duplicate = true;
            }
        }
            if(duplicate){
                symbArr[i] = '\0';
                duplicate = false;
            }
            
        }
    }
    char *newArr = new char[counter];
    int amount = 0;
    for(int i=0; i<counter; i++){
        if(symbArr[i]!='\0') {
            newArr[amount] = symbArr[i];
            amount++;
        }
    }
    Tree newTree;
    Node* newRoot = makeTree(newArr, amount/2, amount);
    newTree.printTree("", newRoot, false);
    newTree.postfix(newRoot);
}
void Tree::postfix(Node* root){
    int stop = 0;
    Node *current = root;
    Stack stack;
    while(stop==0){
        while(current!=NULL){
            stack.push(current);
            
            current = current->right;
        }
        if(stack.isEmpty()) stop = 1;
        else{
            Node *stackNode = stack.pop();
            current = stackNode;
            cout<<current->data<<endl;
            current = current->left;
            
        }
    }
}
