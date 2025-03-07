#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

int arr[MAX + 1]{0, };

// 소수를 구하는 함수
void findPrimes() {
    for (int i = 2; i <= MAX; i++) {
        arr[i] = i;
    }
    for (int i = 2; i * i <= MAX; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            arr[j] = 0;
        }
    }
}

// 홀수 소수만 추출하는 함수
vector<int> getOddPrimes() {
    vector<int> odd_prime;
    for (int i = 3; i <= MAX; i += 2) { // 홀수만 검사
        if (arr[i] != 0) {              // 소수인 경우만 추가
            odd_prime.push_back(arr[i]);
        }
    }
    return odd_prime;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

   findPrimes(); // 소수 구하기

    vector<int> odd_prime = getOddPrimes(); // 홀수 소수 추출

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < odd_prime.size(); i++) {
            if (arr[n - odd_prime[i]] == n - odd_prime[i]) { // 두 소수의 합으로 표현 가능 여부 확인
                cout << n << " = " << odd_prime[i] << " + " << n - odd_prime[i] << '\n';
                break;
            }
        }
    }

    return 0;
}
