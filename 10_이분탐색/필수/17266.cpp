#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinHeight(int n, const vector<int>& lamp) {
    int h = 0;

    // 첫번째 가로등    
    h = max(h, lamp[0]);

    // 가로등  간격 길이
    for (int i = 1; i < lamp.size(); i++) {
        int dist = lamp[i] - lamp[i-1];
        int min = (dist + 1) / 2;
        h = max(h, min);
    }

    // 마지막 가로등 
    h = max(h, n - lamp.back());

    return h;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> lamp(m);

    for(int i = 0; i < m; i++) {
        cin >> lamp[i];
    }
    
    int height = findMinHeight(n, lamp);

    cout << height;

    return 0;
}