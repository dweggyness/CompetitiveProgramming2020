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

ll_int upperBound = 1000000;
ll_int lowerBound = 0;
ll_int curValue = 500000;

int solve() {
    string s;

    ll_int prevValue = 1000001;
    ll_int count = 0;
    while (true) {
        cout << curValue << endl;
        
        count++;
        cin >> s;

        if ( upperBound - lowerBound == 1 ) {
            cout << "! " << curValue << endl;
            break;
        }

        if ( s == ">=" ) {
            lowerBound = curValue;
            ll_int newValue = curValue + ( upperBound - curValue + 1)  / 2;
            curValue = newValue;
        } else if ( s == "<" ) {
            upperBound = curValue;
            ll_int newValue = curValue - ( curValue - lowerBound + 1) / 2;
            curValue = newValue;
        }

        prevValue = curValue;
    }
    
    return 0;
};

int main() {
    solve();
    return 0;
};