#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    unsigned int s = 0; // 공집합으로 초기값 집합 비트마스크 표현

    cin >> m;

    while (m--) {
        string input; // 명령어 문자열
        int x; // 명령어 숫자

        cin >> input;

        if (input == "add") {
            cin >> x;
            s |= (1 << x); // 1을 왼쪽으로 x칸 이동하여 x번째 비트 1로 설정, OR연산으로 x번째 비트 켬 (=1)
        }
        else if (input == "remove") {
            cin >> x;
            s &= ~(1 << x); // x번째 비트 제외 모든 비트 1로 만들고 AND연산으로 해당 비트 끔 (=0)
        }
        else if (input == "check") {
            cin >> x;
            if (s & (1<<x)) { 
                cout << "1\n";
            } 
            else {
                cout << "0\n";
            }
        }
        else if (input == "toggle") {
            cin >> x;
            s ^= (1 << x); // XOR연산으로 x번째 비트를 뒤집어서 반전시킴
        }
        else if (input == "all") {
            s = (1 << 21) - 1; // 21개의 비트 모두 1로 만듦
        }
        else if (input == "empty") {
            s = 0; // 모든 비트 0으로 설정
        }
    }
    return 0;
}
