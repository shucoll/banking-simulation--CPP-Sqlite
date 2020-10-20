#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
}*front=NULL,*rear=NULL;

class Queue {

    public:
        void enqueue(int x);
        int dequeue();
        int size();
};

void Queue::enqueue(int x) {

    Node *t = new Node; 
    if(t==NULL) cout<<"Queue full"<<endl;
    else {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else {
            rear->next=t;
            rear=t;
        }
    }
}

int Queue::dequeue() {

    int x=0;
    Node *t;

    if(front==NULL) {}//cout<<"Queue Empty"<<endl;
    else {
        x=front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}

int Queue::size() {
    
    Node *p=front;
    int len=0;
    while(p) {
        len++;
        p=p->next;
    }
    return len;
}