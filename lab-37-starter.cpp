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
void modify(map<int, list<string>>& hash_table, int key); 

int main() {

    string filename = "lab-37-data.txt";

    fstream infile(filename); 

    map<int, list<string>> hash_table; 

    string line; 

    while (getline(infile, line)) {

        int hash = gen_hash_index(line); 
        hash_table[hash].push_back(line); 
    }

    int choice;

    do {

        cout << "\tMenu\n"; 
        cout << "1. Print 1st 100 entries\n"; 
        cout << "2. Search for Key\n"; 
        cout << "3. Add Key\n"; 
        cout << "4. Remove Key\n";
        cout << "5. Modify Key\n"; 
        cout << "6. Exit\n"; 
        cin >> choice; 

        switch(choice) {

            case 1:
                print(hash_table); 
                break; 

            case 2: {

                int a; 
                cout << "Enter Index to search: ";
                cin >> a; 
                ASCIIsearch(hash_table, a); 
                break; 
            }

            case 3: {

                string b; 
                cout << "Enter Key to add: ";
                cin >> b; 
                add(hash_table, b); 
                break; 
            }

            case 4: {

                int key; 
                cout << "Enter Key to remove: "; 
                cin >> key; 
                remove(hash_table, key); 
                break; 
            }

            case 5: {

                int c; 
                cout << "Enter Key to modify: ";
                cin >> c; 
                modify(hash_table, c);
                break;
            }

            case 6: {

                cout << "Exiting...";
                break; 

                default: 
                cout << "Invalid.\n";
            }   
        }
    } while (choice != 6); 

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

void modify(map<int, list<string>>& hash_table, int key) {

    auto it = hash_table.find(key); 
    if (it != hash_table.end()) {

        cout << "Current Key in Index: " << key << ": ";

        for (const auto& code : it->second) {

            cout << code << " "; 

        }
        cout << endl; 

        cout << "Modify Key:"; 
        list<string> modify_key; 
        string code; 

        while (cin >> code && code != "-1") {

            modify_key.push_back(code);
        }

        it->second = modify_key; 
        cout << "Index: " << key << " updated!\n"; 
        
    } else {
        cout << "Index: " << key << " not found..\n"; 
    }
}
