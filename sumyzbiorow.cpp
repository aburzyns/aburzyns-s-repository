#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, m, x;
    set<int> set1;

    cin >> n;
    for(int count = 0; count < n; count++) {
        cin >> x;
        set1.insert(x);
    }  

    cin >> m;
    for(int count = 0; count < n; count++) {
        cin >> x;
        set1.insert(x);
    }

    for(auto num : set1) {
        cout << num << " ";
    }

    return 0;
}