#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// calculates shortest dist between 2 letters
int distBetweenTwoChars(char a, char b) {
    // ascii val of 'a' is 97 , 'z' is 122
    int asciiA = int(a), asciiB = int(b);

    int diff = abs(a - b);
    // b to z, b -> a -> z
    if ( diff > 13) {
        diff = 26 - diff;
    }

    return diff;
}

int solve() {
    long int maxCursorMoveLeft = 0, maxCursorMoveRight = 0, keyStrokes = 0;
    long int n, cursorPos;
    string s = "";

    cin >> n >> cursorPos;
    cin >> s;

    // cursor only needs to move in first half of string to make palindrome
    // if cursor is in 2nd half of string, flip string
    if ( cursorPos > ( n / 2 ) ) {
        reverse(s.begin(), s.end());
        cursorPos = n - cursorPos + 1;
    }

    // xx|xxyyyx  xx|xx yyyx   ||| xx|xxxyyyx xx|xx x yyyx
    for ( int i = 0; i < n / 2; i++ ) {
        char curCharL = s[i];
        char curCharR = s[n - 1 - i]; 

        if ( curCharL != curCharR ) {
            keyStrokes += distBetweenTwoChars(curCharL, curCharR);
            if ( i < cursorPos ) {
                maxCursorMoveLeft = max(maxCursorMoveLeft, ( (cursorPos - 1 ) - i ));
            } else maxCursorMoveRight = max(maxCursorMoveRight, ( i - ( cursorPos - 1) ));
        }
    }

    // keyStrokes has the total number of keystrokes to change letters
    // if cursor has to move both L and R, we move the shortest one first
    // otherwise, it only has to move in 1 direction

    if ( maxCursorMoveLeft == 0 ) keyStrokes += maxCursorMoveRight;
    else if ( maxCursorMoveRight == 0 ) keyStrokes += maxCursorMoveLeft;
    else if ( maxCursorMoveLeft >= maxCursorMoveRight ) keyStrokes += maxCursorMoveRight * 2 + maxCursorMoveLeft;
    else keyStrokes += maxCursorMoveRight + maxCursorMoveLeft * 2;

    cout << keyStrokes << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};