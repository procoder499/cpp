#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    bool check = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n-i-1]){
            cout << "not symmetryArray";
            check = false;
            break;
        }
    }
    if(check) cout << "symmetryArray";
    return 0;
}