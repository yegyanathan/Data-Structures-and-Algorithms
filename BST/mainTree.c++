#include <iostream>
#include <memory>
#include "BinarySearchTree.h"


using namespace std;

int main(){

	BinarySearchTree Tree;
	Node* R = Tree.getRoot();

	R = Tree.insertNode(R,7);
	R = Tree.insertNode(R,17);
	R = Tree.insertNode(R,18);
	R = Tree.insertNode(R,3);
	R = Tree.insertNode(R,66);
	R = Tree.insertNode(R,1002);
	R = Tree.insertNode(R,4);
	R = Tree.insertNode(R,22);

	Tree.DisplayAsc(R);

	cout << "\n\n";
	
	Tree.DisplayDesc(R);

	cout << "\n\n";

	R = Tree.deleteNode(R,18);
	R = Tree.deleteNode(R,1002);
	R = Tree.deleteNode(R,7);

	R = Tree.searchNode(R,66);

	R = Tree.insertNode(R,3);

	Tree.DisplayAsc(R);

	cout << "\n\n";


}


