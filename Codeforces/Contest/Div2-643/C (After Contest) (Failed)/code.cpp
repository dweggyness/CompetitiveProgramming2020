#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// fok it i'll use 'int' = 'long long int' im sorry to all the programming gods
typedef long long int ll_int;
typedef pair <int,int> ii;
typedef vector <int> vi;

// arr[3] = count of how many x & y can sum to 3
long int numberOfXAndYThatSumsTo[1000010];
ll_int countOfXAndYThatSumsToAtLeast[1000010];

int solve() {
    ll_int A,B,C,D;
    cin >> A >> B >> C >> D;

    // possible values for summation of any x and any y
    ll_int maxSumXAndY, minSumXAndY;
    maxSumXAndY = B + C; // xn + yn
    minSumXAndY = B + A; // y1 + x1(1)

    // if x = 1..3, and y = 3..1000
    // the max count of a single value e,g : 50 is equal to 3 ( 1 + 49, 2 + 48, 1 + 47 ), the length of x.
    // the count distribution will be : 1,2,3,3,3...3,2,1 ( for values 3..1003 )
    ll_int elementsOfX = B - A + 1;
    ll_int elementsOfY = C - B + 1;
    ll_int maxCount = min(B - A + 1, C - B + 1);

    ll_int maxCounter = 0;
    ll_int counter = 0;

    // generate count of each sum value
    // count increases by 1 until the middle, then decreases by 1 
    for ( int i = minSumXAndY; i <= maxSumXAndY; i++ ) {
        if ( i > ( minSumXAndY + maxSumXAndY ) / 2 ) {
            if ( maxCounter - 1 > 0 ) maxCounter--;
            counter = min(counter, maxCounter);
        } else if ( counter < maxCount ) {
            counter++;
            maxCounter++;
        } else maxCounter++;

        numberOfXAndYThatSumsTo[i] = counter;
    }

    // generate prefix sum
    for ( int i = maxSumXAndY; i >= minSumXAndY; i-- ) {
        countOfXAndYThatSumsToAtLeast[i] = countOfXAndYThatSumsToAtLeast[i + 1] + numberOfXAndYThatSumsTo[i];
    }

    // iterate throguh Z and add together the number of possible x and y combinations
    ll_int answer = 0;
    for ( int i = C; i <= D; i++ ) {
        answer += countOfXAndYThatSumsToAtLeast[i + 1];
    }

    if ( answer == 0 ) { cout << 1 << endl; return 0; }
    cout << answer << endl;

    return 0;
};

int main() {
    solve();
    return 0;
};