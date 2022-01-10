#include <iostream>


using namespace std;



/* Node structure containing data and
 * pointers to its left and right child node. */
class Node{
	
	private:

	int data;
	Node* left_c; 
	Node* right_c;
	friend class BinarySearchTree;

	public:

	Node(){
		data = 0;
		left_c = NULL;
		right_c = NULL;

	}

	Node(const int& val){

		data = val;
		left_c = NULL;
		right_c = NULL;

	}

	~Node(){}

};


class BinarySearchTree{

	private:

		Node* root; //Root node of the BST.

	public:

		BinarySearchTree(){

			root == NULL;

		}

		/* searchNode searches for a given data
		 * from the currNode set to root by default. */
		Node* searchNode(Node* root , const int& val ){

			if( root == NULL ){

				return NULL;

			}

			else if( root->data == val ){
				
				cout << "Search Successful. \n\n";
				return root;

			}

			else if( val < root->data ){

				root->left_c = searchNode(root->left_c , val); // recursion.

			}

			else if( val > root->data ){

				root->right_c = searchNode(root->right_c , val);// recursion.

			}

		}
	
		/* insertNode inserts val
		 * accordingly in the tree. */
		Node* insertNode( Node* root , const int& val ){

			if( root == NULL ){

				root = new Node();
				root->data = val;

			}
			
			else if( val <= root->data ){

				root->left_c = insertNode( root->left_c , val );

			}

			else{

				root->right_c = insertNode( root->right_c , val );

			}

			return root;

		}
		
		/* InorderTraversal traverses the tree 
		 * and prints the node values in ascending order. */
		void Ascending(Node* root){

			Node* temp = root;

			if( temp == NULL ){

				return;

			}

			else{

				Ascending(temp->left_c);

				cout << temp->data << " "; 
	
				Ascending(temp->right_c);

			}


		}
		
		/* InorderTraversal traverses the tree
                 * and prints the node values in descending order. */
		void Descending(Node* root){
			
			Node* temp = move(root);

			if( temp == NULL ){

					return;

			}

			else{

					Descending(temp->right_c);

					cout << temp->data <<" ";

					Descending(temp->left_c);

			}

		}
		
		void DisplayAsc(Node* root){
			
			cout << "[" << " ";

			Ascending(root);

			cout << "]";

		}

		void DisplayDesc(Node* root){

			cout << "[" << " ";

			Descending(root);

			cout << "]";

		}

		
		/* Returns the node containing the minValue 
		 * in the tree corresponding to currNode. */
		Node* minValue(Node* root){

			while( (root->left_c) != NULL ){

				root = root->left_c;

			}

			return root;

		}


		/* deleteNode delete a given value from the tree. */
		Node* deleteNode( Node* root , const int& val ){

			if( root == NULL ){

				return NULL;

			}

			else if( val < root->data ){

				root->left_c = deleteNode( root->left_c , val );

			}

			else if(val > root->data ){

				root->right_c = deleteNode( root->right_c , val );

			}

			else if( root->data == val ){

				if( root->right_c != NULL && root->right_c != NULL ){

					Node* temp =  minValue(root->right_c);

					root->data = temp->data;

					root->right_c = deleteNode(root->right_c , temp->data );


				}

				else if( root->left_c == NULL) // only right child present.

				{	
					 Node *temp = root;

				 	 root = root->right_c;

					 delete temp;

					 return root;

				}

				else if( root->right_c == NULL) // only left child present.

				{
					Node* temp = root;

					root = root->left_c;

					delete temp;

					return root;

				}

				else{
					
					delete root;

					root = NULL;

				}

			}

			return root;

		}

		Node* getRoot(){

			Node*  r = this->root;

			return r;

		}
	       
	      
		void destroyBST(Node* temp){

			 if(temp->left_c != NULL){
				 
				 destroyBST( temp->left_c );

			 }

			 if(temp->right_c!=NULL){
				 
				 destroyBST( temp->right_c );

			 }

			 delete temp;
		}
		
		
		~BinarySearchTree(){


			delete root;

		}
		

};

