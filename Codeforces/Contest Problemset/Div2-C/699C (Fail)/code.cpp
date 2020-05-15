#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int days[110]; 
int memo[110][4]; // [rested days][prev activity]

// prevActivity : rest - 0, gym - 1, contest - 2 , 3- null
int dp(int dayIndex, int prevActivity) {
    if (dayIndex >= n) return 0;
    if (memo[dayIndex][prevActivity] != -1) return memo[dayIndex][prevActivity];

    int restedDays = 0;
    int today = days[dayIndex];

    if (today == 1 ) {
        if (prevActivity != 1) {
            restedDays = dp(dayIndex + 1, 1);
            memo[dayIndex][1] = restedDays;
        } else {
            restedDays = max(restedDays + 1, dp(dayIndex + 1, 0) + 1);
            memo[dayIndex][0] = restedDays;
        }
    } else if (today == 2 ) {
        if (prevActivity != 2) {
            restedDays = dp(dayIndex + 1, 2);
            memo[dayIndex][2] = restedDays;
        } else {
            restedDays = max(restedDays + 1, dp(dayIndex + 1, 0) + 1);
            memo[dayIndex][0] = restedDays;
        }
    } else if ( today == 3 ) {
        if (prevActivity != 1 && prevActivity != 2) {
            restedDays = min(dp(dayIndex + 1, 1), dp(dayIndex + 1, 2));
        } else if (prevActivity != 1) {
            restedDays = dp(dayIndex + 1, 1);
            memo[dayIndex][1] = restedDays;
        } else if (prevActivity != 2) {
            restedDays = dp(dayIndex + 1, 2);
            memo[dayIndex][2] = restedDays;
        } else {
            restedDays = max(restedDays + 1, dp(dayIndex + 1, 0) + 1);
            memo[dayIndex][0] = restedDays;
        }
    } else {
        restedDays = max(restedDays + 1, dp(dayIndex + 1, 0) + 1);
        memo[dayIndex][0] = restedDays;
    }

    return restedDays;
}

int solve() {
    memset(memo, -1, sizeof memo);
    
    cin >> n;
    for ( int i = 0; i < n; i ++ ) {
        scanf("%d", &days[i]);
    }

    int answer = dp(0, 3);

    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};