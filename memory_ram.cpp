#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream> //string stream takes an input line and splits into parts based on whitespace
#include <fstream> //contains both input aqnd output files

using namespace std;

class MiniDB {
    private:
    unordered_map<string,string> store;
    void load () {
    ifstream infile("data.txt");
    if(!infile) return;
    string key,value;
    while(infile >> key >> value){store[key]=value;}
    infile.close();
    cout << "system databse is loaded. " << store.size() << "keys loaded." << endl;
}

    public:
    MiniDB () {
        load();
    }
    void set(string key,string value){
        store[key]=value;
        ofstream outfile("data.txt", ios::app);
        if(outfile.is_open()) {
            outfile << key << " " << value << endl;
            outfile.close();
            cout << "saved [" << key << "->" << value << "]" << endl;
        }
        else {
            cout << "Error Access denied!" << endl;
        }
        
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
        string command;
        ss >> command;
        if(command == "set"){
            string key,value;
            ss >> key >> value;
            db.set(key,value);
        }
        else if(command == "get"){
            string key;
            ss >> key;
            cout << db.get(key) << endl;
        }
        else {cout << "(Error) unknown command: "<< command << endl;}
    }
    return 0;
} 