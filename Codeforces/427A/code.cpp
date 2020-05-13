#include <iostream>

using namespace std;

int solve() {
    int result = 0, n, curOfficers = 0;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int cur;
        cin >> cur;

        if ( cur == -1 ) {  // crime
            if ( curOfficers >= 1 ) {
                curOfficers--;
            } else {
                result++;
            }
        } else { // add officers
            curOfficers += cur;
        }
    }

    cout << result << "\n";
    return result;
};

int main() {
    solve();
    return 0;
};