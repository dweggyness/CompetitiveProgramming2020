#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// pro CPers use 'll' but it hurts the soul so i compromise
typedef long long int ll_int;
typedef pair <int,int> ii;
typedef vector <int> vi;

int solve() {
    ll_int n, s;
    cin >> n >> s;

    bool isPossible = ( s / 2 ) >= n;
    ll_int sumOfTwos = 0;
    if ( isPossible ) {
        cout << "YES" << endl;
        if ( n == 1 ) {
            cout << s << endl;
            cout << 1 << endl;
            return 0;
        }

        for ( int i = 0; i < n; i++ ) {
            if ( i == n - 1 ) {
                cout << s - sumOfTwos << endl;;
                cout << 1 << endl;
                return 0;
            } else {
                cout << 2 << " ";
                sumOfTwos += 2;
            }
        }

    } else {
        cout << "NO" << endl;
    }
};

int main() {
    solve();
    return 0;
};