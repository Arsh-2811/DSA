#include <bits/stdc++.h>
using namespace std;

/*Structure of a Stack implemented with array*/
struct Mystack{
    int* arr;
    int cap;
    int size;

    Mystack(int max){
        cap = max;
        arr = new int[cap];
        size = 0;
    }
    void push(int x){
        if(size == cap-1){
            cout << "Stack is full !!" << endl;
            return;
        }
        arr[size] = x;
        size++;
    }
    int pop(){
        if(size == 0){
            cout << "Stack is empty !!" << endl;
            return INT16_MIN;
        }
        // int res = arr[size];
        size--;
        int res = arr[size];
        return res;
    }
    int sized(){
        return size;
    }
    bool isEmpty(){
        if(size == 0){
            return true;
        }
        return false;
    }
    void printStack(){
        if(size == 0){
            cout << "Stack is empty !!" << endl;
            return;
        }
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*Structure of a Node of a linked list*/
struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

/*Structure of a Stack implemented with linked list*/
struct Stack{
    Node* head;
    int size;
    Stack(){
        size = 0;
        head = NULL;
    }
    void push(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        if(head == NULL){
            cout << "Stack is Empty !!" << endl;
            return INT16_MIN;
        }
        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    int sized(){
        return size;
    }
    int peek(){
        if(head == NULL){
            cout << "Stack is Empty !!" << endl;
            return INT16_MIN;
        }
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void printStack(){
        if(head == NULL){
            cout << "Stack is Empty !!" << endl;
            return;
        }
        Node* curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(5);

    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}