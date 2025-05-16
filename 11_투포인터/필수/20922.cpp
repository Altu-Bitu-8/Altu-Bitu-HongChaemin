#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxSubarrayLength(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> count(100001, 0); 

    int start = 0;
    int end = 0;
    int maxLength = 0;

    while (end < n) {
        int currNum = nums[end];

        // 현재 수가 K번 이하로 등장했으면 포함
        if (count[currNum] < k) {
            count[currNum]++;
            end++;
        } 
        else {
            // 초과한 경우 start를 이동하며 수 줄이기
            count[nums[start]]--;
            start++;
        }

        // 현재 구간 길이 체크
        maxLength = max(maxLength, end - start);
    }

    return maxLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = getMaxSubarrayLength(nums, k);
    cout << result;

    return 0;
}