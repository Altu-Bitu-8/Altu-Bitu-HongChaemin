#include <iostream>
#include <vector>
using namespace std;

// 시계방향 회전
void turnRight(vector<int>& wheel) {
    int last = wheel[wheel.size() - 1]; // 마지막 원소
    for (int i = wheel.size() - 1; i > 0; i--) {
        wheel[i] = wheel[i - 1]; // 모든 원소를 오른쪽으로 이동
    }
    wheel[0] = last; // 첫 번째 위치에 마지막 원소 배치
}

// 반시계방향 회전
void turnLeft(vector<int>& wheel) {
    int first = wheel[0]; // 첫 번째 원소
    for (int i = 0; i < wheel.size() - 1; i++) {
        wheel[i] = wheel[i + 1]; // 모든 원소를 왼쪽으로 이동
    }
    wheel[wheel.size() - 1] = first; // 마지막 위치에 첫 번째 원소 배치
}

int main() {
    int t; // 톱니바퀴 개수
    cin >> t;

    vector<vector<int>> wheels(t + 1, vector<int>(8)); // 톱니바퀴 상태
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            wheels[i][j] = c - '0'; // 값 직접 대입
        }
    }

    int k; // 회전 명령 수
    cin >> k;

    vector<pair<int, int>> commands(k); // (톱니 번호, 방향)
    for (int i = 0; i < k; i++) {
        int first, second;
        cin >> first >> second;
        commands[i] = {first, second}; // 값 직접 대입
    }

    for (int i = 0; i < k; i++) { 
        int center = commands[i].first;
        int direction = commands[i].second;

        vector<int> rotate(t + 1, 0); // 각 톱니의 회전 방향, 0은 회전 안 함
        rotate[center] = direction;

        // 왼쪽으로 영향
        for (int j = center; j > 1; j--) {
            if (wheels[j][6] != wheels[j - 1][2]) { // 맞닿은 극이 다르면
                rotate[j - 1] = -rotate[j];
            } else {
                break;
            }
        }

        // 오른쪽으로 영향
        for (int j = center; j < t; j++) {
            if (wheels[j][2] != wheels[j + 1][6]) { // 맞닿은 극이 다르면
                rotate[j + 1] = -rotate[j];
            } else {
                break;
            }
        }

        // 실제로 회전 수행
        for (int j = 1; j <= t; j++) {
            if (rotate[j] == 1) {
                turnRight(wheels[j]);
            }
            else if (rotate[j] == -1) {
                turnLeft(wheels[j]);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= t; i++) {
        if (wheels[i][0] == 1) {
            result++; // 첫 번째 위치가 S극(1)이면 카운트
        }
    }

    cout << result;
    return 0;
}