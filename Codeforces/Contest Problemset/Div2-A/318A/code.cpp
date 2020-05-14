#include <iostream>

using namespace std;

int solve() {
    long long int n, k;
    long long int answer;

    cin >> n >> k;

    // 1 3 5 7 | 2 4 6 ( n = 7 )  -- 1 3 5 | 2 4 6 ( n = 6 )
    // midPoint = 4 -- midPoint = 3
    long long int midPoint = ( n + 1 ) / 2;

    if ( k <= midPoint ) {
        answer = -1 + ( 2 * k );
    } else if ( k > midPoint ) {
        answer = 0 + ( 2 * ( k - midPoint ));
    }

    cout << answer << endl;
    return 0;
};

int main() {
    solve();
    return 0;
};