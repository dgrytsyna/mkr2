//
//  SetChar.hpp
//  setchar
//
//  Created by Діана on 21.06.2022.
//

#ifndef SetChar_hpp
#define SetChar_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct Node{
    char data;
    Node* prev;
    Node(char x): data(x), prev(NULL){};
};
class Set_Char{
    Node *top;
public:
    Set_Char(): top(NULL){};
    void insert(char x);
    bool findEl(char x);
    Node* getTop();
    friend ostream &operator<<(ostream&, Set_Char&);
};
Set_Char findUnique(Set_Char s1, Set_Char s2);
#endif /* SetChar_hpp */
