#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 프림 알고리즘
// 정점 위주로 진행한다.
// 우선순위 큐를 이용하여 방문할 수 있는 정점중 가중치가 가장 낮은 정점으로 이동
// 음수도 처리 가능하다.
// ElogV

using namespace std;

int v, e, ans;
bool visited[10001];
vector<pair<int, int>> graph[1001];

void sol() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    // starting point를 virtualNode로 하자

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (visited[cur.second]) {
            continue;
        }

        visited[cur.second] = true;
        ans += cur.first;

        for (int i = 0; i < graph[cur.second].size(); i++) {
            pair<int, int> nxt = graph[cur.second][i];
            if (!visited[nxt.second]) {
                pq.push({nxt.first, nxt.second});
            }
        }
    }

}

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {

        cin >> n;

        //init
        ans = 0;
        for (int i = 0; i < 1001; ++i) {
            graph[i].clear();  // 각 노드에 연결된 벡터(인접 리스트) 초기화
        }
//        for (int i = 0; i < 1001; ++i) {
//            graph[i] = std::vector<std::pair<int, int>>();  // 새로운 빈 벡터로 재할당
//        }
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }

        vector<int> cost;
        for (int i = 1; i <= n; i++) {
            int curCost;
            cin >> curCost;
            cost.push_back(curCost);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int w;
                cin >> w;

                graph[i].push_back({w, j});
                graph[j].push_back({w, j});
            }
        }

        // 가상노드 설정하고 건설비용을 edge화 시킨다.
        int virtualNode = 0;
        for (int i = 0; i < cost.size(); i++) {
            graph[virtualNode].push_back({cost[i], i + 1});
            graph[i + 1].push_back({cost[i], virtualNode});
        }

        sol();

        cout << ans << '\n';
    }
}
