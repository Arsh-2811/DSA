#include <bits/stdc++.h>
using namespace std;

bool ismatching(char s, char e){
    if(s == '('){
        if(e == ')'){
            return true;
        }
        return false;
    }
    else if(s == '{'){
        if(e == '}'){
            return true;
        }
        return false;
    }
    else if(s == '['){
        if(e == ']'){
            return true;
        }
        return false;
    }
}

bool  isStarting(char c){
    if(c == '(' || c == '{' || c == '['){
        return true;
    }
    return false;
}

bool balanced_paranthese(string str){
    stack<int> s;
    for(int i = 0; i < str.length(); i++){
        if(isStarting(str[i])){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
                return false;
            }
            else if(ismatching(s.top(), str[i])){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

struct kStacks{ 
    int *arr;   
    int *top;   
    int *next;  
    int cap, k; 
    int freeTop; 
    
    kStacks(int k1, int n){
        k = k1; cap = n; 
        arr = new int[cap]; 
        top = new int[k]; 
        next = new int[cap];
        
        for (int i = 0; i < k; i++) 
            top[i] = -1; 
        
        freeTop = 0;

        for (int i=0; i<cap-1; i++) 
            next[i] = i+1; 
        next[cap-1] = -1;
    } 
  
    bool isFull(){
        return (freeTop == -1);
    } 
  
    bool isEmpty(int sn){
        return (top[sn] == -1);
    }
    
    void push(int x, int sn){ 
        if (isFull()){ 
            cout << "\nStack Overflow\n"; 
            return; 
        }
        int i = freeTop;     
        freeTop = next[i]; 
        next[i] = top[sn]; 
        top[sn] = i;
        arr[i] = x; 
    } 
 
    int pop(int sn){ 
        if (isEmpty(sn)){ 
            cout << "\nStack Underflow\n"; 
            return INT_MAX; 
        }

        int i = top[sn]; 
        top[sn] = next[i];   
        next[i] = freeTop; 
        freeTop = i; 
        return arr[i]; 
    }
}; 

void stockspan(int arr[], int n){
    stack<int> s;
    s.push(0);
    cout << 1 << " ";
    for(int i = 1; i < n; i++){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        int span;
        if(s.empty()){
            span = i + 1;
        }
        else{
            span = i - s.top();
        }
        cout << span << " ";
        s.push(i);
    }
    cout << endl;
}

int main(){

    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    stockspan(arr, n);

    return 0; 
}