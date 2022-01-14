#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Stack{
    queue<int> q1, q2;
    int curr_size;

    Stack(){
        curr_size = 0;
    }
    void push(int val){
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        curr_size++;
    }

    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
        curr_size--;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }

    int size(){
        return curr_size;
    }

};

void print_queue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout <<"\n";
}

void reverse_queue(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){

    // Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
 
    // cout << "current size: " << s.size() << endl;
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // cout << "current size: " << s.size() << endl;
    queue<int> q;
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    reverse_queue(q);
    print_queue(q);

    return 0;
}