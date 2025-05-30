#include <iostream>
#include <vector>
using namespace std;

int floydWarshall(int n, const vector< vector<int> >& relation_list) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));

    // 입력된 키 비교 정보를 거리 배열에 반영
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (relation_list[i][j] == 1) {
                dist[i][j] = 1;  // i가 j보다 작음
            }
        }
    }

    // 플로이드 워셜 알고리즘 수행
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] && dist[k][j]) {
                    dist[i][j] = 1;
                }
            }
        }
    }

    int result = 0;

    // 정확한 키 순서를 알 수 있는 학생 수 카운트
    for (int i = 1; i <= n; i++) {
        int known_count = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] || dist[j][i]) {
                known_count++;
            }
        }
        if (known_count == n - 1) {
            result++;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 키 비교 관계 저장
    vector<vector<int>> relation_list(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        relation_list[a][b] = 1;  // a < b
    }

    int answer = floydWarshall(n, relation_list);
    cout << answer;

    return 0;
}