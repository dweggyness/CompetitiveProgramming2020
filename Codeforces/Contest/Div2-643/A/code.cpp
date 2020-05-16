#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// pro CPers use 'll' but it hurts the soul so i compromise
typedef long long int ll_int;
typedef pair <int,int> ii;
typedef vector <int> vi;

int solve() {
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        long long int a, k;
        cin >> a >> k;

        for ( int j = 0; j < k - 1; j++ ) {
            ll_int _tempA = a;
            int largest = 0; 
            int smallest = 9; 
            while (_tempA) { 
                int r = _tempA % 10; 
        
                // Find the largest digit 
                largest = max(r, largest); 
                // Find the smallest digit 
                smallest = min(r, smallest); 
        
                _tempA = _tempA / 10; 

                if (largest == 9 && smallest == 0) break;
            } 

            ll_int nextValue = a + ( smallest * largest );
            if ( nextValue == a ) break;
            else a = nextValue;
        }

        cout << a << endl;
    }

    return 0;
};

int main() {
    solve();
    return 0;
};