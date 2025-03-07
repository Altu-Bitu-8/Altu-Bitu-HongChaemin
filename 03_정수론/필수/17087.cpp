#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int n, s;
    int result = -1;
    cin >> n >> s;
    while (n--) {
        int a;
        cin >> a;
        int d = (s > a) ? (s - a) : (a - s);

        if (result != -1) {
            result = gcd(result, d);
        }
        else
            result = d;
    }
    cout << result << '\n';

    return 0;
}