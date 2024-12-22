#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n){
    int fib1 = 0, fib2 = 1, fib;
    if(n == 0) return 0;
    if(n == 1) return 1;
    for(int i = 2; i <= n; i++){
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return fib;
}

int fibonacciSearch(vector<int>& arr, int n, int target){
    int fibM_2 = 0;
    int fibM_1 = 1;
    int fib = fibM_1 + fibM_2;

    while(fib < n){
        fibM_2 = fibM_1;
        fibM_1 = fib;
        fib = fibM_1 + fibM_2;
    }

    int offset = -1;

    while(fib > 1){
        int i = min(offset + fibM_2, n -1);

        if(arr[i] < target){
            fib = fibM_1;
            fibM_1 = fibM_2;
            fibM_2 = fib - fibM_1;
            offset = i;
        }

        else if(arr[i] > target){
            fib = fibM_2;
            fibM_1 = fibM_1 - fibM_2;
            fibM_2 = fib - fibM_1;
        }
        else {
            return i;
        }
    }

    if(fibM_1 && arr[offset + 1] == target){
        return offset + 1;
    }

    return -1;
}

int main(){
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 100};
    int n = arr.size();
    int target = 85;

    int result = fibonacciSearch(arr, n, target);
    if(result != -1){
        cout << "Element found at index " << result << endl;
    }

    else {
        cout << "Element not found" << endl;
    }

    return 0;
}