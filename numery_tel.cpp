#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> lista_numerow;
    set<string> indywidualna_lista;
    string numer;

    for(int count = 0; count < n; count++) {
        getline(cin, numer);
        lista_numerow[numer]++;
    }

    for(auto numer : lista_numerow) {
       indywidualna_lista.insert(numer.first);
    }

    for(auto numer : indywidualna_lista) {
        cout << numer << endl;
    }

    return 0;
}