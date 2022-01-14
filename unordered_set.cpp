#include <bits/stdc++.h>
using namespace std;

int main(){

    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.insert(20);

    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " " ;
    }
    cout << endl;

    cout << s.size() << endl;

    s.clear();
    cout << s.size() << endl;

    s.insert(5);
    s.insert(10);
    s.insert(15);
    s.insert(20);

    if(s.find(15) == s.end()){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found " << *s.find(15) << endl;
    }

    s.erase(15);
    cout << s.size() << endl;
    if(s.find(15) == s.end()){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found " << *s.find(15) << endl;
    }

    return 0;
}