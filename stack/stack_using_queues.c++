#include <iostream>
#include <queue>
#include <string>

using namespace std;

template<class T>
class stack{

	private:

		queue<T> q1,q2;

	public:
		void Push(const T& value){

			q1.push(value);

		}

		void Pop(){

			T temp = q1.front();
			
			while( true ){
				
				
				if( temp != q1.back() ){
					
					q2.push(temp);
					q1.pop();
					temp = q1.front();
				}

				else{

					q1.pop();
					q1.swap(q2);
					break;
			}

			}

		}

		T& Front(){

			return q1.back();

		}

		T& Back(){

			return q1.front();

		}

};

			
int main(){

	stack<string> s;

	s.Push("yegi");
	s.Push("arjun");
	s.Push("raghul");
	
	
	cout<<s.Front()<<endl;

	s.Pop();
	s.Pop();
	s.Pop();

	cout<<s.Front()<<endl;

}
