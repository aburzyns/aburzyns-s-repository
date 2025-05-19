#include <iostream>
#include <map>
using namespace std;

int main() 
{
    map<char, int> litery;

    string txt;
    cin >> txt;

    for(auto character : txt) {
        litery[tolower(character)]++;
    }
    for(auto num : litery) {
        if(num.first == ' ') {
            map.eras
        }
    }
    for(auto element : litery) {
        cout << element.first << " " << element.second << endl;
    }

    return 0;
}