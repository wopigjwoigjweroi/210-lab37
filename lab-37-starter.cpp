// COMSC-210 | Jeremiah Ortiz | Lab-38
#include <iostream>
#include <string>
#include <fstream> 
#include <map>
#include <list> 
using namespace std;

int gen_hash_index(string word); 
void print(const map<int, list<string>>& hash_table); 

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
