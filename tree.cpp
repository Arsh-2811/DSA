#include<iostream>
using namespace std;
#include<queue>

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root != NULL){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void print_nodes_at_distance_k(Node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->val << " ";
    }
    else{
        print_nodes_at_distance_k(root->left, k-1);
        print_nodes_at_distance_k(root->right, k-1);
    }
}

void naive_level_order_traversal(Node* root){
    int h = height(root);
    for(int i = 0; i < h; i++){
        print_nodes_at_distance_k(root, i);
    }
}

void level_order_traversl(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout << curr->val << " ";
        q.pop();
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << "\n";
}

void level_order_traversal_linebyline(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->val << " ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

void level_order_traversal_linebyline_2(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();   // Hsve to mentio it before the for loop and not inside the foor loop because the size of the queue changes because of the for loop
        for(int i = 0; i < n; i++){
            Node* curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        cout << "\n";
    }
}

int size_of_binary_tree(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + size_of_binary_tree(root->left) + size_of_binary_tree(root->right);
}

int getMaximum(Node* root){
    if(root == NULL){
        return INT16_MIN;
    }
    return max(max(getMaximum(root->left), getMaximum(root->right)), root->val);
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);

    // inorder(root);
    // cout << "\n";
    // preorder(root);
    // cout << "\n";
    // postorder(root);
    // cout << "\n";

    // cout << height(root) << endl;

    // print_nodes_at_distance_k(root, 2);

    // naive_level_order_traversal(root);

    // level_order_traversl(root);

    // level_order_traversal_linebyline(root);

    level_order_traversal_linebyline_2(root);
    cout << size_of_binary_tree(root) << endl;
    cout << getMaximum(root) << endl;

    return 0;
}