//
//  Stack.cpp
//  tree6
//
//  Created by Діана on 21.06.2022.
//

#include "Stack.hpp"
void Stack::push(Node *node){
    if(top==NULL){
        StackNode* temp = new StackNode;
        temp->current = node;
        temp->prev = NULL;
        top = temp;
    }else{
        StackNode* temp = new StackNode;
        temp->current = node;
        temp->prev = top;
        top = temp;
    }
}
Node* Stack::pop(){
    StackNode* temp = new StackNode;
    Node* current = top->current;
    temp = top->prev;
    top = temp;
    return current;
}
bool Stack::isEmpty(){
    if(top==NULL) return true;
    else return false;
}
