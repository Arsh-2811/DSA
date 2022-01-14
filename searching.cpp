#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int d){
    int l = 0;
    int r = n-1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] == d){
            return mid;
        }
        else if(d > arr[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

int first_occurence(int arr[], int n, int d){
    int l = 0;
    int r = n-1;
    int res = -1;
    while(l <= r){
        int mid = (l+r)/2;

        if(d > arr[mid]){
            l = mid + 1;
        }
        else if(d < arr[mid]){
            r = mid - 1;
        }
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int trial(int arr[], int n, int d, int l, int r){
    int mid = (l + r)/2;
    while(l <= r){
        if(arr[mid] == d){
            return 1 + trial(arr, n, d, mid + 1, r) + trial(arr, n, d, l, mid - 1);
        }
        else if(arr[mid] > d){
            return trial(arr, n, d, l, mid-1);
        }
        else{
            return trial(arr, n, d, mid+1, r);
        }
    }
    return 0;
}

int count_occurences(int arr[], int n, int d){
    
    int res = trial(arr, n, d, 0, n-1);
    return res;
}

int count_ones(int arr[], int n){
    int l = 0;
    int r = n-1;
    int ans = -1;
    int d = 1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] == d){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(ans == -1){
        return 0;
    }
    else{
        return n - ans ;
    }
}

int square_root(int n){
    int l =1, r = n, ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        int mSq =mid *mid;
        if(mSq == n){
            return mid;
        }
        else if(mSq > n){
            r = mid - 1;
        }
        else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int bSearch(int arr[], int d, int l, int r){
    if(l > r){
        return -1;
    }
    int mid = (l + r)/2;
    if(arr[mid] == d){
        return mid;
    }
    else if(arr[mid] > d){
        return bSearch(arr, d, l, mid-1);
    }
    else{
        return bSearch(arr, d, mid+1, r);
    }
}

int search_in_infinite_sized_zorted_array(int arr[], int x){
    if(arr[0] == x){
        return 0;
    }
    int i = 1;
    while(arr[i] < x){
        i = i * 2;
    }
    if(arr[i] == x){
        return i;
    }
    return bSearch(arr, x, i/2 + 1, i-1);
}

int search_in_sorted_rotated_array(int arr[], int n, int d){
    int l = 0;
    int r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == d){
            return mid;
        }
        if(arr[l] < arr[mid]){
            if(arr[mid] > d && d >= arr[l]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            if(d > arr[mid] && d <= arr[r]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return -1;
}

int find_a_peak_element(int arr[], int n){
    int l = 0;
    int r = n-1;
    while(l <= r){
        int mid = (l + r) / 2;

        /* There is a different way to write this code which is discussed below
        if(mid == 0){
            if(arr[mid] > arr[mid + 1]){
                return arr[mid];
            }
        }
        else if(mid == n-1){
            if(arr[mid] > arr[mid - 1]){
                return arr[mid];
            }
        }
        else if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid+1]){
            return arr[mid];
        }
        */

        /* This one line of code is equal to the above 10s of lines of code*/
        if((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])){
            return arr[mid];
        }

        if(arr[mid + 1] > arr[mid]){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}

bool two_pointer(int arr[], int n, int s, int l, int r){
    while(l < r){
        int sum = arr[l] + arr[r];
        if(sum == s){
            return true;
        }
        else if(sum > s){
            r--;
        }
        else{
            l++;
        }
    }
    return false;
}

bool triplet_with_given_sum(int arr[], int n, int sum){
    for(int i = 0; i < n-2; i++){
        int s = sum - arr[i];
        bool ans = two_pointer(arr, n, s, i+1, n-1);
        if(ans == true){
            return ans;
        }
    }
    return false;
}

double det_median(int a1[], int a2[], int n1, int n2){
    int begin1 = 0, end1 = n1;
    while(begin1 <= end1){
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1+n2+1)/2 - i1;

        int min1 = (i1 == n1)?INT16_MAX:a1[i1];
        int max1 = (i1 == 0)?INT16_MIN:a1[i1 - 1];

        int min2 = (i2 == n2)?INT16_MAX:a2[i2];
        int max2 = (i2 == 0)?INT16_MIN:a2[i2 - 1];

        if(max1 <= min2 && max2 <=  min1){
            if(n1 + n2 % 2 == 0){
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            }
            else{
                return (double)max(max1, max2);
            }
        }
        else if(max1 > min2){
            end1 = i1 - 1;
        }
        else{
            begin1 = i1 + 1;
        }
    }
}

int main(){

    int arr1[] = {30, 40, 50, 60};
    int n1 = sizeof(arr1)/ sizeof(arr1[0]);

    int arr2[] = {5, 6, 7, 8, 9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << det_median(arr1, arr2, n1, n2) << endl;

    return 0;
}