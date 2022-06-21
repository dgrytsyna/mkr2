//
//  Stack.hpp
//  tree5
//
//  Created by Діана on 21.06.2022.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "Tree.hpp"
struct StackNode{
    Node* current;
    StackNode* prev;
};
class Stack{
    StackNode *top;
public:
    Stack(): top(NULL){};
    void push(Node *node);
    Node* pop();
    bool isEmpty();
};
#endif /* Stack_hpp */
