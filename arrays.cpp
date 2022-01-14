#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int nearest_perfect_square(int n){
    int a = sqrt(n);
    int b, c;
    if(a*a == n){
        b = a-1;
        c = a + 1;
    }
    else{
        b = a;
        c = a + 1;
    }
    b = b*b;
    c = c*c;
    if(n-b < c-n){
        return b;
    }
    else{
        return c;
    }
}

int main() {
	//code
	long long int arr[100];
    int n;
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
	    int ans = nearest_perfect_square(arr[i]);
	    cout << ans << endl;
	}
	
	return 0;
}