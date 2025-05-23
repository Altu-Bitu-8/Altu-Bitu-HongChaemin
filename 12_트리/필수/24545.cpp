#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> parent_node;
vector<int> depth_down;  // 아래 서브트리에서 최대 깊이 (edge 개수)
vector<int> depth_up;    // 부모 쪽으로 이어질 최대 깊이

// 1. depth_down[u] 계산: u 아래 서브트리에서 가장 먼 leaf까지의 거리
void computeDepthDown(int u, int p) {
    parent_node[u] = p;
    depth_down[u] = 0;

    int sz = (int)tree[u].size();

    for (int i = 0; i < sz; i++) {
        int v = tree[u][i];
        if (v == p) {
            continue;
        }
        computeDepthDown(v, u);

        // 자식 v를 통해 내려가는 최대 거리 +1
        if (depth_down[v] + 1 > depth_down[u]) {
            depth_down[u] = depth_down[v] + 1;
        }
    }
}

// 2. depth_up[u] 계산: 부모 쪽(나머지 트리)에서 가장 먼 leaf까지의 거리
void computeDepthUp(int u, int p) {
    // 자식들의 depth_down을 모아서 상위 두 개를 뽑기
    // u에서 내려갈 수 있는 두 번째로 긴 가지가 depth_up 계산에 필요
    int sz = (int)tree[u].size();

    // top1, top2 = 가장 큰 두 개
    int top1 = -1, top2 = -1;
    for (int i = 0; i < sz; i++) {
        int v = tree[u][i];
        if (v == p) {
            continue;
        }

        int d = depth_down[v] + 1;
        if (d > top1) {
            top2 = top1;
            top1 = d;
        } 
        else if (d > top2) {
            top2 = d;
        }
    }
    // 자식마다 depth_up 계산
    for (int i = 0; i < sz; i++) {
        int v = tree[u][i];
        if (v == p) {
            continue;
        }
        // v를 제외한 u의 가장 긴 가지 길이 선택
        int use = top1;
        if (depth_down[v] + 1 == top1) {
            use = top2;
        }
        // 부모 쪽으로 올라간 뒤, 그 가지에서 내려오는 거리
        // depth_up[u]는 이미 계산되어 있어야 함
        depth_up[v] = max(depth_up[u], use) + 1;
        computeDepthUp(v, u);
    }
}

// 3. 각 u별로 parent 쪽(depth_up)과 아이들 쪽(depth_down)들을 모아
//    세 가지 가장 큰 깊이를 뽑아 Y-트리 크기 계산
int solveYTree(int n) {
    // 1. 아래 방향 깊이
    computeDepthDown(1, 0);
    // 2. 위 방향 깊이: root의 depth_up = 0
    depth_up[1] = 0;
    computeDepthUp(1, 0);

    int answer = 0;
    // 각 노드 u 에 대해
    for (int u = 1; u <= n; u++) {
        // 이웃 v 중에서 깊이 목록 수집
        vector<int> cand;
        int sz = (int)tree[u].size();

        for (int i = 0; i < sz; i++) {
            int v = tree[u][i];

            if (v == parent_node[u]) {
                // 부모 쪽 깊이
                cand.push_back(depth_up[u]);
            } else {
                // 자식 쪽 깊이
                cand.push_back(depth_down[v] + 1);
            }
        }
        // 이웃이 3개 이상이어야 Y-트리 중심 후보
        if ((int)cand.size() < 3) {
            continue;
        }

        // 내림차순으로 상위 3개만 뽑기
        sort(cand.begin(), cand.end(), greater<int>());
        // Y-트리 크기 = 1(중심 u) + 세 가지 깊이의 합
        int y_size = 1 + cand[0] + cand[1] + cand[2];
        if (y_size > answer) {
            answer = y_size;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    tree.assign(n+1, vector<int>());
    parent_node.assign(n + 1, 0);
    depth_down.assign(n + 1, 0);
    depth_up.assign(n + 1, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int result = solveYTree(n);
    // Y-트리 최소 크기는 4이므로, 3 이하면 0 출력
    if (result < 4) {
        result = 0;
    }
    cout << result;
    return 0;
}
