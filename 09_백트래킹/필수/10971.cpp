#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
vector<vector<int>> cost;
vector<bool> visited;
int minCost = numeric_limits<int>::max();

void solve(int start, int current, int count, int totalCost) {
    if (count == N) { // 모든 도시 방문 완료
        if (cost[current][start] != 0) { // 시작 도시로 돌아갈 수 있는 경우
            minCost = min(minCost, totalCost + cost[current][start]);
        }
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!visited[next] && cost[current][next] != 0) {
            visited[next] = true;
            solve(start, next, count + 1, totalCost + cost[current][next]);
            visited[next] = false; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cost.assign(N, vector<int>(N));
    visited.assign(N, false);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    for (int i = 0; i < N; i++) { // 각 도시에서 출발해보기
        visited[i] = true;
        solve(i, i, 1, 0);
        visited[i] = false;
    }

    cout << minCost << '\n';
    return 0;
}