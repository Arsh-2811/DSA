#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int arr[], int n){    // Bubble sort is a stable sorting algorithm and also in place as it does not require any extra array to copy the elements

    for(int i = 0; i < n-1; i++){
        bool swapped = false;    // This is a bool to break the for loop in between if the array has been already sorted 

        for(int j = 0; j < n-i-1; j++){    // This is an optimisation for the original bubble sort method
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
    }
}

void selection_sort(int arr[], int n){    // Not a stable algorithm but is inplace
    for(int i = 0; i < n - 1; i++){
        int temp_min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[temp_min]){
                temp_min = j;
            }
        }
        swap(arr[i], arr[temp_min]);
    }
}

void insertion_sort(int arr[], int n){    // Stable algorithm and inplace
    for(int i = 1; i < n; i++){
        int element = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > element){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}

void merge_two_sorted_arrays(int a1[], int a2[], int n1, int n2){
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
        if(a1[i1] <= a2[i2]){
            cout << a1[i1] << " ";
            i1++;
        }
        else{
            cout << a2[i2] << " ";
            i2++;
        }
    }
    if(i1 == n1){
        for(int i = i2; i < n2; i++){
            cout << a2[i2] << " ";
        }
    }
    else{
        for(int i = i1; i < n1; i++){
            cout << a1[i1] << " ";
        }
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int h){    // This function has a time complexity of theta(n) and space requires an auxilary space of theta(n)
    int n1=m-l+1, n2=h-m;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++){
        left[i] = arr[i+l];
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[m+1+j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i < n1){
        arr[k++] = left[i++];
    }
    while(j < n2){
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int l, int r){    // It is a Divide and Conquer algorithm
    if(r > l){    // This is to check that at least there are two elements there because there is nothing to sort if there is just one element
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int naive_partition(int arr[], int l, int h, int p){
    int temp[h-l+1], index = 0;
    for(int i = l; i <=h; i++){
        if(arr[i] <= arr[p] && i != p){
            temp[index] = arr[i];
            index++;
        }
    }
    temp[index++] = arr[p];
    int res = l+index-1;
    for(int i = l; i <=h; i++){
        if(arr[i] > arr[p]){
            temp[index] = arr[i];
            index++;
        }
    }
    for(int i = l; i <=h; i++){
        arr[i] = temp[i-l];
    }
    return res;
}

int main(){

    int arr[] = {5, 3, 12, 8, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << naive_partition(arr, 0, n-1, 0) << endl;
    print_array(arr, n);

    return 0;
}