#include <iostream>

using namespace std;

int solve() {
    long long int iceCream;
    int distressedCount = 0, n;

    cin >> n >> iceCream;

    for ( int i = 0; i < n; i++ ) {
        char sign;
        long long int count;
        cin >> sign >> count;

        if ( sign == '+' ) {
            iceCream += count;
        } else if ( sign == '-' ) {
            if ( iceCream >= count )  iceCream -= count;
            else distressedCount += 1;
        };
    };

    cout << iceCream << " " << distressedCount << "\n";
    return 0;
};

int main() {
    solve();
    return 0;
};