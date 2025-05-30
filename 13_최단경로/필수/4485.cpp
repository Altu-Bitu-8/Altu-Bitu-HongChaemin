#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int DX[4] = {0, 0, -1, 1};  // 상, 하, 좌, 우
const int DY[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
const int INF = 987654321;

int findMinCost(int n, const vector<vector<int>>& map) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[0][0] = map[0][0];

    priority_queue< pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>> > pq;

    pq.push(make_pair(map[0][0], make_pair(0, 0)));

    while (!pq.empty()) {
        pair<int, pair<int, int>> current = pq.top();
        pq.pop();

        int current_cost = current.first;
        int x = current.second.first;
        int y = current.second.second;

        if (dist[x][y] < current_cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i];
            int ny = y + DY[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int new_cost = current_cost + map[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push(make_pair(new_cost, make_pair(nx, ny)));
                }
            }
        }
    }

    return dist[n - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case = 1;
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<vector<int>> map(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        int answer = findMinCost(n, map);
        cout << "Problem " << test_case << ": " << answer << '\n';
        test_case++;
    }

    return 0;
}