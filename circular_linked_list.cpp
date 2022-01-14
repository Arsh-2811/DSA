#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printlist(Node* head){
    if(head == NULL){
        return;
    }
    cout << head-> data << " ";
    for(Node* p = head->next; p != head; p = p->next){
        cout << p->data << " ";
    }
    cout << endl;
}

Node* insert_at_beginning(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return temp;
}

Node* insert_at_beginning_betterway(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        return temp;
    }
    head->next = temp;
    temp->next = head->next;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
}

Node* insert_at_end(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    Node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
    return head;
}

Node* insert_at_end_better(Node* head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    head->next = temp;
    temp->next = head->next;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return temp;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    head = insert_at_beginning(head, 2);

    printlist(head);

    return 0;
}