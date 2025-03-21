#include <iostream>
#include <queue>

using namespace std;

// 최소 힙의 크기를 n으로 유지하는 함수
void maintainHeap(priority_queue<int, vector<int>, greater<int>> &pq, int n) {
    while (pq.size() > n) {
        pq.pop(); // 힙의 크기가 n보다 커지면 가장 작은 값들을 제거
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            cin >> num;
            pq.push(num); 
            maintainHeap(pq, n); // 힙 크기 n으로 유지
        }
    }

    cout << pq.top(); 
    return 0;
}