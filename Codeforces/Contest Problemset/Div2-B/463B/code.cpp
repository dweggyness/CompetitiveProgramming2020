#include <iostream>
#include <map>

using namespace std;

int solve() {
    long long int answer = 0;
    long int energy = 0, curPylonHeight = 0, nextPylonHeight;
    long int n;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> nextPylonHeight;

        energy += ( curPylonHeight - nextPylonHeight );

        // if energy is less than 0, means u lack that amount of energy to jump to next pylon
        if ( energy < 0 ) {
            long int requiredEnergy = -energy;
            answer += requiredEnergy;
            energy += requiredEnergy;
        }

        curPylonHeight = nextPylonHeight;
    }

    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};