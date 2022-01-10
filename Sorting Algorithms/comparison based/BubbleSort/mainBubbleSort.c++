#include <iostream>
#include <algorithm>
#include <vector>
#include "bubbleSort.h"

using namespace std;

int main(){

    vector<int> vec{1,5,7,3,4,6,9};

    bubbleSort(vec,vec.size());

    for(int ele : vec){

        cout << ele << " ";

    }
    
}