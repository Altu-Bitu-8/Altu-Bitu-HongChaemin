#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(int left, int right, int target, const vector<int>& arr) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, input;

    cin >> n; 
    vector<int> s_card(n);
    for (int i = 0; i < n; i++) {
        cin >> s_card[i];
    }

    sort(s_card.begin(), s_card.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;

        cout << (binarySearch(0, n - 1, input, s_card) ? 1 : 0) << ' ';
    }

    return 0;
}