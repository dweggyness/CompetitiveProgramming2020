#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//  ['toVertex', 'color']
vector<vector<pair<int, int>>> adjList(110);
vector<int> uniqColors;

map<int, int> visited;
bool dfs(int start, int end, int color) {
    bool canReachEnd = false;;

    if ( start == end ) return true;

    for ( int i = 0; i < adjList[start].size(); i++ ) {
        int _color = adjList[start][i].second;
        int nextNode = adjList[start][i].first;

        if ( _color == color ) { // same color OK
            if ( visited[nextNode] != -1 ) {
                visited[nextNode] = -1;
                canReachEnd = dfs(nextNode, end, color);
                if ( canReachEnd ) return true;
            }
        }
    }

    return canReachEnd;
}

int solve() {
    int n, m, q, colors = 0;

    adjList[0].push_back(make_pair(1, 2));
    
    cin >> n >> m;

    for ( int i = 0; i < m; i++ ) {
        int a,b,c;
        cin >> a >> b >> c;

        if ( find(uniqColors.begin(), uniqColors.end(), c) == uniqColors.end() ) {
            colors += 1;
            uniqColors.push_back(c);
        }

        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, c));
    }

    cin >> q;

    for ( int i = 0; i < q; i++ ) {
        int validColors = 0;
        int start, end;

        cin >> start >> end;

        // try every color
        for ( int j = 0; j < uniqColors.size(); j++ ) {
            int curColor = uniqColors[j];

            visited.clear();
            if ( dfs(start, end, curColor) ) validColors++;
        }
        cout << validColors << endl;
    }
    return 0;
};

int main() {
    solve();
    return 0;
};