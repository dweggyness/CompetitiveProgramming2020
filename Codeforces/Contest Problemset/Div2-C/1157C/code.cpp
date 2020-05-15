#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solve() {
   long int n;
   long int arr[200010];
   cin >> n;

   for ( long int i = 0; i < n; i ++ ) {
       int _temp;
       cin >> _temp;
       arr[i] = _temp;
   }

   long int startIndex = 0, lastIndex = n - 1;
   long int lastNumber = -1;
   string s = "";

    // greedily take the smallest number L/R larger than current until we bump into 2 similar numbers
    // then try taking ALL left and ALL right and see which is larger
    // 1 3 5 3 2
   while (true) {
        if ( arr[startIndex] == arr[lastIndex] ) break; // same number
        if ( startIndex > lastIndex ) break; // end of loop

        if ( arr[startIndex] < arr[lastIndex] ) {
            if ( arr[startIndex] > lastNumber ) {
                lastNumber = arr[startIndex];
                startIndex++;
                s += 'L';
            } else if ( arr[lastIndex] > lastNumber ) {
                lastNumber = arr[lastIndex];
                lastIndex--;
                s += 'R';
            } else {
                cout << s.size() << "\n" << s << "\n";
                return 0;
            }
        }

         if ( arr[startIndex] > arr[lastIndex] ) {
            if ( arr[lastIndex] > lastNumber ) {
                lastNumber = arr[lastIndex];
                lastIndex--;
                s += 'R';
            } else if ( arr[startIndex] > lastNumber ) {
                lastNumber = arr[startIndex];
                startIndex++;
                s += 'L';
            } else {
                cout << s.size() << "\n" << s << "\n";
                return 0;
            }
        }
    }

    long int _lastNumberL = lastNumber, _lastNumberR = lastNumber;
    long int _tempStartIndex = startIndex, _tempLastIndex = lastIndex;
    string sLeft = s, sRight = s;
    // try all LEFT numbers
    while (true) {
        if ( _tempStartIndex > lastIndex ) break; // end of loop

        if ( arr[_tempStartIndex] > _lastNumberL ) {
            _lastNumberL = arr[_tempStartIndex];
            _tempStartIndex++;
            sLeft += 'L';
        } else {
            break;
        }
    };

    // try all RIGHT numbers
    while (true) {
        if ( startIndex > _tempLastIndex ) break; // end of loop

        if ( arr[_tempLastIndex] > _lastNumberR ) {
            _lastNumberR = arr[_tempLastIndex];
            _tempLastIndex--;
            sRight += 'R';
        } else {
            break;
        }
    };

    if ( sLeft.size() >= sRight.size() ) {
        cout << sLeft.size() << "\n" << sLeft << "\n";
    } else {
        cout << sRight.size() << "\n" << sRight << "\n";
    }

    return 0;
};

int main() {
    solve();
    return 0;
};