#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    // bool check = true;
    // for(int i = 0; i < s.size(); i++){
    //     if(check) s[i] = toupper(s[i]);
    //     else{
    //       s[i] = tolower(s[i]);
    //     }
    //     check = false;
    //     if(s[i] == ' ') check = true;
    // }

    stringstream ss(s);
    string word;
    while(ss >> word){
        cout << word << endl;
    }

    cout << s;
}