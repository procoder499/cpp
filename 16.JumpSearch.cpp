#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int target){
    int step = sqrt(n);
    int prev = 0;

    while(arr[min(step, n) - 1] < target){
        prev = step;
        step += sqrt(n);
        if(prev >= n){
            return -1;
        }
    }

    for(int i = prev; i < min(step, n); i++){
        if(arr[i] == target){
            return i;
        }
    }

    return -1;
}

int main(){
    int arr[] = {1, 3, 4, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(arr) /sizeof(arr[0]);
    int target = 15;

    int result = jumpSearch(arr, n, target);

    if(result != -1){
        cout << "Element found at index " << result << endl;
    } else{
        cout << "Element not found" << endl;
    }

    return 0;
}