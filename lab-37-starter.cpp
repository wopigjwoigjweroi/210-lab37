// COMSC-210 | Jeremiah Ortiz | Lab-38
#include <iostream>
#include <string>
#include <fstream> 
#include <map>
#include <list> 
using namespace std;

int gen_hash_index(string word); 
void print(const map<int, list<string>>& hash_table); 
void ASCIIsearch(const map<int, list<string>>& hash_table, int key); 
void add(map<int, list<string>>& hash_table, const string& code);
void remove(map<int, list<string>>& hash_table, int key);

int main() {

    string filename = "lab-37-data.txt";

    fstream infile(filename); 

    map<int, list<string>> hash_table; 

    string line; 

    while (getline(infile, line)) {

        int hash = gen_hash_index(line); 
        hash_table[hash].push_back(line); 
    }

    infile.close(); 
    
    return 0;
}

int gen_hash_index(string word) {

    int sum = 0;

    for (char c : word) {

        sum += (int) c;
    }  

    return sum % 1000; 
}

void print(const map<int, list<string>>& hash_table) {

    int count = 0; 

    for (const auto& entry : hash_table) {

        if (count >= 100) {
            break; 
        }
        cout << "Index: " << entry.first << endl;
        cout << "Codes: \n"; 

        for (const auto& code : entry.second) {
            cout << code; 
        }
        cout << endl;
    }

}

void ASCIIsearch(const map<int, list<string>>& hash_table, int key) {

    auto it = hash_table.find(key);

    if (it != hash_table.end()) {

        cout << "Index: " << key << endl; 
        cout << "Codes: "; 

        for (const auto& code : it->second) {

            cout << code << endl; 
        }
        cout << endl; 
    } else {
        cout << "Hash Index " << key << " not found.\n";  
    }
}

void add(map<int, list<string>>& hash_table, const string& code) {
    
    int index = gen_hash_index(code); 
    
    hash_table[index].push_back(code); 

    cout << "Code " << code << " added under Index " << index << endl; 
}

void remove(map<int, list<string>>& hash_table, int key) {

    if (hash_table.erase(key)) {

        cout << "Index " << key << " removed.\n"; 
    } else {
        cout << "Index " << key << " not found.\n"; 
    }
}
