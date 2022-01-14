#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_distinct_elements(int arr[], int n){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    return s.size();
}

void frequencies_of_array_elements(int arr[], int n){
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

int intersection_of_two_unsorted_arrays(int a1[], int a2[], int n1, int n2){
    unordered_set<int> s;
    for(int i = 0; i < n1; i++){
        s.insert(a1[i]);
    }
    int count = 0;
    for(int i = 0; i <n2; i++){
        if(s.find(a2[i]) != s.end()){
            count++;
            s.erase(a2[i]);
        }
    }
    return count;
}

bool pair_with_given_sum(int arr[], int n, int sum){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(sum-arr[i]) != s.end()){
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

bool subarray_with_zero_sum(int arr[], int n){
    unordered_set<int> psum;
    int sum = 0;
    for(int i =0; i < n; i++){
        sum += arr[i];
        if(sum == 0 || (psum.find(sum) != psum.end())){
            return true;
        }
        psum.insert(sum);
    }
    return false;
}

int longest_subarray_with_given_sum(int arr[], int n, int sum){
    unordered_map<int, int> m; // (prefix_sum, i)
    int ans = 0;
    int psum = 0;
    for(int i = 0; i < n; i++){
        psum += arr[i];
        if(psum == sum){
            ans = max(ans, i+1);
        }
        if(m.find(psum - sum) != m.end()){
            int tempans = i - m.find(psum - sum)->second;
            ans = max(ans, tempans);
        }
        m[psum] = i;
    }
    return ans;
}

void count_distinct_elements(int arr[], int n, int k){
    unordered_map<int, int> m;

    for(int i = 0; i < k; i++){
        m[arr[i]]++;
    }
    cout << m.size() << " ";

    for(int i = k; i < n; i++){
        m[arr[i-k]]--;
        if(m[arr[i-k]] == 0){
            m.erase(arr[i-k]);
        }
        m[arr[i]]++;
        cout << m.size() << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k  = 4;

    count_distinct_elements(arr, n, k);

    return 0;
}