#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int solve() {
    map<char, vector<vector<int>>> posOfKey;
    map<char, double> shortestDistance;
    int answer = 0;
    int n, m, Xdist;
    cin >> n >> m >> Xdist;

    // creates a mapping to an array of key positions
    for ( int y = 0; y < n; y++ ) {
        for ( int x = 0; x < m; x++ ) {
            char curChar;
            cin >> curChar;

            vector<int> curPos = {x, y};

            posOfKey[curChar].push_back(curPos);
        }
    }

    int sLen;
    cin >> sLen;

    for ( int i = 0; i < sLen; i++ ) {
        char curChar;
        cin >> curChar;

        // uppercase, need to press shift key
        if ( isupper(curChar) ) {
            char lowChar = tolower(curChar);
            if ( posOfKey[lowChar].size() && posOfKey['S'].size() ) {
                double minDistance = 1e4;
                // check if we have previously calculated the shortest distance
                if ( shortestDistance[curChar] ) {
                    minDistance = shortestDistance[curChar];
                    if ( minDistance > Xdist ) answer++;
                    continue;
                }

                // calculate distance from all lowercase letters to all shift keys, and find shortest distance
                for ( int j = 0; j < posOfKey[lowChar].size(); j++ ) {
                    for ( int k = 0; k < posOfKey['S'].size(); k++ ) {
                        // euclidean distance between the two keys
                        double distance = 
                            sqrt(pow(posOfKey[lowChar][j][0] - posOfKey['S'][k][0],2) + pow(posOfKey[lowChar][j][1] - posOfKey['S'][k][1],2));
                        if ( distance < minDistance ) minDistance = distance;
                        shortestDistance[curChar] = minDistance;
                    }
                }
                
                // greater than the max range, need to use other hand
                if ( minDistance > Xdist ) answer++;
            }
            else { // keyboard doesn't have the lowercase letter, or doesnt have Shift key
                answer = -1;
                break;
            }
        } else { // lowercase letter, does keyboard have this letter?
            if ( posOfKey[curChar].size() ) {}
            else { // keyboard doesn't have the lowercase letter
                answer = -1;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};