//
//  TVector.hpp
//  lab25
//
//  Created by Діана on 16.05.2022.
//

#ifndef TVector_hpp
#define TVector_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
class TVector{ //базовий клас
protected:
    int x, y, z;
public:
    void set(int xx, int yy, int zz=0){x=xx; y=yy; z=zz;}
    int getX(){return x;};
    int getY(){return y;};
    int getZ(){return z;};
    virtual int scalar(TVector *obj1, TVector *obj2)=0; //скалярний добуток
    virtual int length()=0;//довжина вектора
    virtual void print()=0;
};
class R2: public TVector{//вектор 2D
public:
    int scalar(TVector *obj1, TVector *obj2);
    int length();
    void print();
};
class R3: public TVector{//вектор 3D
public:
    int scalar(TVector *obj1, TVector *obj2);
    int length();
    void print();
};

#endif /* TVector_hpp */
