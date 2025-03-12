#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // 바퀴 초기화 '?'로 채움
    vector<char> wheel(n, '?');
    int current = 0;

    for (int i = 0; i < k; i++) {
        int steps;
        char letter;
        cin >> steps >> letter;

        steps %= n;
        current -= steps;
        if (current < 0) current += n;

        // 현재 위치에 다른 문자가 이미 있는 경우
        if (wheel[current] != '?' && wheel[current] != letter) {
            cout << "!\n";
            return 0;
        }

        wheel[current] = letter;
    }

    // 다른 위치에 동일한 문자가 있는 경우
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!\n";
                return 0;
            }
        }
    }

    // 현재 화살표 위치부터 시계 방향으로 출력
    for (int i = 0; i < n; i++) {
        cout << wheel[current];
        current++;
        if (current == n) current = 0;
    }
    cout << '\n';

    return 0;
}
