#include <iostream>
#include <vector>
using namespace std;

// 그래프에서 두 노드 사이의 거리를 DFS로 찾는 함수
int findDistanceDFS(int current, int target, int distance_so_far, vector<bool>& visited, const vector<vector<pair<int, int>>>& tree) {
    if (current == target) {
        return distance_so_far;
    }

    visited[current] = true;

    for (const auto& neighbor : tree[current]) {
        int next_node = neighbor.first;
        int edge_weight = neighbor.second;

        if (!visited[next_node]) {
            int result = findDistanceDFS(next_node, target, distance_so_far + edge_weight, visited, tree);
            if (result != -1) {
                return result; // 찾으면 바로 리턴
            }
        }
    }

    return -1; // target 노드를 못 찾은 경우
}

// 모든 쿼리를 처리하는 함수
void processQueries(const vector<vector<pair<int, int>>>& tree, int query_count) {
    for (int i = 0; i < query_count; i++) {
        int from, to;
        cin >> from >> to;

        vector<bool> visited(tree.size(), false);

        int distance = findDistanceDFS(from, to, 0, visited, tree);
        cout << distance << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int node_count, query_count;
    cin >> node_count >> query_count;

    vector<vector<pair<int, int>>> tree(node_count + 1);

    for (int i = 0; i < node_count - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        // 양방향 간선
        tree[a].push_back({b, d});
        tree[b]. push_back({a, d});
    }

    processQueries(tree, query_count);

    return 0;
}