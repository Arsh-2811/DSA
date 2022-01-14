#include <iostream>
using namespace std;

int sumOfElements(int A[], int n){    // This is actually interpreted by the compiler as " int sumOfElements(int* A){ " which means here A is just pointer to the first value in the original array
    // int n = sizeof(A)/ sizeof(A[0]);    // We cannot do this, so we need to pass the size of the array
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    return sum;
}

int main(){

    int A[5] = {1, 2, 3, 4, 5};
    int n = sizeof(A)/ sizeof(A[0]);
    int total = sumOfElements(A, n);    // As the array is passes as reference to the function, we can midify the actual array inside the function
    cout << "The sum of elements is : " << total << endl;

    return 0;
}