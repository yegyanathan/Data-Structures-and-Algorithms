#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

int getTens(int num){

    return num%10;

}

int getHundreds(int num){

    return (num%100)/10;

}

int getThousands(int num){

    return num/100;

}

void emptyStack(stack<int> &stack,vector<int> &vect){

    while (!stack.empty()) {
        
        vect.push_back(stack.top());
        stack.pop();

    }

}

void radixSort(vector<int> &vec){

    stack<int> st0,st1,st2,st3,st4,st5,st6,st7,st8,st9;

    for(int ele : vec){

        switch(getTens(ele)){

            case 0:
                st0.push(ele);
                break;
            case 1:
                st1.push(ele);
                break;
            case 2:
                st2.push(ele);
                break;
            case 3:
                st3.push(ele);
                break;
            case 4:
                st4.push(ele);
                break;
            case 5:
                st5.push(ele);
                break;
            case 6:
                st6.push(ele);
                break;
            case 7:
                st7.push(ele);
                break;
            case 8:
                st8.push(ele);
                break;
            case 9:
                st9.push(ele);
                break;
        }

    }

    vector<int> pass1;

    emptyStack(st0,pass1);
    emptyStack(st1,pass1);
    emptyStack(st2,pass1);
    emptyStack(st3,pass1);
    emptyStack(st4,pass1);
    emptyStack(st5,pass1);
    emptyStack(st6,pass1);
    emptyStack(st7,pass1);
    emptyStack(st8,pass1);
    emptyStack(st9,pass1);



    for(int ele : pass1){

        switch(getHundreds(ele)){

            case 0:
                st0.push(ele);
                break;
            case 1:
                st1.push(ele);
                break;
            case 2:
                st2.push(ele);
                break;
            case 3:
                st3.push(ele);
                break;
            case 4:
                st4.push(ele);
                break;
            case 5:
                st5.push(ele);
                break;
            case 6:
                st6.push(ele);
                break;
            case 7:
                st7.push(ele);
                break;
            case 8:
                st8.push(ele);
                break;
            case 9:
                st9.push(ele);
                break;
        }

    }

    vector<int> pass2;

    emptyStack(st0,pass2);
    emptyStack(st1,pass2);
    emptyStack(st2,pass2);
    emptyStack(st3,pass2);
    emptyStack(st4,pass2);
    emptyStack(st5,pass2);
    emptyStack(st6,pass2);
    emptyStack(st7,pass2);
    emptyStack(st8,pass2);
    emptyStack(st9,pass2);


    for(int ele : pass2){

        switch(getThousands(ele)){

            case 0:
                st0.push(ele);
                break;
            case 1:
                st1.push(ele);
                break;
            case 2:
                st2.push(ele);
                break;
            case 3:
                st3.push(ele);
                break;
            case 4:
                st4.push(ele);
                break;
            case 5:
                st5.push(ele);
                break;
            case 6:
                st6.push(ele);
                break;
            case 7:
                st7.push(ele);
                break;
            case 8:
                st8.push(ele);
                break;
            case 9:
                st9.push(ele);
                break;
        }

    }

    vector<int> pass3;

    emptyStack(st0,pass3);
    emptyStack(st1,pass3);
    emptyStack(st2,pass3);
    emptyStack(st3,pass3);
    emptyStack(st4,pass3);
    emptyStack(st5,pass3);
    emptyStack(st6,pass3);
    emptyStack(st7,pass3);
    emptyStack(st8,pass3);
    emptyStack(st9,pass3);

    for(int ele : pass3){

        cout << ele << " ";
        
    }


}