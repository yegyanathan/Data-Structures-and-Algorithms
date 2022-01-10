#include <iostream>
#include <algorithm>
#include <vector>

//Insertion Sort.
//Best Case: O(n) => when sorted.
//Avg/Worst Case => when sorted in reverse order.
//Following code is in-place.
//online algo since it can accept data during the process.
//stable algo.

using namespace std;

void insertSort(vector<int> &vec, int n)
{
	int i,j,key;

	for(i = 1;i<=n-1;i++)
	{
		key = vec.at(i);

		j = i-1;

		
		while (j >= 0 && vec.at(j) > key){

			vec.at(j+1) = vec.at(j);  
           	j = j - 1;

		}
       		
       	vec.at(j+1) = key;

	}

}