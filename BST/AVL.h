#include <iostream>

using namespace std;


class Node{

    public:

        int val;
        int level;
        Node* left_c;
        Node* right_c;

        Node(){

            data = NULL;
            level = NULL;
            left_c = NULL;
            right_c = NULL;

        }

        Node(const int& v,const int& l){

            val = v;
            level = l;
            left_c = NULL;
            right_c = NULL;

        }

};

class AVL{

    public:

        Node* root;

        AVL(){ root = NULL; }

        Node* insertNode(Node* root, const int& val){

            if( root == NULL ) Node* newnode = new Node(val,root->level + 1);

            else if(val <= root->val) root->left_c = insertNode(root->left_c,val);

            else if(val > root->val) root->right_c = insertNode(root->right_c,val);

            return root;

        }

        int findHeight(Node* root) {

            if (root == NULL) return -1;

            int lefth = findHeight(root->left_c);
            int righth = findHeight(root->right_c);

            if (lefth > righth) return lefth + 1;
            
            else return righth + 1;

        }


        Node* insert(Node* root, const int& val){

            Node* rootInsert = insertNode(root,val);

            int balance = findHeight(rootInsert->left_c) - findHeight(rootInsert->right_c);

            if( balance > 1 ){

                if(findHeight(rootInsert->left_c->left_c) >= findHeight(rootInsert->left_c->right_c)){

                    rootInsert = rightRotate(rootInsert);

                }
                else{

                    rootInsert->left_c = leftRotate(rootInsert->left_c);
                    rootInsert = rightRotate(rootInsert);

                }

            }
            else if( balance < -1 ){

                if(findHeight(root->right_c->right_c) >= findHeight(rootInsert->right_c->left_c){

                    rootInsert = leftRotate(rootInsert);

                }
                else{

                    rootInsert->right_c = rightRotate(rootInsert->right_c);
                    rootInsert = leftRotate(rootInsert);

                }
                
            }

        }
}