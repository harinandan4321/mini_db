#include <iostream>
#include <unordered_map>
#include <string>

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
    MiniDB db;
    cout << "--- MINIDB starting ---- \n";
    db.set("Username","Ninja123");
    db.set("weapon","swordy");
    //armor is not set but will be set
    cout << "\n --- Fetching Data ---" << endl;
    cout << "WHo is the user? " << db.get("Username") << endl;
    cout << "What is the weapon?" << db.get("weapon") << endl;
    cout << "What is their armor?" << db.get("Armor") << endl;
    cout << "--- I told you armor is not decided yet ----" << endl;
    return 0;
} 