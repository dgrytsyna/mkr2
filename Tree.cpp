
#include "Tree.hpp"
#include "myStack.hpp"
#include <iostream>
using namespace std;
Node* Tree::makeTree(int m[], int from, int n, int level){
    if(n==0) return NULL;
    Node* p = new Node(m[from]);
    int nl = n/2;
    int nr = n-nl-1;
    p->level = level;
    p->left = makeTree(m, from+1, nl, level+1);
    p->right = makeTree(m, from+nl+1, nr, level+1);
    return p;
}
Node* Tree::balancedTree(int m[], int from, int n, int level){
    if(n==0) return NULL;
    Node* p = new Node(m[from]);
    p->level = level;
    int *arrLeft = new int[n];
    int *arrRight = new int[n];
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
    if(k!=0) p->right = balancedTree(arrRight, k/2, k, level+1);
    if(j!=0) p->left = balancedTree(arrLeft, j/2, j, level+1);
    return p;
}
void Tree::printTree(const string& prefix, const Node* node, bool isLeft){
    if( node != nullptr ){
        cout<<prefix;
        cout<<(isLeft ? "|──" : "`──" );
        cout<<node->data;
        cout<<" lvl"+to_string(node->level);
        cout<<endl;
        printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
    
}
void Tree::deleteElement(Node *node){
    if(node != nullptr){
        if(node->data==4){
            node->data= 0;
            node = nullptr;
            delete node;
            return;
        }
        deleteElement(node->left);
        deleteElement(node->right);
    }
}
void Tree::checkBalance(Node* node){
    Node* current = node;
    myStack stack;
    int minH = -1;
    int maxH = 0;
    int stop = 0;
    while(stop==0){
        while(current!=NULL){
            stack.push(current);
            current = current->right;
        }
        if(stack.isEmpty()) stop = 1;
        else{
            Node* stackCurrent = stack.pop();
            current = stackCurrent;
            if(current->left==NULL&&current->right==NULL){
                if(current->level>maxH) maxH = current->level;
                if(minH==-1) minH = maxH;
                if(current->level<minH) minH=current->level;
            }
            cout<<current->data<<endl;
            current = current->left;
        }
    }
    cout<<"Min level "<<minH<<endl;
    cout<<"Max level "<<maxH<<endl;
    if(maxH-minH>1) cout<<"Not balanced"<<endl;
    else cout<<"Tree is balanced"<<endl;
}
void Tree::findElement(int value, Node* root){
    Node* current = root;
    int stop = 0;
    cout<<"FIND EL "<<value<<endl;
    while(current!=NULL&&stop==0){
        cout<<current->data<<endl;
        if(value<current->data) current = current->left;
        else{
            if(value>current->data) current = current->right;
            else stop = 1;
        }
    }
}
