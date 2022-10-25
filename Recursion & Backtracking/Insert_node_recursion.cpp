#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* takeInput(){
    int data;
    cin >> data;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

Node* insertNodeRecursion(Node* head, int pos, int data){
    if(head == NULL){
        return head;
    }
    if(pos == 0){
        head -> data = data;
    }
    
    Node* temp = insertNodeRecursion(head -> next, pos-1, data);
    head -> next = temp;
    
    return head;
}

int main()
{
    Node* head = takeInput();
    int pos, data;
    cin >> pos >> data;  
    
    head = insertNodeRecursion(head, pos, data);
    print(head);

    return 0;
}