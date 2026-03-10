#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class MiniDB {
private:
    unordered_map<string, string> store;

    string trim(const string& s) {
        size_t first = s.find_first_not_of(" \t\n");
        if (first == string::npos) return "";
        size_t last = s.find_last_not_of(" \t\n");
        return s.substr(first, (last - first + 1));
    }
    void load() {
        ifstream infile("data.txt");
        string line;
        if (!infile.is_open()) return;

        while (getline(infile, line)) {
            if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) continue;

            size_t commaPos = line.find(',');
            if (commaPos == string::npos) continue; 

            string k = trim(line.substr(0, commaPos));
            string v = trim(line.substr(commaPos + 1));

            if (!k.empty()) {
                if(!v.empty()){
                    store[k]=v;
                }
            }
        }
        infile.close();
    }

public:
    MiniDB(){
        load();
    }
    void set(string k, string v) {
        k = trim(k);
        v = trim(v);
        if (k.empty() || v.empty()) return;
        store[k] = v;
        ofstream infile("data.txt", ios::app);
        if (infile.is_open()) {
            infile << k << "," << v << endl;
            infile.close();
        }
    }

    string get(string k) {
        k = trim(k);
        if (store.count(k)) {
            return store[k];
        }
        return "key [ " + k + " ] not found!";
    }

    void listAll() {
        if (store.empty()) {
            cout << "[System] Database is currently empty." << endl;
            return;
        }
        cout << "--- Current Entries ---" << endl;
        for (auto const& [key, val] : store) {
            cout << "  " << key << " : " << val << endl;
        }
        cout << "-----------------------" << endl;
    }
};

int main() {
    MiniDB db;

    cout << "MiniDB Started." << endl;
    cout << "Commands: SET key,value | GET key | LIST | EXIT or Exit" << endl;

    string input;
    while (true) {
        cout << "\ndb > ";
        if (!getline(cin, input)) break;

        stringstream ss(input);
        string command;
        ss >> command; 

        if (command == "set") {
            string pair;
            getline(ss >> ws, pair); 

            size_t commaPos = pair.find(',');
            if (commaPos == string::npos) {
                cout << "[Error] Missing comma! Correct usage: SET name,Arjit" << endl;
            } else {
                string k = pair.substr(0, commaPos);
                string v = pair.substr(commaPos + 1);
                db.set(k, v);
                cout << "[Success] Entry stored." << endl;
            }
        } 
        else if (command == "get") {
            string k;
            getline(ss >> ws, k);
            if (k.empty()) {
                cout << "[Error] Usage: GET keyname" << endl;
            } else {
                cout << "Result: " << db.get(k) << endl;
            }
        } 
        else if (command == "list") {
            db.listAll();
        } 
        else if (command == "EXIT" || "Exit") {
            cout << "Goodbye!" << endl;
            break;
        } 
        else {
            cout << "[Error] Unknown command. Try set, get, or list." << endl;
        }
    }

    return 0;
}