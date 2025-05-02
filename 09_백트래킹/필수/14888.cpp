#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<int> numbers;
int operators[4]; // +, -, *, /
int maxResult = INT_MIN;
int minResult = INT_MAX;

void solve(int index, int currentResult) {
    if (index == N) {
        if (currentResult > maxResult) maxResult = currentResult;
        if (currentResult < minResult) minResult = currentResult;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i]--;

            int nextResult = currentResult;
            if (i == 0) nextResult += numbers[index];
            else if (i == 1) nextResult -= numbers[index];
            else if (i == 2) nextResult *= numbers[index];
            else if (i == 3) {
                if (nextResult < 0) {
                    nextResult = -(-nextResult / numbers[index]);
                } else {
                    nextResult /= numbers[index];
                }
            }

            solve(index + 1, nextResult);
            operators[i]++; // 백트래킹
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    solve(1, numbers[0]);

    cout << maxResult << '\n';
    cout << minResult << '\n';

    return 0;
}