#include <iostream>
#include <deque>

using namespace std;

// 카드 이동 함수
void moveCards(deque<int>& winner, deque<int>& loserGround, deque<int>& winnerGround) {
    while (!loserGround.empty()) {
        winner.push_front(loserGround.front());
        loserGround.pop_front();
    }
    while (!winnerGround.empty()) {
        winner.push_front(winnerGround.front());
        winnerGround.pop_front();
    }
}

// 종 치는 조건 확인 함수
int checkBell(deque<int>& ground_do, deque<int>& ground_su) {
    if (!ground_do.empty() && !ground_su.empty() && ground_do.back() + ground_su.back() == 5) 
        return 1; // 수연 승리
    if ((!ground_do.empty() && ground_do.back() == 5) || (!ground_su.empty() && ground_su.back() == 5)) 
        return 0; // 도도 승리
    return -1; // 아무도 종을 치지 않음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> do_deck(n), su_deck(n); // 도도와 수연의 카드 덱
    for (int i = 0; i < n; i++) 
        cin >> do_deck[i] >> su_deck[i];

    deque<int> ground_do, ground_su; // 도도와 수연의 그라운드 더미
    bool do_turn = true; // true: 도도 차례, false: 수연 차례
    int count = 0;       // 진행된 턴 수
    string winner = "";  // 최종 승자

    while (true) {
        count++;

        // 현재 플레이어가 카드 내려놓기
        if (do_turn) {
            ground_do.push_back(do_deck.back());
            do_deck.pop_back();
        } else {
            ground_su.push_back(su_deck.back());
            su_deck.pop_back();
        }

        // 덱이 비었는지 확인
        if (do_deck.empty()) {
            winner = "su";
            break;
        } else if (su_deck.empty()) {
            winner = "do";
            break;
        }

        // 종 치는 조건 확인 및 처리
        int bellResult = checkBell(ground_do, ground_su);
        if (bellResult == 1) 
            moveCards(su_deck, ground_do, ground_su); // 수연 승리
        else if (bellResult == 0) 
            moveCards(do_deck, ground_su, ground_do); // 도도 승리

        // m 턴이 끝난 경우 결과 계산
        if (count == m) {
            int result = do_deck.size() - su_deck.size();
            if (result < 0) 
                winner = "su";
            else if (result > 0) 
                winner = "do";
            else 
                winner = "dosu";
            break;
        }

        do_turn = !do_turn; // 차례 변경
    }

    cout << winner;

    return 0;
}