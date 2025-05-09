#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLength(int nephew, int n, const vector<int>& snacks) {
    int left = 1;
    int right = *max_element(snacks.begin(), snacks.end());
    int max_length = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += snacks[i] / mid;
        }
        if (cnt >= nephew) {
            max_length = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return max_length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int nephew, n;

    cin >> nephew >> n;

    vector<int> snacks(n);
    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
    }

    cout << maxLength(nephew, n, snacks);

    return 0;
}