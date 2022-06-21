//
//  List.hpp
//  list
//
//  Created by Діана on 21.06.2022.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
struct Node{
    int data;
    Node* next;
    Node(): data(NULL), next(NULL){};
};
class List{
    Node* head;
    Node* tail;
public:
    Node* makeList();
    void listOut(Node *head);
    void deleteElement(int el, Node *head);
    void insertElement(Node *head);
    
};
#endif /* List_hpp */
