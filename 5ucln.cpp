#include <iostream>
#include <math.h>
using namespace std;

int ucln(int a, int b){
    while(b!=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int n = 10;
    int a[10] = {2, 4, 6, 8, 5, 18, 20, 14, 10, 100};
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(ucln(a[i], a[j]) == 1) cout << a[i] << " " << a[j] << endl;
        }
    }
}