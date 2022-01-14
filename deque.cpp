#include <iostream>
#include <deque>
using namespace std;

// Structure of a Node of Double Linked list
struct Node{
    int val;
    Node* prev;
    Node* next;
    Node(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }
};


//Structure of Deque with implementation using Double Linked List
struct Deque{
    Node* head;
    Node* tail;
    int size;

    Deque(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertFront(int x){
        Node* temp = new Node(x);
        if(head == NULL){
            head = tail = temp;
            size++;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        size++;
    }

    void insertLast(int x){
        Node* temp = new Node(x);
        if(tail == NULL){
            head = tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        size++;
    }

    void deleteFront(){
        if(head == NULL){
            cout << "Deque is Empty !!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
            size = 0;
        }
        else{
            head->prev = NULL;
        }
        delete(temp);
        size--;
    }

    void deleteLast(){
        if(tail == NULL){
            cout << "Deque is Empty !!\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
            size = 0;
        }
        else{
            tail->next = NULL;
        }
        delete(temp);
        size--;
    }

    void printDeque(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr->val <<" ";
            curr = curr->next;
        }
        cout << "\n";
    }

    int getsize(){
        return size;
    }
};

// Data stucture with min and max operations in O(1) time.
struct MyDS{
    deque<int> dq;

    void insertMin(int x){
        dq.push_front(x);
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    int extractMin(){
        int res = dq.front();
        dq.pop_front();
        return res;
    }
    int extractMax(){
        int res = dq.back();
        dq.pop_back();
        return res;
    }
};

void maximum_in_all_subarrays_of_size_k(int arr[], int n, int k){
    deque<int> dq;

    for(int i = 0; i < k; i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = k; i < n; i++){
        cout << arr[dq.front()] << " ";
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl;
}

int main(){

    int arr[] = {20, 40, 30, 10, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    maximum_in_all_subarrays_of_size_k(arr, n, k);

    return 0;
}