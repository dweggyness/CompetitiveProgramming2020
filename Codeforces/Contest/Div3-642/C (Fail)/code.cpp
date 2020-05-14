#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;


int solve() {
    long int n;
    cin >> n;

    for ( long int i = 0; i < n; i++ ) {
        long long int current;
        cin >> current;

        long long int hotdog = ( current / 2 );
        current = hotdog * pow(current, 2);

        current -= 8 * ( hotdog * ( hotdog + 1 ) * ( 2 * hotdog + 1 ) ) / 6;

        cout << current << endl;
    };

    return 0;
};

int main() {
    solve();
    return 0;
};