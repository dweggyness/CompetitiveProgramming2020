#include <iostream>
#include <cmath>

using namespace std;

int solve() {
    double answer;
    double radius1 = 0, density1 = 0, density2 = 6000;
    double a,b,c;
    double constA, constB;

    // max radius1,density1 ,, min density2
    cin >> a;
    for ( int i = 0; i < a; i ++ ) {
        double cur;
        cin >> cur;
        if ( cur > radius1 ) radius1 = cur;
    }

    cin >> b;
    for ( int i = 0; i < b; i ++ ) {
        double cur;
        cin >> cur;
        if ( cur > density1 ) density1 = cur;
    }

    cin >> c;
    for ( int i = 0; i < c; i ++ ) {
        double cur;
        cin >> cur;
        if ( cur < density2 ) density2 = cur;
    }

    cin >> constA >> constB;

    // r2 = sqrt (( D1 * R1^2 * B ) / ( D2 * A + D1 * B))

    double eqTop = density1 * pow(radius1, 2) * constB;
    double eqBottom = density2 * constA + density1 * constB;

    answer = sqrt(eqTop / eqBottom);

    cout.precision(17);
    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};