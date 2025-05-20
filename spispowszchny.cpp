#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    map<string, int> nazwisko;

    for(int count = 0; count <= n; count++) {
        string name;
        getline(cin, name);

        nazwisko[name]++;
    }

    int num = 1;
    map<string, int> max_nazw;

    for(auto name : nazwisko) {
        if(name.second > num) {
            num++;
            max_nazw.insert(name);
        }
    }

    cout << num << endl;
    for(auto name : max_nazw) {
        if(name.second == num) {
            cout << name.first << endl;
        }
        else if (name.second != num) {
            max_nazw.erase(name.first);
        }
    }
   return 0; 
}