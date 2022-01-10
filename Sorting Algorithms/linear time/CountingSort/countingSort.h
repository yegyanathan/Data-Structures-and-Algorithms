#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void countSort(vector<int> &vect, int range){

    vector<int> count;
    vector<int> answer;

    count.reserve(range+1);
    answer.reserve(vect.size());

    count.assign(range+1,0);
    answer.assign(vect.size(),0);

    for(int ele : vect){

        (count.at(ele))++;

    }

    /*
    for(int ele : count){

        cout << ele << " ";

    }
    */

   for(int i = 1; i < count.size(); i++){

       count.at(i) = count.at(i-1) + count.at(i);

   }

   for(int j = vect.size()-1; j >= 0; j--){

       answer.at(--(count.at(vect.at(j)))) = vect.at(j);

   }

    for(int ele : answer){

        cout << ele << " ";

    }

}