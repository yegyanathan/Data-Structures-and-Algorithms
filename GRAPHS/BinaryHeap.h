/*
 * The root is the second item in the array. We skip the index zero cell of the array for the convenience of implementation. Consider k-th element of the array, the array,
 * its left child is located at 2*k+1 index
 * its right child is located at 2*k+2 index
 * its parent is located at k/2 index.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class BinaryHeap{

	private:

		vector<int> Heap;

	public:

		BinaryHeap(){

		}
		
		BinaryHeap(int size){

			Heap.reserve(size);

		}

		int peekHeap(){

			if( Heap.capacity() == 0 ){

				return -1;

			}

			else{
				
				return Heap.at(0); //Return by value so that the value can't be changed further.

			}

		}

		int sizeofHeap(){

			int temp = Heap.size();
			return temp;

		}

		void SwapDown( int i ){

			int LC = 2*i+1;
			int RC = 2*i+2;
			int min = i;

			if( LC < Heap.size() && Heap.at(LC) < Heap.at(min) ){

				min = LC;

			}

			if( RC < Heap.size() && Heap.at(RC) < Heap.at(min) ){

                                min = RC;

                        }

			if( min != i ){

				swap(Heap.at(min),Heap.at(i));
				SwapDown(min);

			}

		}

		void Heapify(){

			for( int i = ((Heap.size())-2)/2 ; i>=0 ; i-- ){

				SwapDown(i);

			}

		}


		void insertHeap(const int& val){

			Heap.push_back(val);

			Heapify();

		}

		int ExtractMin() {
			
			int i = 0;
			int temp = Heap.front();
			Heap[i] = Heap.back();
			Heap.pop_back();
			
			SwapDown(i);

			return temp;

		}

		void printHeap(){

			cout << "[ ";

			for(int i = 0 ; i < Heap.size() ; i++ ){

				cout << Heap.at(i) << " ";

			}

			cout << "]\n";

		}
	
		~BinaryHeap(){

			Heap.clear();

		}

};
		

					
				





















