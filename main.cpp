//
//  main.cpp
//  lab25
//
//  Created by Діана on 16.05.2022.
//

#include <iostream>
#include "TVector.hpp"
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    srand((unsigned int)time(NULL));
    TVector* arrVec[4];
    TVector *p;//створення покажчика на об'єкт базового типу
    R2 vecR2, vec2R2;//створення об'єктів похідних типів
    R3 vecR3, vec2R3;
    p = &vecR2;//присвоєння покажчику адреси об'єкта похідного класу
    p->set(rand()%9+1, rand()%9+1);
    arrVec[0] = p;
    p = &vec2R2;
    p->set(rand()%9+1, rand()%9+1);
    arrVec[1] = p;
    p = &vecR3;
    p->set(rand()%9+1, rand()%9+1, rand()%9+1);
    arrVec[2] = p;
    p = &vec2R3;
    p->set(rand()%9+1, rand()%9+1, rand()%9+1);
    arrVec[3] = p;
    for(int i=0; i<4; i++){
        arrVec[i]->print();
    }
    int s = vecR3.scalar(arrVec[2], arrVec[3]) + vecR2.scalar(arrVec[0], arrVec[1]) + arrVec[2]->length();
    cout<<"Result "<<s<<endl;
    return 0;
}
