#include <iostream> 
#include <math.h>

using namespace std;

bool primeNumber(int n){
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int n; cin >> n;
    if(primeNumber(n)) cout << "prime number";
    else cout << "not prime number";

    return 0;
}
