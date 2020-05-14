#include <iostream>
#include <map>

using namespace std;

int solve() {
    long long int answer = 0;
    map<long long int, long long int> pairsForValue;
    long int n, m;

    cin >> n >> m;

    long int curCount = 1;
    // create the number of pairings for values 1-5 in N
    while (true) {
        long int fiveDivisionM = m / 5;
        long int remainder = m % 5;

        long int numberOfPairs = fiveDivisionM;
        if ( ( 5 - curCount ) != 0 && remainder >= ( 5 - curCount ) ) numberOfPairs++;

        pairsForValue[curCount] += numberOfPairs;

        // n can be smaller than 5
        if (curCount >= n || curCount >= 5) break;
        curCount++;
    };

    long int fiveDivisionN = n / 5;
    long int remainder = n % 5;

    for ( int i = 1; i < 6; i++ ) {
        answer += fiveDivisionN * pairsForValue[i];
    };

    for ( int i = 1; i <= remainder; i++ ) {
        answer += pairsForValue[i];
    };

    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};