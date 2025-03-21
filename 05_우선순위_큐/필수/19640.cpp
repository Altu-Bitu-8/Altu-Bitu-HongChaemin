#include <iostream>
#include <queue>

using namespace std;

// 사원 정보를 저장하는 구조체
struct Employee {
    int i; // 전체 순서
    int lines; // 줄 번호
    int d; // 근무 일수
    int h; // 화장실이 급한 정도
};

// 우선순위 큐에서 사용할 비교 함수
struct cmp {
    bool operator() (const Employee& a, const Employee& b) {
        if (a.d != b.d) {
            return a.d < b.d; // 근무 일수 내림차순
        }
        if (a.h != b.h) {
            return a.h < b.h; // 급한 정도 내림차순
        }
        return a.lines > b.lines; // 줄 번호 오름차순
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<queue<Employee>> lines(m); // m개의 줄을 각각 큐로 관리

    for (int i=0; i < n; i++) {
        int d, h;
        cin >> d >> h;
        lines[i%m].push({i, (i%m), d, h}); // 줄번호를 계산하고, 큐에 사원 정보를 각 줄에 나누어 배치
    }

    priority_queue<Employee, vector<Employee>, cmp> pq;

    for (int i=0; i < m; i++) { // 각 줄의 선두를 우선순위 큐에 추가
        if(!lines[i].empty()) { // 줄이 비어 있지 않은 경우에만
            pq.push(lines[i].front()); // 해당 줄의 선두를 우선 순위 큐에 추가
            lines[i].pop(); // 해당 줄에서 선두 제거
        }
    }

    int count = 0;  

    while (!pq.empty()) { 
        Employee current = pq.top(); // 우선 순위 큐에서 가장 높은 우선순위를 가진 사람
        pq.pop();                    // 해당 사람을 큐에서 제거

        if (current.i == k) { // 데카 차례라면 종료
            break;
        }

        count++;

        // 현재 사람이 빠진 줄에서 다음 사람이 앞으로 땡길 수 있게 추가해줌
        if (!lines[current.lines].empty()) { 
            pq.push(lines[current.lines].front()); // 해당 줄의 선두를 우선 순위 큐에 추가
            lines[current.lines].pop(); // 줄에서 선두 제거
        }
    }

    cout << count;

    return 0;
}