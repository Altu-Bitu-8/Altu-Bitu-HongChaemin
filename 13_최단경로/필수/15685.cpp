#include <iostream>
#include <vector>
using namespace std;

const int BOARD_SIZE = 101;
const int DX[4] = {1, 0, -1, 0};  // 우, 상, 좌, 하
const int DY[4] = {0, -1, 0, 1};  // 우, 상, 좌, 하

void makeDragonCurve(vector< vector<int> >& board, int x, int y, int direction, int generation) {
    vector<int> dir_list;
    dir_list.push_back(direction);

    // 세대 수만큼 드래곤 커브 생성
    for (int g = 0; g < generation; g++) {
        int size = (int)dir_list.size();
        for (int i = size - 1; i >= 0; i--) {
            int next_dir = (dir_list[i] + 1) % 4;  // 90도 회전
            dir_list.push_back(next_dir);
        }
    }

    // 시작 점 표시
    board[y][x] = 1;

    // 방향 리스트를 따라 좌표 이동
    for (int i = 0; i < (int)dir_list.size(); i++) {
        x = x + DX[dir_list[i]];
        y = y + DY[dir_list[i]];

        // 보드에 경로 표시
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            board[y][x] = 1;
        }
    }
}

int countSquares(const vector< vector<int> >& board) {
    int count = 0;

    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            // 꼭짓점 4칸이 모두 1이면 정사각형 가능
            if (board[i][j] == 1 &&
                board[i + 1][j] == 1 &&
                board[i][j + 1] == 1 &&
                board[i + 1][j + 1] == 1) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        makeDragonCurve(board, x, y, d, g);
    }

    int answer = countSquares(board);
    cout << answer;

    return 0;
}