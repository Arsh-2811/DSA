#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* previous;
    Node* next;
    Node(int x){
        data = x;
        previous = NULL;
        next = NULL;
    }
    void printNode(){
        cout << "Data : " << data << " Previous : " << previous << " Next : " << next << endl;
    }
};

void printlist(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* reverse_doubly_linked_list(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* temp = NULL;
    while(curr != NULL){
        temp = curr->previous;
        curr->previous = curr->next;
        curr->next = temp;
        curr = curr->previous;
    }
    return temp->previous;
}

int main(){

    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp1;
    temp1->previous = head;
    temp1->next = temp2;
    temp2->previous = temp1;

    printlist(head);
    head = reverse_doubly_linked_list(head);
    printlist(head);

    return 0;
}