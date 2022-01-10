#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(vector<int> &array,int left,int middle,int right){

    vector<int> arrayLeft;
    vector<int> arrayRight;

    for (int i = 0; i < (middle-left+1); i++)
        arrayLeft[i] = array[left + i];

    for (int j = 0; j < (right-middle); j++)
        arrayRight[j] = array[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < (middle-left+1) && j < (right-middle)) {

        if (arrayLeft[i] <= arrayRight[j]) {

            array[k] = arrayLeft[i];
            i++;

        }
        else {

            array[k] = arrayRight[j];
            j++;

        }

        k++;

    }

    while (i < (middle-left+1)) {

        array[k] = arrayLeft[i];
        i++;
        k++;

    }
 
    while (j < (right-middle)) {

        array[k] = arrayRight[j];
        j++;
        k++;

    }

}

void mergeSort(vector<int> &array,int left,int right){

    if(left >= right){

        return;

    }

    int middle = (left + right)/2;

    mergeSort(array,left,middle);

    mergeSort(array,middle+1,right);

    merge(array,left,middle,right);

}