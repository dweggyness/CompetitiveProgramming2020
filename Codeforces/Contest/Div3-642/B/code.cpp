#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int solve() {
    int n;
    cin >> n;
    int arrA[31], arrB[31];

    for ( int i = 0; i < n; i++ ) {
        int count, k;

        cin >> count >> k;

        for ( int j = 0; j < count; j++ ) {
            int _temp;
            cin >> _temp;
            arrA[j] = _temp;
        }

        for ( int j = 0; j < count; j++ ) {
            int _temp;
            cin >> _temp;
            arrB[j] = _temp;
        }

        sort(arrA, arrA + count);
        sort(arrB, arrB + count);

        int _tempCount = 0;
        for ( int j = 0; j < count; j++ ) {
            if ( k <= 0 ) break;
            if ( arrA[j] < arrB[count - 1 - _tempCount]) {
                arrA[j] = arrB[count - 1 - _tempCount];
                k -= 1;
                _tempCount++;
            } 
        }

        long int sum = 0;
        for ( int j = 0; j < count; j++ ) {
            sum += arrA[j];
        }

        cout << sum << endl;
    }

    return 0;
};

int main() {
    solve();
    return 0;
};