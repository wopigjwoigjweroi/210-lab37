// COMSC-210 | Jeremiah Ortiz | Lab-37
#include <iostream>
#include <string>
#include <fstream> 
#include <map>
#include <list> 
using namespace std;

int gen_hash_index(string word) {

    int sum = 0;

    for (char c : word) {

        sum += (int) c;
    }  

    return sum % 1000; 
}

int main() {

    string filename = "lab-37-data.txt";

    fstream infile(filename); 

    // long grandTotal = 0; 

    map<int, list<string>> hash_table; 

    string line; 

    while (getline(infile, line)) {

        int hash = gen_hash_index(line); 
        hash_table[hash].push_back(line); 
    }

    // cout << "Grand Total: " << grandTotal; 

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

    infile.close(); 
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

/*
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string t1 = "First String: ";
    string t2 = "Second String: "; 

    cout << "ASCII Value of, " << t1 << sum_ascii(t1) << endl;
    cout << "ASCII Value of, " << t2 << sum_ascii(t2) << endl; 
    
*/
