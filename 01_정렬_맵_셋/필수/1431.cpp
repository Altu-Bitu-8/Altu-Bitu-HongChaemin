#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfNumbers(const string& str) {
    int sum = 0;
    for (char c : str) {
        if (c >= '0' && c <= '9') { // 숫자인 경우만 처리
            sum += c -'0';
        }
    }
    return sum;
}

bool cmp(const string& a, const string& b) {
    // 1. 길이 다르면, 짧은 것 먼저
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    
    // 2. 길이 같으면, 숫자의 합 작은 것 먼저
    int sumA = sumOfNumbers(a);
    int sumB = sumOfNumbers(b);
    if (sumA != sumB) {
        return sumA < sumB;
    }
    
    // 3. 1, 2 조건으로 비교 불가 시, 사전순으로 비교
    return a < b;
}

int main()
{
    int n;
    cin >> n;

    vector<string> serialNumbers(n);
    for (int i = 0; i < n; i++) {
        cin >> serialNumbers[i];
    }
    
    sort(serialNumbers.begin(), serialNumbers.end(), cmp);
    
    for (const string& serial : serialNumbers) {
        cout << serial << '\n';
    }
    
    return 0;
}