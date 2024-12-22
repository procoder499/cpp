#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 5, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    
    int result = binarySearch(arr, n, target);

    if(result != -1){
        cout << "Element found at index " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }

    return 0;
}