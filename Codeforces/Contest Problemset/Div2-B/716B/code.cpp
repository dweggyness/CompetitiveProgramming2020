#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solve() {
    string s;
    cin >> s;

    if (s.size() < 26) {
        cout << -1 << endl;
        return 0;
    }

    for ( int i = 0; i <= s.size() - 26; i++ ) {
        map<char, int> letters;
        int questionMarks = 0;
        bool goodString = true;
        string newString = "";
        for ( int j = 0; j < 26; j++ ) {
            char curLetter = s[i + j];
            if ( letters[curLetter] >= 1 && curLetter != '?' ) {
                goodString = false;
                break;
            }
            letters[curLetter] += 1;
            newString += curLetter;
        }

        if (goodString) {
            // make the good substring
            for ( int j = i; j < i + 26; j++ ) {
                char curLetter = s[j];
                if ( curLetter == '?' ) {
                    string allLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

                    for ( int k = 0; k < 26; k++ ) {
                        char _i = allLetters[k];
                        if ( letters[_i] == 0 ) {
                            s[j] = _i;
                            letters[_i] += 1;
                            break;
                        }
                    }
                }
            }

            // loop through array 1 more time, and convert remaining '?' into A
            for ( int j = 0; j < s.size(); j++ ) {
                char curLetter = s[j];
                if ( curLetter == '?' ) {
                    s[j] = 'A';
                }
            }

            cout << s << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
};

int main() {
    solve();
    return 0;
};