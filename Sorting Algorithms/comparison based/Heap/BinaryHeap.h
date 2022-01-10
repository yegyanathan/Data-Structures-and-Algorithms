#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class BinaryHeap{

    private:

        vector<int> Heap;
        bool isMax;

    public:

        //contructors.
        BinaryHeap(vector<int> not_heap,bool ismax){

            Heap = not_heap;
            isMax = ismax;

            this->Heapify(this->Size());
        }

        BinaryHeap(int size,bool ismax){

            Heap.reserve(size);
            isMax = ismax;

        }

        //getting isMax.
        int getIsMax(){

            return isMax;

        }

        //return size 
        int Size(){

            return Heap.size();

        }

        //to return max from the heap.
        int Peak(){

            int top = (Heap.capacity()!=0)?Heap.at(0):-1;

            return top;

        }

        //swap down function for single index.
        void SwapDown( int i , int size ){

			int LC = 2*i+1;
			int RC = 2*i+2;
			int sub = i;

            if( isMax ){
                
                if( LC < size && Heap.at(LC) > Heap.at(sub) ){

                    sub = LC;

                }

                if( RC < size && Heap.at(RC) > Heap.at(sub) ){

                    sub = RC;

                }

                if( sub != i ){

                    swap(Heap.at(sub),Heap.at(i));
                    SwapDown(sub,size);

                }

            }
            else{

                if( LC < size && Heap.at(LC) < Heap.at(sub) ){

                    sub = LC;

                }

                if( RC < size && Heap.at(RC) < Heap.at(sub) ){

                    sub = RC;

                }

                if( sub != i ){

                    swap(Heap.at(sub),Heap.at(i));
                    SwapDown(sub,size);

                }

            }


		}

        //max_heapify a random array.
        void Heapify(int size){

			for( int i = (size-2)/2 ; i>=0 ; i-- ){

				SwapDown(i,size);

			}

		}

        //insert element.
        void Insert(const int& val){

            Heap.push_back(val);
            Heapify(this->Size());
            
        }

        //extract max, delete the top.
        int ExtractTop() {

			int temp = Heap.front();
			Heap[0] = Heap.back();
			Heap.pop_back();
			
			SwapDown(0,Heap.size());

			return temp;

		}

        //print max_heap.
        void printHeap(){

			cout << "[ ";

			for(int element : Heap){

				cout << element << " ";

			}

			cout << "]\n";

		}

        //opertor overload for [].
        int &operator[](int i) {

            return Heap[i];

         }

        //destructor.
        ~BinaryHeap(){

			Heap.clear();

		}
      
};


//Heap sorting.
void heapSort(const vector<int>& heap){

    BinaryHeap Heap(heap,true);

    int size = Heap.Size();

    while(size > 1){

        //swap top and last element.
        swap(Heap[0],Heap[size-1]);

        //reduce size of heap assuming
        //the last element is forbidden from access.
        size = size-1;

        //Heapify the non forbidden nodes.
        Heap.Heapify(size);

    }

    Heap.printHeap();

}