#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "quickSort.h"

int main(){

    vector<int> vect{60,17,3,16,4,1,9,40};

    quickSort1(vect.begin(),vect.end());

    for(int ele : vect){

        cout << ele << " ";

    }

}