#include <iostream>
#include <algorithm>
#include <vector>

//Bubble Sort.
//Best Case: O(n) => when the array is already sorted.
//Avg/Worst Case: O(n^2) => when the array is sorted in reverse order.
//doesn't use extra space to sort => in order algorithm.
//can't accept new data during the process => offline algorithm.
//doesn't change order of element with the same value => stable algorithm.

using namespace std;

void bubbleSort(vector<int> &vec, int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      

    for (j = 0; j < n-i-1; j++) 
        if (vec.at(j) > vec.at(j+1)) 
            swap(vec.at(j), vec.at(j+1)); 

} 