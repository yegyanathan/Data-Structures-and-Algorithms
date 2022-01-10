#include <iostream>
#include <algorithm>
#include <vector>

#include "insertionSort.h"

using namespace std;

int main(){

    vector<int> vec{5,2,9,11,23};

    insertSort(vec,vec.size());

    for(int ele : vec){

        cout << ele << " ";

    }
    
}