#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    //Outer loop for n passes

    for(int i = 0; i < n; i++){
        bool swapped = false;

        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 4, 2, 6, 1, 3, 4};
    int n = sizeof(arr) /sizeof(arr[0]);
    cout << "Unsorted array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}