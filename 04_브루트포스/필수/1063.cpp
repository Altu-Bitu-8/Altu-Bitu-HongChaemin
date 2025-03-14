#include <iostream>
#include <string>

using namespace std;

string move_list[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1 , -1};

// 체스판 범위 체크 함수
bool isInBounds(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() 
{
    string king, stone;
    
    int n;
    cin >> king >> stone >> n;

    int kx = '8' - king[1];
    int ky = king[0] - 'A';
    int sx = '8' - stone[1];
    int sy = stone[0] - 'A';

    while (n--) {
        string move;
        cin >> move;

        // 이동 방향 찾기
        int d;
        for (int i = 0; i < 8; i++) {
            if (move == move_list[i]) {
                d = i;
                break;
            }
        }
        
        int nkx = kx + dx[d];
        int nky = ky + dy[d];

        // 킹이 체스판 밖으로 나가는 경우 명령 무시
        if (!isInBounds(nkx, nky)) continue;

        // 킹이 움직인 위치가 돌과 겹치는 경우
        if (nkx == sx && nky == sy) { 
            int nsx= sx + dx[d];
            int nsy = sy + dy[d];

            // 돌이 체스판 밖으로 나가는 경우 명령 무시
            if (!isInBounds(nsx, nsy)) continue;

            sx = nsx;
            sy = nsy;
        }

        kx = nkx;
        ky = nky;
    }

    cout << char(ky + 'A') << 8 - kx << '\n';
    cout << char(sy + 'A') << 8 - sx << '\n';

    return 0;
}
