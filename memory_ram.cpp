#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string,string> myDatabase;
    myDatabase["username"]="Hari";
    myDatabase["role"]="Admin";
    myDatabase["level"]="1";

    cout << "__MINI_DATABASE OUTPUT___" << endl;
    cout << "USER: "<< myDatabase["username"] << endl;
    cout << "ROLE: "<< myDatabase["role"] << endl;
    cout << "Hierarchy: "<< myDatabase["level"] << endl;
    return 0;
} 