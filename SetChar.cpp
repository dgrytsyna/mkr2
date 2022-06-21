//
//  SetChar.cpp
//  setchar
//
//  Created by Діана on 21.06.2022.
//

#include "SetChar.hpp"
#include <iostream>
void Set_Char::insert(char x){
    if(top==NULL){
        Node* temp = new Node(x);
        top = temp;
        top->prev = NULL;
    }else{
        Node* temp = new Node(x);
        temp->prev = top;
        top = temp;
    }
}
bool Set_Char::findEl(char x){
    Node* current = top;
    bool found = false;
    while(current){
        if(current->data==x){
            found = true;
            break;
        }
        current = current->prev;
    }
    return found;
}
Node* Set_Char::getTop(){
    return top;
}
ostream& operator<<(ostream& cout, Set_Char& n){
    Node*curr = n.getTop();
    while(curr){
        cout<<curr->data<<endl;
        curr = curr->prev;
    }
    return cout;
}
Set_Char findUnique(Set_Char s1, Set_Char s2){
    Node* top1 = s1.getTop();
    Node* top2 = s2.getTop();
    Set_Char s3;
    while(top1){
        bool hasDuplicate = false;
        while(top2){
            hasDuplicate = s2.findEl(top1->data);
            if(hasDuplicate) break;
            else top2 = top2->prev;
        }
        if(hasDuplicate==false){
            s3.insert(top1->data);
        }
        top2 = s2.getTop();
        top1 = top1->prev;
    }
    top1 = s1.getTop();
    while(top2){
        bool hasDuplicate = false;
        while(top1){
            hasDuplicate = s1.findEl(top2->data);
            if(hasDuplicate) break;
            else top1 = top1->prev;
        }
        if(hasDuplicate==false&&!(s3.findEl(top2->data))){
            s3.insert(top2->data);
        }
        top1 = s1.getTop();
        top2 = top2->prev;
    }
    return s3;
}
