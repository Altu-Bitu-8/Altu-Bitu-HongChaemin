#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int DX[4] = {0, 1, 0, -1};  // 동, 남, 서, 북 (x)
const int DY[4] = {1, 0, -1, 0};  // 동, 남, 서, 북 (y)

int changeDirection(int current_direction, char turn) {
    if (turn == 'L') {
        current_direction = (current_direction + 3) % 4;
    } 
    else if (turn == 'D') {
        current_direction = (current_direction + 1) % 4;
    }
    return current_direction;
}

int simulateGame(int board_size, const vector<pair<int,int>>& apples, const vector<pair<int,char>>& moves) {
    vector<vector<int>> board(board_size, vector<int>(board_size, 0));
    // 0: 빈 칸, 1: 사과, 2: 뱀 몸통

    // 사과 위치 표시
    for (int i = 0; i < (int)apples.size(); i++) {
        int x = apples[i].first - 1;
        int y = apples[i].second - 1;
        board[x][y] = 1;
    }

    deque<pair<int,int>> snake;  // 뱀 위치 저장 (머리 앞쪽)
    snake.push_back({0,0});
    board[0][0] = 2;

    int direction = 0; 
    int time = 0;
    int move_index = 0;

    while (true) {
        time++;
        // 머리 이동 위치 계산
        int head_x = snake.front().first;
        int head_y = snake.front().second;
        int next_x = head_x + DX[direction];
        int next_y = head_y + DY[direction];

        // 벽 충돌 검사
        if (next_x < 0 || next_x >= board_size || next_y < 0 || next_y >= board_size) {
            break;  // 게임 종료
        }
        // 자기 몸 충돌 검사
        if (board[next_x][next_y] == 2) {
            break;  // 게임 종료
        }

        // 이동한 칸에 사과가 있으면
        if (board[next_x][next_y] == 1) {
            board[next_x][next_y] = 2;  // 뱀 몸통으로 변환
            snake.push_front({next_x, next_y});
            // 꼬리 움직이지 않음 (몸길이 증가)
        } else {
            // 사과 없으면 몸길이 유지, 꼬리 위치 비워줌
            board[next_x][next_y] = 2;
            snake.push_front({next_x, next_y});
            pair<int,int> tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        // 방향 전환 검사
        if (move_index < (int)moves.size() && moves[move_index].first == time) {
            direction = changeDirection(direction, moves[move_index].second);
            move_index++;
        }
    }
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board_size, apple_count;
    cin >> board_size >> apple_count;

    vector<pair<int,int>> apples;
    for (int i = 0; i < apple_count; i++) {
        int x,y;
        cin >> x >> y;
        apples.push_back({x,y});
    }

    int move_count;
    cin >> move_count;

    vector<pair<int,char>> moves;
    for (int i = 0; i < move_count; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        moves.push_back({sec, dir});
    }

    int answer = simulateGame(board_size, apples, moves);
    cout << answer;

    return 0;
}