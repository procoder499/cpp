#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int low, int high, int target){
    while(low <= high){
        int mid = low + (high - low) /2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int target){
    if(arr[0] == target){
        return 0;
    }

    int i = 1;
    while(i < n && arr[i] <= target){
        i = i * 2;
    }

    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = exponentialSearch(arr, n, target);
    if(result != -1){
        cout << "Element found at index " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
}