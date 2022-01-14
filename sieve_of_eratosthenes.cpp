#include <iostream>
using namespace std;
#include <vector>

template <typename S>

void with_separator(const vector<S>& vec,
                    string sep = " ")
{
    for (auto elem : vec) {
        cout << elem << sep;
    }
 
    cout << endl;
}

void print_array(bool arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

vector<int> sieveOfEratosthenes(int N)
{
    // Write Your Code here
    vector<int> answer;
    bool temp[N+1];
    for(int i = 0; i < N+1; i++){
        temp[i] = true;
    }
    temp[0] = false;
    temp[1] = false;
    for(int i = 2; i < N+1; i++){
        if(temp[i] == true){
            answer.push_back(i);
            for(int j = i*i; j < N+1; j+= i){
                temp[j] = false;
            }
        }
    }
    return answer;
}

int main(){

    vector<int> ans = sieveOfEratosthenes(35);
    cout << "The answer is : " ;
    with_separator(ans, ", ");

    return 0;
}