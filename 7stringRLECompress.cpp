#include <iostream>
#include <string>

using namespace std;

void RLECompress(string s){
    string result = "";
    for(int i = 0; i < s.size(); i++){
        int count = 1;
        while(i < s.size() - 1 && s[i] == s[i+1]){
            i++;
            count++;
        }
        result += to_string(count) + s[i];
    }
    cout << result << endl;
}

int main(){

    string str = "AABBBCCCCDDAA";
    string str_2 = "ABBACCZZA";
    string str_3 = "XYZ";
    RLECompress(str);
    RLECompress(str_2);
    RLECompress(str_3);


    return 0;
}