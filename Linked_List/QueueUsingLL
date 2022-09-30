#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};

class queue{
public:
    Node *head = NULL, *temp;

    void push(int x){
        Node* t= new Node(x);
        if(head == NULL){
            head = t;
            temp = head;
        }
        else{

            temp->next = t;
            temp = t;
        }
    }
    int pop(){
        if(head){
            int p = head->data;
            Node *del = head;
            head = head->next;
            delete del;
            return p;
        }
        else
            return -1;
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    q.push(40);
    cout<<q.pop()<<endl;
    return 0;
}
