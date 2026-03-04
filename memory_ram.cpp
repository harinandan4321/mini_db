#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
//string stream takes an input line and splits into parts based on whitespace
using namespace std;

class MiniDB {
    private:
    unordered_map<string,string> store;

    public:
    void set(string key,string value){
        store[key]=value;
        cout << "saved [" << key << "->" << value << "]" << endl;
    }
    string get(string key){
        if(store.count(key)) {
            return store[key];
        }
        else {return "Error: key not found!";}
    }
};

int main() {
    // adding a cli so it can be interactive but doesnt have a permanent meory yet
    MiniDB db;
    string input;

    cout << "Welcome to MiniDB! (Type 'Exit' to quit)" << endl;
    while(true) {
        cout << "db > ";
        getline(cin, input);
        if(input == "Exit") break;

        stringstream ss(input);
        string command, key, value;
        ss >> command >> key >> value;
        if(command == "set"){
            db.set(key,value);
        }
        else if(command == "get"){cout << db.get(key) << endl;}
        else {cout << "(Error) unknown command: "<< command << endl;}
    }
    return 0;
} 