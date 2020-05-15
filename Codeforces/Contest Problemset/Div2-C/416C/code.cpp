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

vector<vector<int>> bookings; // [ bookingNo, booking size, booking price ]
vector<ii> requestNo_tableNo;
vector<ii> tables; // [tableNo, tableSize]

// sort by second element in descending order
bool sortFunc(const vector<int> &a,  const vector<int> &b) {
    return (a[2] > b[2]); 
} 

bool sortTables(const pair<int, int> &a,  const pair<int, int> &b) {
    return (a.second < b.second); 
} 

int solve() {
    ll_int n, t;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int a,b;
        cin >> a >> b;

        // request no, pax, price
        bookings.push_back({i + 1, a, b});
    }

    // sort by PRICE , descending. serve highest paying customers first
    sort(bookings.begin(), bookings.end(), sortFunc);

    cin >> t;

    for ( int i = 0; i < t; i++ ) {
        int tableSize;
        cin >> tableSize;
        tables.push_back(make_pair(i + 1, tableSize));
    }

    // sort table size ASCENDING, give smallest possible table
    sort(tables.begin(), tables.end(), sortTables);

    ll_int sum = 0;
    int totalAcceptedRequests = 0;
    for ( int i = 0; i < n; i++ ) {
        int curBookingSize = bookings[i][1];
        int curBookingPrice = bookings[i][2];

        for ( int j = 0; j < t; j++ ) {
            if ( curBookingSize <= tables[j].second ) {
                tables[j].second = 0; // once table taken, set size to 0
                sum += curBookingPrice;
                totalAcceptedRequests++;
                
                requestNo_tableNo.push_back(make_pair(bookings[i][0], tables[j].first));
                break;
            }
        }
    }
    
    cout << totalAcceptedRequests << " " << sum << endl;

    for ( int i = 0; i < totalAcceptedRequests; i++ ) {
        int requestNo = requestNo_tableNo[i].first;
        int tableNo = requestNo_tableNo[i].second;

        cout << requestNo << " " << tableNo << endl;
    }

    return 0;
};

int main() {
    solve();
    return 0;
};