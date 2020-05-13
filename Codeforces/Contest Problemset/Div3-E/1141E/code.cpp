#include <iostream>

using namespace std;

long long int solve() {
    long long int HP;
    long long int n;
    cin >> HP >> n;
    
    long long int mins = 0;
    long long int maxDmg = 0;
    long long int dmgPerRound = 0;
    long long int dmgArr[200010];

    // Round 1 - check if the monster dies this round
    // if not, and net dmg is positive, use the totla damage done each round to find the round
    // the monster is defeated.
    for ( long int i = 0; i < n; i++ ) {
        mins += 1;

        long long int dmg;
        cin >> dmg;

        if ( dmg != 0 ) dmgArr[i] = -dmg;
        else dmgArr[i] = 0;

        HP -= dmgArr[i];
        dmgPerRound += dmgArr[i];
        if ( dmgPerRound > maxDmg ) maxDmg = dmgPerRound;

        if ( HP <= 0 ) return mins; // killed in first round
    };

    // postivie dmg, possible to kill monster
    if ( dmgPerRound > 0 ) {
        // calculate the remaining HP in the last round
        // - find the number of rounds taken to bring the HP below maxDMG
        long long int HPInFinalRound = -( maxDmg - HP );
        long long int numberOfRounds = ( HPInFinalRound + dmgPerRound - 1 ) / dmgPerRound; 
        mins += numberOfRounds * n;

        HP -= ( dmgPerRound * numberOfRounds );

        for ( long long int i = 0; i < n; i++ ) {
            if ( HP <= 0 ) return mins;
            mins += 1;

            HP -= dmgArr[i];
            dmgPerRound += dmgArr[i];
        };
    } else { // negative dmg, impossible to defeat
        return -1;
    }

    return mins;
};

int main() {
    long long int answer = solve();
    cout << answer << endl;
    return 0;
};