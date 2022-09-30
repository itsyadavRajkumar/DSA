#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }
};

class stack{
private:
    Node* head = NULL;
public:
    void push(int x){
        Node* temp = new Node(x);
        if(head == NULL)
            head = temp;
        else
            temp->next = head;
            head = temp;
    }
    int pop(){
        if(head == NULL)
            return -1;
        int top = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return top;
    }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}
