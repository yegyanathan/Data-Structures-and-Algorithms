#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* link;

};

struct LinkHead{

    int count;
    Node* head;

};

class SLL{

    public:

    LinkHead* Head;

    SLL(){

        Head = new LinkHead();
        Head->count = 0;
        Head->head = NULL;
        

    }

    void insertBack(int data){

        Node* newnode = new Node();
        newnode->data = data;
        newnode->link = NULL;

        if( Head->head != NULL ){

            Node* temp;
            temp = Head->head;

            while( temp->link != NULL){

                temp = temp->link;

            }

            temp->link = newnode;

        }
        else{

            Head->head = newnode;

        }

        Head->count += 1;

    }

    void insertFront(int data){

        Node* newnode = new Node();
        newnode->data = data;

        newnode->link = Head->head;
        Head->head = newnode;
        
    }

    void traverse(){

        Node* temp;
        temp = Head->head;

        do{

            cout << temp->data << "*";
            if( temp->link != NULL ) temp = temp->link;
        
        }while( temp->link != NULL);

        cout << endl;

    }

    void size(){

        cout << Head->count << endl;

    }

};