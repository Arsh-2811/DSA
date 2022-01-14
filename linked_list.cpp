#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void print_list(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* sorted_insert(Node* head, int val){
    
    Node* temp = new Node(val);
    if(head == NULL){
        return temp;
    }
    if(head->data > val){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    while(curr->next->data < val && curr->next != NULL){
        curr = curr->next;
    }
    temp->next = curr->next;    // Pay attention to the order of the below two statements
    curr->next = temp;
    
    return head;
}

void print_middle(Node* head){
    if(head == NULL){
        return;
    }
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

void printNthfromEnd(Node* head, int n){
    if(head == NULL){
        return;
    }
    Node* first = head;
    for(int i = 0; i < n; i++){
        if(first == NULL){
            return;
        }
        first = first->next;
    }
    Node* second = head;
    while(first != NULL){
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(25);
    head->next->next->next->next->next = new Node(30);

    print_list(head);

    printNthfromEnd(head, 3);

    return 0;
}