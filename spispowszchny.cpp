
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
    for(auto el : nazwisko) {
        if(el.second > num) {
            num = el.second;
        }
    }

    cout << endl << num << endl;
    for(auto name : nazwisko) {
        if(name.second == num) {
            cout << name.first << endl;
        }
    }
    
    
   return 0; 
}
