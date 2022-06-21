//
//  List.cpp
//  list
//
//  Created by Діана on 21.06.2022.
//

#include "List.hpp"
#include <iostream>
using namespace std;
Node* List::makeList(){
    Node* head = NULL;
    char n;
    cout<<"Add element"<<endl;
    do{
        Node* current = new Node;
        cin>>current->data;
        current->next = NULL;
        if(head==NULL) head = current;
        else tail->next = current;
        tail = current;
        cout<<"Continue? (Y/N)";
        cin>>n;
    }while((n!='n')&&(n!='N'));
    return head;
    
}
void List::listOut(Node* head){
    Node* current = head;
    cout<<"LIST"<<endl;
    while(current){
        cout<<current->data<<endl;
        current = current->next;
    }
}
void List::insertElement(Node *head){
    Node* prev = head;
    while(prev){
        if(prev->data==3){
            cout<<"Enter element "<<endl;
            Node* current = new Node;
            cin>>current->data;
            cout<<endl;
            current->next = prev->next;
            prev->next = current;
        }
        prev = prev->next;
    }
}
void List::deleteElement(int el, Node *head){
    Node* prev = head;
    bool check = false;
    while(prev){
        if(prev->data==el){
            check = true;
            Node* current = new Node;
            current = prev->next;
            prev->next = current->next;
        }
        prev = prev->next;
    }
    if(check==false){
        cout<<"Not found";

    }
}
