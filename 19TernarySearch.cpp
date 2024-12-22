#include <iostream>
using namespace std;

int ternarySearch(int arr[], int low, int high, int target){
    while(high >= low){
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) /3;

        if(arr[mid1] == target){
            return mid1;
        }
        if(arr[mid2] == target){
            return mid2;
        }
        if(target < arr[mid1]){
            high = mid1 - 1;
        }
        else if(target > arr[mid2]){
            low = mid2 + 1;
        }

        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = ternarySearch(arr, 0, n-1, target);
    if(result != -1){
        cout << "Element found at index " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }

    return 0;
}