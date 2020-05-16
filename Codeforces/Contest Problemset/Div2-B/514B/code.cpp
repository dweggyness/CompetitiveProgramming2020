#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

// pro CPers use 'll' but it hurts the soul so i compromise
typedef long long int ll_int;
typedef pair <int,int> ii;
typedef vector <int> vi;

int solve() {
    set<double> angleWithStormTrooper;
    int n, x1, y1;
    cin >> n >> x1 >> y1;

    for ( int i = 0; i < n; i++ ) {
        int _x, _y;
        cin >> _x >> _y;

        // special case, stormtrooper on origin. any shot will hit.
        if ( abs(y1 - _y) == 0 && abs(x1 - _x) == 0 ) continue;
        // special case, Y/X origin line.
        if ( y1 - _y == 0 ) {
            angleWithStormTrooper.insert(66667.77); // impossible angel
        } else if ( x1 - _x == 0 ) {
            angleWithStormTrooper.insert(55555.55); // impossible angel
        } else {
            // calculate angle between point and origin ( lazer )
            double angle = 1.0 * (x1 - _x) / (y1 - _y);
            angleWithStormTrooper.insert(angle);
        }
    }

    cout << angleWithStormTrooper.size() << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};