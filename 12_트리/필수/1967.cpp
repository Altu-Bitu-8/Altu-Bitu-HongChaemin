#include <iostream>
#include <vector>
#include <utility> // pair
using namespace std;

// DFS로 가장 먼 노드를 찾기 위한 함수
void dfs(int current, int distance_so_far, vector<bool>& visited,
         const vector<vector<pair<int, int>>>& tree,
         int& max_distance, int& farthest_node) {

    visited[current] = true;

    if (distance_so_far > max_distance) {
        max_distance = distance_so_far;
        farthest_node = current;
    }
    // 인접한 노드 순회
    for (int i = 0; i < tree[current].size(); i++) {
        int next_node = tree[current][i].first;
        int weight = tree[current][i].second;

        if (!visited[next_node]) {
            dfs(next_node, distance_so_far + weight, visited, tree, max_distance, farthest_node);
        }
    }
}

// 트리의 지름을 구하는 함수
int findTreeDiameter(const vector<vector<pair<int, int>>>& tree, int node_count) {
    vector<bool> visited1(node_count + 1, false);
    int max_distance1 = 0;
    int farthest_node = 1;

    // 1차 DFS: 아무 노드에서 가장 먼 노드 찾기
    dfs(1, 0, visited1, tree, max_distance1, farthest_node);

    // 2차 DFS: 그 가장 먼 노드에서 또 DFS -> 지름 구하기
    vector<bool> visited2(node_count + 1, false);
    int max_distance2 = 0;
    int dummy = 0; // 더 이상 필요 없지만 매개변수로 줘야 해서 만듦

    dfs(farthest_node, 0, visited2, tree, max_distance2, dummy);

    return max_distance2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node_count;
    cin >> node_count;

    // 트리 초기화
    vector<vector<pair<int, int>>> tree(node_count + 1);

    for (int i = 0; i < node_count - 1; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        // 양방향 연결
        tree[from].push_back({to, weight});
        tree[to].push_back({from, weight});
    }

    // 지름 구해서 출력
    int diameter = findTreeDiameter(tree, node_count);
    cout << diameter;

    return 0;
}