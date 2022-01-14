#include <iostream>
using namespace std;

struct MyHash{
    // Class Variables
    int* arr;
    int cap, size;

    // Constructor
    MyHash(int c){
        cap = c;
        size = 0;
        arr = new int[cap];
        for(int i = 0; i < cap; i++){
            arr[i] = -1;
        }
    }

    int hash(int key){
        return key%cap;
    }

    bool insert(int key){
        if(size == cap){
            return false;
        }
        int i = hash(key);
        while(arr[i] != -1 && arr[i] != -2 && arr[i] != key){
            i = (i + 1)%cap;
        }
        if(arr[i] == key){
            return false;
        }
        else{
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool search(int key){
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){
                return true;
            }
            i = (i+1)%cap;
            if(i == h){
                return false;
            }
        }
        return false;
    }

    bool erase(int key){
        int h = hash(key);
        int i = h;
        while(arr[i] != -1){
            if(arr[i] == key){
                arr[i] = -2;
                size--;
                return true;
            }
            i = (i+1)%cap;
            if(i == h){
                return false;
            }
        }
        return false;
    }
    void print_Hash_Table(){
        for(int i = 0; i < cap; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

};

int main(){

    MyHash mh(7);
    mh.print_Hash_Table();
    mh.insert(49);
    mh.print_Hash_Table();
    mh.insert(56);
    mh.print_Hash_Table();
    mh.insert(72);
    mh.print_Hash_Table();
    if(mh.search(56) == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    mh.erase(56);
    mh.print_Hash_Table();
    if(mh.search(56) == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}