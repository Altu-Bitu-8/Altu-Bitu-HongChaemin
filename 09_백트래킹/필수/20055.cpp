#include <iostream>
#include <deque>
using namespace std;

int N, K;
deque<int> belt;
deque<bool> robots;

int step = 0;

void simulate() {
    while (true) {
        step++;

        // 벨트 + 로봇 회전
        belt.push_front(belt.back());
        belt.pop_back();

        robots.push_front(false);
        robots.pop_back();

        // 내리는 위치에 로봇이 있으면 내리기
        if (robots[N - 1]) robots[N - 1] = false;

        // 로봇 이동 (뒤에서부터)
        for (int i = N - 2; i >= 0; i--) {
            if (robots[i] && !robots[i + 1] && belt[i + 1] > 0) {
                robots[i] = false;
                robots[i + 1] = true;
                belt[i + 1]--;

                // 이동한 위치가 내리는 위치라면 즉시 내림
                if (i + 1 == N - 1) robots[i + 1] = false;
            }
        }

        // 로봇 올리기
        if (belt[0] > 0 && !robots[0]) {
            robots[0] = true;
            belt[0]--;
        }

        // 내구도 0인 칸 개수 확인
        int zeroCount = 0;
        for (int durability : belt) {
            if (durability == 0) zeroCount++;
        }

        if (zeroCount >= K) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    belt.resize(2 * N);
    robots.resize(2 * N, false);

    for (int i = 0; i < 2 * N; i++) {
        cin >> belt[i];
    }

    simulate();

    cout << step << '\n';
    return 0;
}