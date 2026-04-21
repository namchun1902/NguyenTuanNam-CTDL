#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedListQueue{
private:
    Node* front; //tro dau hang
    Node* rear;  //tro cuoi hang
public:
    LinkedListQueue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int data){
        Node* newNode = new Node(data);

        //Neu node rong
        if (rear == nullptr){
            front = rear = newNode;
            cout << "Enqueue " << data << " to queue" << endl;
            return;
        }

        rear->next = newNode;
        rear = newNode;

        cout << "Enqueue " << data << " to queue" << endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Dequeue " << front->data << " from queue" << endl;

        front = front->next;

        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }
};