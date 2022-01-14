#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int minCoins(int coins[], int n, int amount){
    // print_arr(coins, n);
    sort(coins, coins + n, greater<int>());
    // print_arr(coins, n);
    int res = 0;
    for(int i = 0; i < n; i++){
        if(coins[i] <= amount){
            int c = amount / coins[i];
            // cout << amount << " " << coins[i] << " " << c << endl;
            res += c;
            amount = amount % coins[i];
            if(amount == 0){
                break;
            }
        }
    }
    return res;
}

int main(){

    int coins[] = {1, 2, 5, 10};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 52;

    cout << minCoins(coins, n, amount) << endl;

    return 0;
}