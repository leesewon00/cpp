#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>>graph[1001];
int dir[1001];

int INF = INT_MAX / 2 - 1;
int n, m, t, K;
int a, b, x, y;

void dij(int start) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0,start });
    dir[start] = 0;

    while (!pq.empty()) {

        int curVertex = pq.top().second;
        int curWeight = pq.top().first;
        pq.pop();

        if (dir[curVertex] != curWeight) {
            continue;
        }

        for (int i = 0; i < graph[curVertex].size(); i++) {

            int nxtVertex = graph[curVertex][i].second;
            int nxtWeight = graph[curVertex][i].first;

            int beforeWeight = dir[nxtVertex];
            int newWeight = curWeight + nxtWeight;

            if (beforeWeight > newWeight) {
                // update
                dir[nxtVertex] = newWeight;
                pq.push({ newWeight,nxtVertex });
            }
        }
    }
}

void clear() {
    for (int i = 1; i <= n; i++) {
        dir[i] = INF;
    }
}

void clearGraph() {
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--) {
        // cleanup 잘해줘야해.
        clearGraph();

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x >> y;

            graph[a].push_back({ x,b });
            graph[b].push_back({ y,a });
        }

        cin >> K;
        int ans = -1;
        for (int i = 0; i < K; i++) {
            int customer;
            cin >> customer;

            clear();
            dij(1);
            int back = dir[customer];
            clear();
            dij(customer);
            int come = dir[1];

            int cur = come + back;
            ans = max(cur, ans);
        }
        cout << ans << '\n';
    }
}
