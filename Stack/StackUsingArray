#include<iostream>
using namespace std;

class stack{
private:
    int arr[200];
    int size;
    int top;
public:
    stack(){
        size = 0;
        top = -1;
    }
    void push(int x){
        arr[++top] = x;
        size++;
    }
    int pop(){
        if(top == -1)
            return -1;
        size--;
        return arr[top--];
    }
    int Top(){
        return arr[top];
    }
    bool isEmpty(){
        return !size ? true : false;
    }
    int isSize(){
        return size;
    }

};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.Top()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.isSize()<<endl;

    return 0;
}
