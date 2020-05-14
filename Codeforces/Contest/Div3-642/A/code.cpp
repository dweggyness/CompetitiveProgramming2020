#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int solve() {
    int n;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int b, c;

        cin >> b >> c;

        if ( b == 1 ) {
            cout << 0 << endl;
        } else if ( b == 2 ) {
            cout << c << endl;
        } else {
            cout << c * 2 << endl;
        }
    }

    return 0;
};

int main() {
    solve();
    return 0;
};