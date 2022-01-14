#include<iostream>
using namespace std;

struct Queues{
    int* arr;
    int start, end, capacity;

    Queues(int x){
        capacity = x;
        start = -1;
        end = -1;
        arr = new int[capacity];
    }

    void enque(int n){
        if(isfull()){
            cout << "The Queue is Full !!\n";
            return; 
        }
        if(start == -1){
            start = 0;
        }
        end = (end + 1)% capacity;
        arr[end] = n;
    }

    void deque(){
        if(isempty()){
            cout << "The Queue is Empty !!\n";
            return;
        }
        if(start == end){
            start = end = -1;
        }
        else{
            start = (start+1)%capacity;
        }
    }

    int front(){
        if(isempty()){
            cout << "The Queue is Empty !!\n";
            return 0;
        }
        return arr[start];
    }

    int rear(){
        if(isempty()){
            cout << "The Queue is Empty !!\n";
            return 0;
        }
        return arr[end];
    }

    bool isfull(){
        if((end + 1)%capacity == start){
            return true;
        }
        return false;
    }

    bool isempty(){
        if(start == -1 && end == -1){
            return true;
        }
        return false;
    }

};

int main(){
    
    Queues q(5);
    q.enque(5);
    q.enque(10);
    q.enque(15);
    q.deque();
    cout << q.front() << endl;
    cout << q.rear() << endl;

    return 0;
}