#include <iostream>

using namespace std;

int solve() {
    int result = 0, n, curOfficers = 0;
    int a,b,c,d;

    cin >> a >> b >> c >> d;

    if ( b == a ) result += 1;
    if ( c == b || c == a ) result += 1;
    if ( d == c || d == b || d == a ) result += 1;

    cout << result << "\n";
    return result;
};

int main() {
    solve();
    return 0;
};