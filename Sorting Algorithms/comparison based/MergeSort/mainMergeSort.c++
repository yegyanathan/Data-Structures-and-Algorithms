#include <iostream>
#include <algorithm>
#include <vector>

#include "mergeSort.h"

using namespace std;

int main(){

    vector<int> vec{5,2,9,11,23,1,6};

    mergeSort(vec,0,vec.size()-1);

    for(int ele : vec){

        cout << ele << " ";

    }  
}