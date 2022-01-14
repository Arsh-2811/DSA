#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){    // Constructor
        data = x;
        next = NULL;
    }
};

void print_linked_list(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* insert_at_begin(Node* head, int x){
    Node* temp = new Node(x);
    temp->next = head;
    return temp;
}

Node* insert_at_end(Node* head, int x){
    Node* temp = new Node(x);
    if(head== NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node* del_first_element(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head->next;
    delete(head);
    return temp;
}
Node* del_last_element(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
    return head;
}

Node* insert_at_given_position(Node* head, int pos, int val){
    Node* temp = new Node(val);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    for(int i = 1; i <= pos-2 && curr!= NULL; i++){    // Good example of using two comparison function to terminate the for loop
        curr = curr->next;
    }
    if(curr == NULL){
        return head;
    }
    temp->next = curr->next;
    curr-> next = temp;
    return head;

}

int search_linked_list(Node* head, int val){
    Node* temp = head;
    int ans = 1;
    while(temp != NULL){
        if(temp->data == val){
            return ans;
        }
        temp = temp->next;
        ans++;
    }
    return -1;
}

int main(){

    Node* head = new Node(3);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 15);

    cout << search_linked_list(head, 3);

    return 0;
}