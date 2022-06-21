//
//  TVector.cpp
//  lab25
//
//  Created by Діана on 16.05.2022.
//

#include "TVector.hpp"
#include <iostream>
#include <math.h>
using namespace std;
int R2::scalar(TVector *obj1, TVector *obj2){
    int res;
    res = obj1->getX()*obj2->getX()+obj1->getY()*obj2->getY();
    return res;
};
int R3::scalar(TVector *obj1, TVector *obj2){
    int res;
    res = obj1->getX()*obj2->getX()+obj1->getY()*obj2->getY()+obj1->getZ()*obj2->getZ();
    return res;
};
void R2::print(){
    cout<<"Vector R2 ("<<x<<", "<<y<<")"<<endl;
}
void R3::print(){
    cout<<"Vector R3 ("<<x<<", "<<y<<", "<<z<<")"<<endl;
}
int R2::length(){
    int res;
    res = sqrt(x*x+y*y);
    return res;
}
int R3::length(){
    int res;
    res = sqrt(x*x+y*y+z*z);
    return res;
}
