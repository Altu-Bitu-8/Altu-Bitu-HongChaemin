#include <iostream>
#include <string>

using namespace std;

int countEat(string &arr, int n, int k) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 'P') { // 사람이 아닌 경우
            continue;   
        }

        for (int j = i - k; j <= i + k; j++) {
            if (j < 0 || j >= n) { // 인덱스 범위를 벗어나는 경우
                continue;
            }
            if (arr[j] == 'H') {
                count++;
                arr[j] = '0'; // 이미 사용된 H 표시
                break;
            }
        }
    }    
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    string arr; // 문자열로 선언
    cin >> arr; // 한 번에 입력받음

    int result = countEat(arr, n, k);
    
    cout << result;

    return 0;
}