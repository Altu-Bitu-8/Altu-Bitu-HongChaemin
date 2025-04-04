#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 가장 긴 증가하는 부분 수열의 길이를 계산하는 함수
int findLongest(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // dp 배열 초기화

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에서 최댓값 반환
    return *max_element(dp.begin(), dp.end()); // <algorithm>
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    // 함수 호출
    int result = findLongest(arr);
    cout << result;

    return 0;
}