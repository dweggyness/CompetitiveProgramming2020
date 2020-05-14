#include <iostream>
#include <map>

using namespace std;

int solve() {
    int sumHeights[200000];
    sumHeights[0] = 0;
    long int n, k;

    cin >> n >> k;

    // generate prefix sum for the heights
    for ( int i = 1; i < n + 1; i++ ) {
        int cur;
        cin >> cur;

        sumHeights[i] = sumHeights[i - 1] + cur;
    }

    long long int minHeight = 1e9;
    long int minHeightIndex;

    // find min window where sum is greater than K
    for ( int i = 0; i < ( n - k + 1 ); i++ ) {
        long int windowHeight;
        windowHeight = sumHeights[i + k] - sumHeights[i];

        if ( windowHeight < minHeight ) {
            minHeightIndex = i + 1;
            minHeight = windowHeight;
        }
    };

    cout << minHeightIndex << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};