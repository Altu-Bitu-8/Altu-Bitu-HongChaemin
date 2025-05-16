#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxSushi(int n, int d, int k, int c, const vector<int>& belt) {
    vector<int> visit(d + 1, 0); // 초밥 종류 1~d
    int cnt = 0;
    
    // 쿠폰 초밥은 미리 먹는다고 가정
    visit[c]++;
    cnt = 1;

    // 처음 윈도우 설정
    for (int i = 0; i < k; i++) {
        if (visit[belt[i]] == 0) {
            cnt++;
        }
        visit[belt[i]]++;
    }

    int maxKinds = cnt; 

    // 슬라이딩 윈도우 이동
    for (int i = 1; i < n; i++) {
        int remove = belt[i - 1]; // 왼쪽 끝 제거
        visit[remove]--;
        if (visit[remove] == 0) {
            cnt--;
        }

        int add = belt[(i + k - 1) % n]; // 오른쪽 끝 추가 (회전)
        if (visit[add] == 0) {
            cnt++;
        }
        visit[add]++;

        maxKinds = max(maxKinds, cnt);
    }

    return maxKinds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    int result = getMaxSushi(n, d, k, c, belt);
    cout << result;

    return 0;
}