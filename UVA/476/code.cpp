#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int solve() {
    float rectangles[10][4];
    int n = 0;
    int curPoint = 0;
    char _i;
    float a,b,c,d;
    float x,y;

    while (scanf("%c", &_i)) {
        if ( _i == '*' ) break;
        scanf("%f %f %f %f", &a, &b, &c, &d);
        rectangles[n][0] = a;
        rectangles[n][1] = b;
        rectangles[n][2] = c;
        rectangles[n][3] = d;
        
        n++;
    };

    while (scanf("%f %f", &x, &y)) {
        bool atLeastOne = false;
        if ( fabs(x - 9999.9) < 1e-2 ) break;

        curPoint++;
        
        for ( int i = 0; i < n; i++ ) {
            if ( x > rectangles[i][0] && x < rectangles[i][2]) {
                if ( y < rectangles[i][1] && y > rectangles[i][3]) {
                    cout << "Point " << curPoint << " is contained in figure " << i + 1 << endl;
                    atLeastOne = true;
                }
            }
        }

        if ( !atLeastOne )  cout << "Point " << curPoint << " is not contained in any figure" << endl;
    };

    return 0;
};

int main() {
    solve();
    return 0;
};