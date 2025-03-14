#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    unsigned int s = 0;

    cin >> m;

    while (m--) {
        string input;
        int x;

        cin >> input;

        if (input == "add") {
            cin >> x;
            s |= (1 << x);
        }
        else if (input == "remove") {
            cin >> x;
            s &= ~(1 << x);
        }
        else if (input == "check") {
            cin >> x;
            if (s & (1<<x)) {
                cout << "1\n";
            } 
            else {
                cout << "0\n";
            }
        }
        else if (input == "toggle") {
            cin >> x;
            s ^= (1 << x);
        }
        else if (input == "all") {
            s = (1 << 21) - 1;
        }
        else if (input == "empty") {
            s = 0;
        }
    }
    return 0;
}