#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<list<pair<int, string>>> table;

    int hash(int key){
        return key % size;
    }

public: 
    HashTable(int size){
        this->size = size;
        table.resize(size);
    }

    void insert(int key, string value){
        int index = hash(key);
        table[index].push_back(make_pair(key, value));
    }

    string search(int key){
        int index = hash(key);
        for(auto &pair : table[index]){
            if(pair.first == key){
                return pair.second;
            }
        }
        return "Not Found";
    }
    void remove(int key){
        int index = hash(key);
        list<pair<int, string>> &bucket = table[index];
        for(auto it = bucket.begin(); it != bucket.end(); ++it){
            if(it -> first == key){
                bucket.erase(it);
                return;
            }
        }
    }
}
int main(){
    HashTable ht(10);

    ht.insert(1, "A")
}