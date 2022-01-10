#include <iostream>
#include <algorithm>
#include <vector>

#include "BinaryHeap.h"

using namespace std;

int main(){
	
    vector<int> vect{11,19,44,4,1,13,3};

    BinaryHeap obj1(vect,true);

    obj1.printHeap();

    heapSort(vect);

}

	
