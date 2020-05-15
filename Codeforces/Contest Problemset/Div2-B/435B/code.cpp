#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

// pro CPers use 'll' but it hurts the soul so i compromise
typedef long long int ll_int;
#define pair <int,int> ii;
#define vector <int> vi;

using namespace std;

int solve() {
    int k;
    string a;

    cin >> a >> k;

    int pointer = 0;
    while (k > 0) {
        if (pointer >= a.size()) break;
        int cur = a[pointer];
        
        int maxNumber = 0;
        long long int indexOfMax = 0;
        for ( int i = 1; i < k + 1; i++ ) {
            if ( (pointer + i) >= a.size()) break;
            int next = a[pointer + i];
            if ( next > maxNumber ) {
                indexOfMax = pointer + i;
                maxNumber = next;
            }
        }

        if ( maxNumber > cur ) {
            int numberOfSwaps = indexOfMax - pointer;
            for ( int i = 1; i < numberOfSwaps + 1; i++ ) {
                char maxNumberC = maxNumber;
                a[indexOfMax - i + 1] = a[indexOfMax - i];
                a[indexOfMax - i] = maxNumberC;
            }
            k -= ( indexOfMax - pointer );
        }

        pointer++;
    }

    cout << a << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};