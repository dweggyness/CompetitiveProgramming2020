#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> friends;

int solve() {
    long long int n, moneyDiff, maxFriendshipPoints = 0;
    cin >> n >> moneyDiff;

    for ( int i = 0; i < n; i++ ) {
        long long int a,b;
        cin >> a >> b;
        friends.push_back(make_pair(a, b));
    }

    sort(friends.begin(), friends.end());

    long long int secondPointer = 0;
    long long int sum = 0;
    // Two pointer method
    // Keep track of the last item, and the moment the last item is no longer part of the current subsequence
    // we remove it from the current subsequence
    for ( long int i = 0; i < n; i++ ) {
        while ( friends[i].first - friends[secondPointer].first >= moneyDiff ) {
            sum -= friends[secondPointer].second;
            secondPointer++;
        }

        sum += friends[i].second;
        maxFriendshipPoints = max(maxFriendshipPoints, sum);
    }

    cout << maxFriendshipPoints << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};