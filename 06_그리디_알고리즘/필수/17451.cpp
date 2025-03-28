#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
       }

    long long min_v = v[n-1]; // 최소값 초기화

    for(int i = n-2; i >= 0; i--) { // 뒤에서부터
        if (min_v % v[i] != 0) { // 배수가 아니라면
            min_v = (min_v + v[i] - 1) / v[i] * v[i]; // 정수 나눗셈으로 올림 연산
        }
    }

    cout << min_v;

    return 0;
}