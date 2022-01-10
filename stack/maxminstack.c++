
/* Find maximum and minimum in stack in O(1) without using additional stack.
 * Design a stack which can get max and min in the stack in O(1) time without using additional stack. */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct Num{

	int data;
	int LocalMax;
	int LocalMin;

};

class MyStack : public stack<Num> {

	public:

		void Push(int val){

			Num temp;

			//initialising data field of temp variable.
			temp.data = val;
			
			//initialising LocalMax and LocalMin field of temp variable.
			if(this->empty()){

				temp.LocalMax = temp.data;
				temp.LocalMin = temp.data;

			}

			else{

				temp.LocalMax = max(temp.data,(this->top()).LocalMax);
				temp.LocalMin = min(temp.data,(this->top()).LocalMin);

			}

			this->push(temp);

		}

		int Max(){

			return (this->top()).LocalMax;

		}

		int Min(){

			return (this->top()).LocalMin;

		}
};

int main(){

	MyStack s;
	s.Push(8);
	s.Push(6);
	s.Push(3);
	s.Push(5);
	s.Push(1);
	int max = s.Max();
	int min = s.Min();

	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
}
