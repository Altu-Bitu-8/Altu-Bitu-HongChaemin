#include <iostream>
#include <vector>

using namespace std;

int cleaned = 0;

// 북 동 남 서
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};

void simulateCleaning(int& r, int& c, int& d, vector<vector<int>>& room) {
    int n = room.size();
    int m = room[0].size();

    while (true) {
        // 1. 현재 칸이 아직 청소되지 않은 경우 청소
        if (room[r][c] == 0) {
            room[r][c] = 2; // 2는 청소한 칸
            cleaned++;
        }

        bool cleanedAdjacent = false;

        // 2. 주변 4칸 확인
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4; // 왼쪽으로 회전
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && room[nx][ny] == 0) {
                // 청소되지 않은 칸으로 이동
                r = nx;
                c = ny;
                cleanedAdjacent = true;
                break;
            }
        }

        if (!cleanedAdjacent) {
            // 3. 네 방향 모두 청소되어 있거나 벽인 경우
            int backDir = (d + 2) % 4;
            int bx = r + dx[backDir];
            int by = c + dy[backDir];

            if (bx >= 0 && bx < n && by >= 0 && by < m && room[bx][by] != 1) {
                r = bx;
                c = by;
            } 
            else {
                // 뒤쪽이 벽이면 작동 종료
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> room(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    simulateCleaning(r, c, d, room);

    cout << cleaned;
    return 0;
}