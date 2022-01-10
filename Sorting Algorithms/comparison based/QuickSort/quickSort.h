#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


vector<int>::iterator partition1(const vector<int>::iterator &low, const vector<int>::iterator &high){

    vector<int>::iterator itr1 = low;
    vector<int>::iterator itr2 = high;



    while( distance(low,itr1) < distance(low,itr2) ){

        do{

            itr1++;

        }while( *itr1 <= *low && itr1 != high ); 

        do{

            itr2--;

        }while( *itr2 > *low );

        if( distance(low,itr1) < distance(low,itr2) ){

            iter_swap(itr1, itr2);

        }

    }

    iter_swap (low, itr2);

    return itr2;

}



void quickSort1(const vector<int>::iterator &low, const vector<int>::iterator &high){

    if(distance(low,high) > 1){

        vector<int>::iterator temp = partition1(low,high);
        quickSort1(low,temp);
        quickSort1(next(temp),high);

    }

}


