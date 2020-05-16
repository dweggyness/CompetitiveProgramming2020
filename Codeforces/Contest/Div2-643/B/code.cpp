#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// pro CPers use 'll' but it hurts the soul so i compromise
typedef long long int ll_int;
typedef pair <int,int> ii;
typedef vector <int> vi;

int solve() {
    ll_int t;
    cin >> t;

    for ( int i = 0; i < t; i++ ) {
        ll_int explorersCount;
        ll_int explorers[200010];
        ll_int groups = 0;
        cin >> explorersCount;

        for ( int j = 0; j < explorersCount; j++ ) {
            ll_int _temp;
            cin >> _temp;
            explorers[j] = _temp;
        }

        sort(explorers, explorers + explorersCount);

        ll_int pointer = 0;
        ll_int groupSize = 0;
        while ( pointer < explorersCount ) {
            ll_int curExplorerINEXP = explorers[pointer];
            groupSize++;

            // enough ppl to make group
            if ( curExplorerINEXP <= groupSize ) {
                groups++;
                groupSize = 0;
                pointer++;
            } else {
                pointer++;
            }
        }

        cout << groups << endl;
    }

    return 0;
};

int main() {
    solve();
    return 0;
};