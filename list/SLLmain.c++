#include<iostream>
#include "SLL.h"

using namespace std;

int main(){

    SLL mySLL;
    mySLL.insertBack(8);
    mySLL.insertBack(7);
    mySLL.insertBack(2);
    mySLL.insertBack(3); 

    mySLL.traverse();
    mySLL.size();

}